#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->filePushButton, &QPushButton::clicked, this, &MainWindow::onFileClicked);
    connect(ui->uploadPushButton, &QPushButton::clicked, this, &MainWindow::onUploadClicked);
    connect(ui->metricsPushButton, &QPushButton::clicked, this, &MainWindow::onMetricsClicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::onExitClicked);
    connect(ui->regionComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),this, &MainWindow::filterTable);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->horizontalHeader()->setMinimumSectionSize(80);
    ui->columnComboBox->setDisabled(true);
    ui->regionComboBox->setDisabled(true);
    ui->maxYearSpinBox->setDisabled(true);
    ui->minYearSpinBox->setDisabled(true);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onFileClicked() {
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->pathLabel->clear();
    QString path = QFileDialog::getOpenFileName(this, "Выбрать файл", "D:\\labsFiles", "Файлы csv (*.csv);");
    if (!path.isEmpty()) {
        ui->pathLabel->setText(path);
    }
}

void MainWindow::onUploadClicked() {
    if (ui->pathLabel->text().isEmpty()) {
        QMessageBox::critical(this, "Ошибка", "Сначала выберите файл");
        return;
    }
    doOperation(Init, &context);
    strcpy(context.currentFilePath, ui->pathLabel->text().toStdString().c_str());
    doOperation(LoadData, &context);

    if (!context.fileLoaded) {
        QMessageBox::warning(this, "Ошибка", "Не удалось загрузить данные из файла");
        return;
    }
    ui->regionComboBox->clear();
    ui->columnComboBox->clear();
    ui->tableWidget->setRowCount(context.tableData.dataPointsCount);
    ui->tableWidget->setColumnCount(context.tableData.cols);

    if (context.tableData.dataPointsCount > 0) {
        int minYear = context.tableData.dataPoints[0].year;
        int maxYear = context.tableData.dataPoints[0].year;

        for (int i = 1; i < context.tableData.dataPointsCount; i++) {
            int year = context.tableData.dataPoints[i].year;
            if (year < minYear) minYear = year;
            if (year > maxYear) maxYear = year;
        }

        ui->minYearSpinBox->setRange(minYear, maxYear);
        ui->maxYearSpinBox->setRange(minYear, maxYear);
        ui->minYearSpinBox->setValue(minYear);
        ui->maxYearSpinBox->setValue(maxYear);
    }

    QStringList headers;
    for (int i = 0; i < context.tableData.cols; i++) {
        headers << QString(context.tableData.headers[i]);
    }
    int chekHeaders = 0;
    if(!headers.isEmpty())
        chekHeaders = 1;
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    for (int row = 0; row < context.tableData.dataPointsCount; row++) {
        for (int col = 0; col < context.tableData.cols; col++) {
            QTableWidgetItem* item = new QTableWidgetItem(
                QString(context.tableData.matrix[row][col]));
            ui->tableWidget->setItem(row, col, item);
        }
    }

    ui->regionComboBox->clear();
    ui->regionComboBox->addItem("Все регионы");

    QSet<QString> regions;
    for (int i = 0; i < context.tableData.dataPointsCount; i++) {
        regions.insert(QString(context.tableData.dataPoints[i].region));
    }

    for (const QString& region : regions) {
        ui->regionComboBox->addItem(region);
    }
    for (int i = 2; i < context.tableData.cols;i++) {
        ui->columnComboBox->addItem(context.tableData.headers[i],i);
    }

    for(int i = 0; i < ui->tableWidget->columnCount(); i++){
        ui->tableWidget->setColumnWidth(i, 90);
        if(i == REGION_COLUM) {
            ui->tableWidget->setColumnWidth(i, 260);
        }
    }

    filterTable(ui->regionComboBox->currentIndex());

    QString stats = QString(
                        "Статистика загрузки:\n"
                        "▸ Всего строк в файле: %1\n"
                        "▸ Корректных строк: %2\n"
                        "▸ Некорректных строк: %3")
                        .arg(context.tableData.rows + context.tableData.invalidRows + chekHeaders)
                        .arg(context.tableData.rows)
                        .arg(context.tableData.invalidRows);

    QMessageBox::information(this, "Результаты загрузки", stats);
    ui->columnComboBox->setDisabled(false);
    ui->regionComboBox->setDisabled(false);
    ui->maxYearSpinBox->setDisabled(false);
    ui->minYearSpinBox->setDisabled(false);

}

void MainWindow::filterTable(int index)
{
    if (!context.fileLoaded || index < 0) return;

    QString selectedRegion = ui->regionComboBox->itemText(index);
    bool showAllRegions = (selectedRegion == "Все регионы");
    int minYear = ui->minYearSpinBox->value();
    int maxYear = ui->maxYearSpinBox->value();

    for (int row = 0; row < context.tableData.dataPointsCount; ++row) {
        bool regionMatches = showAllRegions || (QString(context.tableData.dataPoints[row].region) == selectedRegion);
        bool yearInRange = (context.tableData.dataPoints[row].year >= minYear) && (context.tableData.dataPoints[row].year <= maxYear);

        ui->tableWidget->setRowHidden(row, !(regionMatches && yearInRange));
    }
}


void MainWindow::onMetricsClicked() {
    if (!context.fileLoaded) {
        QMessageBox::warning(this, "Ошибка", "Сначала загрузите файл");
        return;
    }
    else if(ui->regionComboBox->currentIndex() == 0) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберите регион");
        return;
    }

    context.filtredParams.selectedColumn = ui->columnComboBox->currentData().toInt();
    context.filtredParams.minYear = ui->minYearSpinBox->value();
    context.filtredParams.maxYear = ui->maxYearSpinBox->value();
    context.filtredParams.regionFilter = (ui->regionComboBox->currentText() == "Все регионы" ? NULL :
                                              ui->regionComboBox->currentText().toUtf8().constData());

    doOperation(FilterData, &context);

    if (!context.dataFiltered || context.metrics.count == 0) {
        QMessageBox::warning(this, "Ошибка", "Нет данных для отображения");
        return;
    }

    for (int i = 0; i < context.metrics.count; i++) {
        if (_isnan(context.metrics.points[i].value)) {
            QMessageBox::warning(this, "Ошибка", "Некорректные данные");
            return;
        }
    }

    if (!context.dataFiltered || context.metrics.count == 0 ||(ui->minYearSpinBox->text().toInt() >= ui->maxYearSpinBox->text().toInt())) {
        QMessageBox::warning(this, "Ошибка", "Нет данных для отображения");
        return;
    }

    std::sort(context.metrics.points, context.metrics.points + context.metrics.count,
              [](const DataPoint& a, const DataPoint& b) { return a.year < b.year; });
    QVector<QPointF> points;
    for (int i = 0; i < context.metrics.count; i++) {
        points.append(QPointF(context.metrics.points[i].year,context.metrics.points[i].value));
    }

    drawChart(points, ui->columnComboBox->currentText());

    QString metricsText = QString(
                              "Статистика для %1:\n"
                              "▸ Годы: %2 - %3\n"
                              "▸ Минимум: %4\n"
                              "▸ Максимум: %5\n"
                              "▸ Медиана: %6\n")
                              .arg(ui->regionComboBox->currentText())
                              .arg(ui->minYearSpinBox->value())
                              .arg(ui->maxYearSpinBox->value())
                              .arg(context.metrics.min, 0, 'f', 2)
                              .arg(context.metrics.max, 0, 'f', 2)
                              .arg(context.metrics.median, 0, 'f', 2);

    QMessageBox::information(this, "Результаты анализа", metricsText);
}

void MainWindow::setupChartScene(QGraphicsScene* scene) {
    const QColor bgColor("#2D3848");
    scene->setBackgroundBrush(bgColor);
}

QVector<QPointF> MainWindow::filterValidPoints(const QVector<QPointF>& points) {
    QVector<QPointF> validPoints;
    for (const QPointF& point : points) {
        if (!qIsNaN(point.x()) && !qIsNaN(point.y())) {
            validPoints.append(point);
        }
    }
    return validPoints;
}

void MainWindow::calculateDataRange(const QVector<QPointF>& points, double& minX, double& maxX, double& minY, double& maxY) {
    if (points.isEmpty()) return;

    minX = points[0].x();
    maxX = points[0].x();
    minY = points[0].y();
    maxY = points[0].y();

    for (const QPointF& point : points) {
        minX = qMin(minX, point.x());
        maxX = qMax(maxX, point.x());
        minY = qMin(minY, point.y());
        maxY = qMax(maxY, point.y());
    }

    double xRange = maxX - minX;
    double yRange = maxY - minY;
    minX -= xRange * 0.1;
    maxX += xRange * 0.1;
    minY -= yRange * 0.1;
    maxY += yRange * 0.1;
}

void MainWindow::drawAxes(QGraphicsScene* scene, int width, int height, int margin) {
    const QColor axisColor("#E0E0E0");
    QPen axisPen(axisColor, 2);
    scene->addLine(margin, height - margin, width - margin, height - margin, axisPen);
    scene->addLine(margin, margin, margin, height - margin, axisPen);
}

void MainWindow::drawGrid(QGraphicsScene* scene, int width, int height, int margin, double minY, double maxY, double yStep) {
    const QColor gridColor("#3A4759");
    const QColor textColor("#E0E0E0");
    const QColor axisColor("#E0E0E0");
    QFont font("Arial", 9);
    QPen gridPen(gridColor, 1, Qt::DotLine);

    for (double val = minY; val <= maxY; val += yStep) {
        double y = height - margin - (val - minY) / (maxY - minY) * (height - 2 * margin);
        scene->addLine(margin, y, width - margin, y, gridPen);

        QGraphicsTextItem* label = scene->addText(QString::number(val, 'f', 2));
        label->setDefaultTextColor(textColor);
        label->setFont(font);
        label->setPos(margin - label->boundingRect().width() - 5, y - 8);
        scene->addLine(margin - 5, y, margin + 5, y, QPen(axisColor, 2));
    }
}

void MainWindow::drawLineChart(QGraphicsScene* scene, const QVector<QPointF>& points,
                               int width, int height, int margin,
                               double minX, double maxX, double minY, double maxY) {
    const QColor lineColor("#4FC3F7");
    QPainterPath path;
    bool firstPoint = true;

    for (const QPointF& point : points) {
        double x = margin + (point.x() - minX) / (maxX - minX) * (width - 2 * margin);
        double y = height - margin - (point.y() - minY) / (maxY - minY) * (height - 2 * margin);

        if (firstPoint) {
            path.moveTo(x, y);
            firstPoint = false;
        } else {
            path.lineTo(x, y);
        }
    }

    scene->addPath(path, QPen(lineColor, 1.5));
}

void MainWindow::drawDataPoints(QGraphicsScene* scene, const QVector<QPointF>& points, int width, int height, int margin,
                                double minX, double maxX, double minY, double maxY) {
    const QColor normalPointColor("#4FC3F7");
    const QColor minPointColor("#FF5252");
    const QColor maxPointColor("#4CAF50");
    const QColor medianPointColor("#2406F4");
    const QColor textColor("#E0E0E0");

    double minVal = context.metrics.min;
    double maxVal = context.metrics.max;
    double medianVal = context.metrics.median;

    for (const QPointF& point : points) {
        double x = margin + (point.x() - minX) / (maxX - minX) * (width - 2 * margin);
        double y = height - margin - (point.y() - minY) / (maxY - minY) * (height - 2 * margin);

        if (qFuzzyCompare(point.y(), minVal)) {
            scene->addEllipse(x-5, y-5, 10, 10, QPen(minPointColor, 2), QBrush(minPointColor));
            QGraphicsTextItem* label = scene->addText(QString("min: %1").arg(point.y(), 0, 'f', 2));
            label->setDefaultTextColor(minPointColor);
            label->setPos(x - label->boundingRect().width()/2, y - 25);
        }
        else if (qFuzzyCompare(point.y(), maxVal)) {
            scene->addEllipse(x-5, y-5, 10, 10, QPen(maxPointColor, 2), QBrush(maxPointColor));
            QGraphicsTextItem* label = scene->addText(QString("max: %1").arg(point.y(), 0, 'f', 2));
            label->setDefaultTextColor(maxPointColor);
            label->setPos(x - label->boundingRect().width()/2, y - 25);
        }
        else if (qFuzzyCompare(point.y(), medianVal)) {
            scene->addEllipse(x-5, y-5, 10, 10, QPen(medianPointColor, 2), QBrush(medianPointColor));
            QGraphicsTextItem* label = scene->addText(QString("median: %1").arg(point.y(), 0, 'f', 2));
            label->setDefaultTextColor(medianPointColor);
            label->setPos(x - label->boundingRect().width()/2, y - 25);
        }
        else {
            scene->addEllipse(x-3, y-3, 6, 6, QPen(normalPointColor, 1), QBrush(normalPointColor));
        }
    }
}

void MainWindow::drawLabels(QGraphicsScene* scene, const QString& title, int width, int height, int margin, double minX, double maxX) {
    const QColor textColor("#E0E0E0");
    const QColor axisColor("#E0E0E0");
    QFont font("Arial", 9);

    for (int year = static_cast<int>(minX); year <= static_cast<int>(maxX); year++) {
        if (year >= minX && year <= maxX) {
            double x = margin + (year - minX) / (maxX - minX) * (width - 2 * margin);
            QGraphicsTextItem* label = scene->addText(QString::number(year));
            label->setDefaultTextColor(textColor);
            label->setFont(font);
            label->setPos(x - label->boundingRect().width()/2, height - margin + 10);
            scene->addLine(x, height - margin - 5, x, height - margin + 5, QPen(axisColor, 2));
        }
    }

    QGraphicsTextItem* titleItem = scene->addText(title);
    titleItem->setDefaultTextColor(textColor);
    titleItem->setFont(QFont("Arial", 11, QFont::Bold));
    titleItem->setPos(width/2 - titleItem->boundingRect().width()/2, 15);

    QGraphicsTextItem* xAxisLabel = scene->addText("Год");
    xAxisLabel->setDefaultTextColor(textColor);
    xAxisLabel->setFont(QFont("Arial", 10));
    xAxisLabel->setPos(width/2, height - margin + 30);

    QGraphicsTextItem* yAxisLabel = scene->addText("Значение");
    yAxisLabel->setDefaultTextColor(textColor);
    yAxisLabel->setFont(QFont("Arial", 10));
    yAxisLabel->setPos(15, height/5.5);
}


void MainWindow::drawChart(const QVector<QPointF>& points, const QString& title) {
    if (ui->graphicsView->scene()) {
        delete ui->graphicsView->scene();
    }

    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    setupChartScene(scene);

    QVector<QPointF> validPoints = filterValidPoints(points);
    if (validPoints.isEmpty()) {
        QGraphicsTextItem* text = scene->addText("Нет данных для отображения");
        text->setDefaultTextColor(Qt::red);
        text->setPos(20, 20);
        return;
    }

    int width = ui->graphicsView->width();
    int height = ui->graphicsView->height();
    int margin = 60;

    double minX, maxX, minY, maxY;
    calculateDataRange(validPoints, minX, maxX, minY, maxY);

    drawAxes(scene, width, height, margin);

    double yStep = (maxY - minY) / 5.0;
    drawGrid(scene, width, height, margin, minY, maxY, yStep);

    drawLineChart(scene, validPoints, width, height, margin, minX, maxX, minY, maxY);
    drawDataPoints(scene, validPoints, width, height, margin, minX, maxX, minY, maxY);
    drawLabels(scene, title, width, height, margin, minX, maxX);
}

void MainWindow::onExitClicked() {
    doOperation(Clear, &context);
    qApp->quit();
}
