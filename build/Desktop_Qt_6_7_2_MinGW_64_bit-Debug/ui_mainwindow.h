/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *numberLabel;
    QLabel *label;
    QLabel *regionLabel;
    QSpacerItem *horizontalSpacer_6;
    QComboBox *columnComboBox;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *metricsPushButton;
    QComboBox *regionComboBox;
    QSpinBox *maxYearSpinBox;
    QSpinBox *minYearSpinBox;
    QGridLayout *gridLayout_2;
    QPushButton *exitButton;
    QPushButton *uploadPushButton;
    QLabel *pathLabel;
    QPushButton *filePushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(795, 627);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #f5f5f5;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #0f2027, stop:1 #2c5364);\n"
"}\n"
"\n"
"/* \320\241\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\321\213\320\271 \320\272\320\273\320\260\321\201\321\201 \320\264\320\273\321\217 \321\206\320\265\320\275\321\202\321\200\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \320\262\320\270\320\264\320\266\320\265\321\202\320\260 (\320\265\321\201\320\273\320\270 \320\275\321\203\320\266\320\275\320\276) */\n"
".central-widget {\n"
"    background: transparent;\n"
"    padding: 0;\n"
"    margin: 0;\n"
"    border: none;\n"
"}\n"
"\n"
"/* \320\232\320\276\321\200\321\200\320\265\320\272\321\206\320\270\321\217 \320\264\320\273\321\217 \321\202\320\260\320\261\320\273\320\270\321\206\321\213 */\n"
"QTableWidget {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: 2px solid #1e3c72;\n"
"    border-radius: 8px;\n"
"    gridline-color: #ffffff;\n"
""
                        "    color: #ffffff;\n"
"    font-size: 14px;\n"
"    margin: 0;  /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \320\262\320\275\320\265\321\210\320\275\320\270\320\265 \320\276\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"    padding: 0; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \320\262\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\270\320\265 \320\276\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"}\n"
"\n"
"/* \320\244\320\270\320\272\321\201 \320\264\320\273\321\217 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\276\320\262 \321\202\320\260\320\261\320\273\320\270\321\206\321\213 */\n"
"QHeaderView::section {\n"
"    padding: 8px 12px; /* \320\247\320\265\321\202\320\272\320\270\320\265 \320\276\321\202\321\201\321\202\321\203\320\277\321\213 \320\264\320\273\321\217 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\276\320\262 */\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 "
                        "#1e3c72, stop:1 #2a5298);\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* \320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\271 \321\204\320\270\320\272\321\201 \320\264\320\273\321\217 \320\262\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\321\217 */\n"
"QTableCornerButton::section {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: none;\n"
"}"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setMinimumSize(QSize(400, 0));

        verticalLayout->addWidget(graphicsView);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignLeading|Qt::AlignBottom);
        __qtablewidgetitem8->setFont(font);
        tableWidget->setItem(0, 0, __qtablewidgetitem8);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setMinimumSize(QSize(103, 0));
        tableWidget->setMaximumSize(QSize(1000, 1000));
        QFont font1;
        font1.setBold(true);
        tableWidget->setFont(font1);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: 2px solid #1e3c72;\n"
"    border-radius: 8px;\n"
"    gridline-color: #ffffff;\n"
"    color: #ffffff;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 6px;\n"
"    border-bottom: 1px solid #ffffff;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #4a90e2;\n"
"    color: #ffffff;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    color: #ffffff;\n"
"    padding: 10px;\n"
"    border: 1px solid #1e3c72;\n"
"    font-size: 10px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QHeaderView::section:checked {\n"
"    background-color: #4a90e2;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 1px solid #1e3c72;\n"
"    background: #2a5298;\n"
"    width: 12px;\n"
"    margin: 0px 0px 0px 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    ba"
                        "ckground: #4a90e2;\n"
"    min-height: 20px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"    border: 1px solid #1e3c72;\n"
"    background: #2a5298;\n"
"    height: 0px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"    border: 1px solid #1e3c72;\n"
"    background: #2a5298;\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    border: 1px solid #1e3c72;\n"
"    background: #2a5298;\n"
"    height: 12px;\n"
"    margin: 0px 0px 0px 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #4a90e2;\n"
"    min-width: 20px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"    border: 1px solid #1e3c72;\n"
"    background: #2a5298;\n"
"    width: 0px;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"   "
                        " border: 1px solid #1e3c72;\n"
"    background: #2a5298;\n"
"    width: 0px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        numberLabel = new QLabel(centralwidget);
        numberLabel->setObjectName("numberLabel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(numberLabel->sizePolicy().hasHeightForWidth());
        numberLabel->setSizePolicy(sizePolicy);
        numberLabel->setMinimumSize(QSize(0, 45));
        numberLabel->setMaximumSize(QSize(305, 45));
        QFont font2;
        font2.setBold(true);
        font2.setHintingPreference(QFont::PreferFullHinting);
        numberLabel->setFont(font2);
        numberLabel->setMouseTracking(false);
        numberLabel->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        numberLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: 2px solid #1e3c72;\n"
"    border-radius: 10px;\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    padding: 1px;\n"
"    selection-background-color: #4a90e2;\n"
"    selection-color: #ffffff;\n"
"}\n"
"\n"
"QLabel:focus {\n"
"    border: 2px solid #4a90e2;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #2a5298, stop:1 #1e3c72);\n"
"}\n"
"\n"
"QLabel:disabled {\n"
"    background-color: #cccccc;\n"
"    border: 2px solid #999999;\n"
"    color: #666666;\n"
"}"));
        numberLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(numberLabel, 1, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 45));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: 2px solid #1e3c72;\n"
"    border-radius: 10px;\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    padding: 1px;\n"
"    selection-background-color: #4a90e2;\n"
"    selection-color: #ffffff;\n"
"}\n"
"QLabel:focus {\n"
"    border: 2px solid #4a90e2;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #2a5298, stop:1 #1e3c72);\n"
"}\n"
"\n"
"QLabel:disabled {\n"
"    background-color: #cccccc;\n"
"    border: 2px solid #999999;\n"
"    color: #666666;\n"
"}"));

        gridLayout->addWidget(label, 4, 0, 1, 1);

        regionLabel = new QLabel(centralwidget);
        regionLabel->setObjectName("regionLabel");
        regionLabel->setMaximumSize(QSize(500, 16777215));
        regionLabel->setFont(font1);
        regionLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: 2px solid #1e3c72;\n"
"    border-radius: 10px;\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    padding: 1px;\n"
"    selection-background-color: #4a90e2;\n"
"    selection-color: #ffffff;\n"
"}\n"
"\n"
"QLabel:focus {\n"
"    border: 2px solid #4a90e2;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #2a5298, stop:1 #1e3c72);\n"
"}\n"
"\n"
"QLabel:disabled {\n"
"    background-color: #cccccc;\n"
"    border: 2px solid #999999;\n"
"    color: #666666;\n"
"}"));
        regionLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(regionLabel, 2, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 2, 3, 1, 1);

        columnComboBox = new QComboBox(centralwidget);
        columnComboBox->setObjectName("columnComboBox");
        columnComboBox->setMinimumSize(QSize(150, 45));
        columnComboBox->setMaximumSize(QSize(150, 45));
        columnComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: 2px solid #1e3c72;\n"
"    border-radius: 10px;\n"
"    color: #ffffff;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 5px 30px 5px 10px; /* \320\243\320\262\320\265\320\273\320\270\321\207\320\270\320\273\320\270 \320\277\321\200\320\260\320\262\321\213\320\271 \320\276\321\202\321\201\321\202\321\203\320\277 \320\264\320\273\321\217 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"    margin: 5px;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #2a5298, stop:1 #1e3c72);\n"
"    border: 2px solid #4a90e2;\n"
"}\n"
"\n"
"/* \320\241\321\202\320\270\320\273\321\214 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #2a52"
                        "98;\n"
"    border: 2px solid #1e3c72;\n"
"    selection-background-color: #4a90e2;\n"
"    color: #ffffff;\n"
"    font-size: 14px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* \320\241\321\202\321\200\320\265\320\273\320\272\320\260 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\276\320\261\320\273\320\260\321\201\321\202\320\270 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"    border-left: 1px solid #1e3c72;\n"
"    border-top-right-radius: 8px; /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \320\277\321\200\320\260\320\262\320\276\320\263\320\276 \321\203\320\263\320\273\320\260 */\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"\n"
"/* \320\230\320\272\320\276\320\275\320\272\320\260"
                        " \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"QComboBox::down-arrow {\n"
"    image: none; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \321\201\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\275\321\203\321\216 \320\270\320\272\320\276\320\275\320\272\321\203 */\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* \320\232\320\276\320\263\320\264\320\260 \321\201\320\277\320\270\321\201\320\276\320\272 \321\200\320\260\321\201\320\272\321\200\321\213\321\202 */\n"
"    image: url(:/icons/arrow_up_white.png); /* \320\241\321\202\321\200\320\265\320\273\320\272\320\260 \320\262\320\262\320\265\321\200\321\205 */\n"
"}\n"
"\n"
"/* \320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\321\217 */\n"
"QComboBox:disabled {\n"
"    background-color: #cccccc;\n"
"    border: 2px solid #999999;\n"
"    color: #666666;\n"
"}\n"
"\n"
"QComboBox:on { /* \320\232\320\276\320\263\320\264\320\260 \321\201\320\277\320\270\321\201\320\276\320\272 \321\200\320\260\321\201\320\272"
                        "\321\200\321\213\321\202 */\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #2a5298, stop:1 #1e3c72);\n"
"}"));

        gridLayout->addWidget(columnComboBox, 1, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 3, 1, 1);

        metricsPushButton = new QPushButton(centralwidget);
        metricsPushButton->setObjectName("metricsPushButton");
        metricsPushButton->setMinimumSize(QSize(0, 45));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Roboto Slab")});
        font3.setBold(true);
        metricsPushButton->setFont(font3);
        metricsPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: 2px solid #1e3c72;\n"
"    border-radius: 10px;\n"
"    color: #ffffff;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 1px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #2a5298, stop:1 #1e3c72);\n"
"    border: 2px solid #4a90e2;\n"
"    color: #ffffff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: 2px solid #4a90e2;\n"
"    color: #ffffff;\n"
"    padding: 1px 18px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #cccccc;\n"
"    border: 2px solid #999999;\n"
"    color: #666666;\n"
"}\n"
""));

        gridLayout->addWidget(metricsPushButton, 0, 0, 1, 4);

        regionComboBox = new QComboBox(centralwidget);
        regionComboBox->setObjectName("regionComboBox");
        regionComboBox->setMinimumSize(QSize(150, 45));
        regionComboBox->setMaximumSize(QSize(150, 45));
        regionComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: 2px solid #1e3c72;\n"
"    border-radius: 10px;\n"
"    color: #ffffff;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 5px 30px 5px 10px; /* \320\243\320\262\320\265\320\273\320\270\321\207\320\270\320\273\320\270 \320\277\321\200\320\260\320\262\321\213\320\271 \320\276\321\202\321\201\321\202\321\203\320\277 \320\264\320\273\321\217 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"    margin: 5px;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #2a5298, stop:1 #1e3c72);\n"
"    border: 2px solid #4a90e2;\n"
"}\n"
"\n"
"/* \320\241\321\202\320\270\320\273\321\214 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #2a52"
                        "98;\n"
"    border: 2px solid #1e3c72;\n"
"    selection-background-color: #4a90e2;\n"
"    color: #ffffff;\n"
"    font-size: 14px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* \320\241\321\202\321\200\320\265\320\273\320\272\320\260 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\276\320\261\320\273\320\260\321\201\321\202\320\270 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"    border-left: 1px solid #1e3c72;\n"
"    border-top-right-radius: 8px; /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \320\277\321\200\320\260\320\262\320\276\320\263\320\276 \321\203\320\263\320\273\320\260 */\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"\n"
"/* \320\230\320\272\320\276\320\275\320\272\320\260"
                        " \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"QComboBox::down-arrow {\n"
"    image: url(:/icons/arrow_down_white.png); /* \320\222\320\260\321\210\320\260 \320\261\320\265\320\273\320\260\321\217 \321\201\321\202\321\200\320\265\320\273\320\272\320\260 */\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* \320\232\320\276\320\263\320\264\320\260 \321\201\320\277\320\270\321\201\320\276\320\272 \321\200\320\260\321\201\320\272\321\200\321\213\321\202 */\n"
"    image: url(:/icons/arrow_up_white.png); /* \320\241\321\202\321\200\320\265\320\273\320\272\320\260 \320\262\320\262\320\265\321\200\321\205 */\n"
"}\n"
"\n"
"/* \320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\321\217 */\n"
"QComboBox:disabled {\n"
"    background-color: #cccccc;\n"
"    border: 2px solid #999999;\n"
"    color: #666666;\n"
"}\n"
"\n"
"QComboBox:on { /* \320\232\320\276\320\263\320\264\320\260 \321\201\320\277\320\270\321\201\320\276\320\272 \321\200\320\260\321\201"
                        "\320\272\321\200\321\213\321\202 */\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #2a5298, stop:1 #1e3c72);\n"
"}"));

        gridLayout->addWidget(regionComboBox, 2, 2, 1, 1);

        maxYearSpinBox = new QSpinBox(centralwidget);
        maxYearSpinBox->setObjectName("maxYearSpinBox");
        maxYearSpinBox->setMinimumSize(QSize(150, 45));
        maxYearSpinBox->setMaximumSize(QSize(150, 45));
        maxYearSpinBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: 2px solid #1e3c72;\n"
"    border-radius: 10px;\n"
"    color: #ffffff;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 1px 25px 1px 10px;  /* \320\243\320\262\320\265\320\273\320\270\321\207\320\265\320\275\320\276 \320\277\321\200\320\260\320\262\320\276\320\265 padding \320\264\320\273\321\217 \321\201\321\202\321\200\320\265\320\273\320\276\321\207\320\265\320\272 */\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QSpinBox:hover {\n"
"    border: 2px solid #4a90e2;\n"
"}\n"
""));

        gridLayout->addWidget(maxYearSpinBox, 4, 3, 1, 1);

        minYearSpinBox = new QSpinBox(centralwidget);
        minYearSpinBox->setObjectName("minYearSpinBox");
        minYearSpinBox->setMinimumSize(QSize(150, 45));
        minYearSpinBox->setMaximumSize(QSize(150, 45));
        minYearSpinBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: 2px solid #1e3c72;\n"
"    border-radius: 10px;\n"
"    color: #ffffff;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 1px 25px 1px 10px;  /* \320\243\320\262\320\265\320\273\320\270\321\207\320\265\320\275\320\276 \320\277\321\200\320\260\320\262\320\276\320\265 padding \320\264\320\273\321\217 \321\201\321\202\321\200\320\265\320\273\320\276\321\207\320\265\320\272 */\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QSpinBox:hover {\n"
"    border: 2px solid #4a90e2;\n"
"}\n"
""));

        gridLayout->addWidget(minYearSpinBox, 4, 1, 1, 2);


        horizontalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setMinimumSize(QSize(0, 45));
        exitButton->setFont(font3);
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: 2px solid #1e3c72;\n"
"    border-radius: 10px;\n"
"    color: #ffffff;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 1px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #2a5298, stop:1 #1e3c72);\n"
"    border: 2px solid #4a90e2;\n"
"    color: #ffffff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: 2px solid #4a90e2;\n"
"    color: #ffffff;\n"
"    padding: 1px 18px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #cccccc;\n"
"    border: 2px solid #999999;\n"
"    color: #666666;\n"
"}\n"
"\n"
""));

        gridLayout_2->addWidget(exitButton, 2, 0, 1, 2);

        uploadPushButton = new QPushButton(centralwidget);
        uploadPushButton->setObjectName("uploadPushButton");
        uploadPushButton->setMinimumSize(QSize(0, 45));
        uploadPushButton->setMaximumSize(QSize(16777215, 45));
        uploadPushButton->setFont(font3);
        uploadPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: 2px solid #1e3c72;\n"
"    border-radius: 10px;\n"
"    color: #ffffff;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 1px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #2a5298, stop:1 #1e3c72);\n"
"    border: 2px solid #4a90e2;\n"
"    color: #ffffff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: 2px solid #4a90e2;\n"
"    color: #ffffff;\n"
"    padding: 1px 18px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #cccccc;\n"
"    border: 2px solid #999999;\n"
"    color: #666666;\n"
"}\n"
""));
        uploadPushButton->setAutoDefault(false);

        gridLayout_2->addWidget(uploadPushButton, 1, 1, 1, 1);

        pathLabel = new QLabel(centralwidget);
        pathLabel->setObjectName("pathLabel");
        pathLabel->setMinimumSize(QSize(0, 45));
        pathLabel->setMaximumSize(QSize(16777215, 45));
        pathLabel->setFont(font1);
        pathLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: 2px solid #1e3c72;\n"
"    border-radius: 10px;\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    padding: 1px;\n"
"    selection-background-color: #4a90e2;\n"
"    selection-color: #ffffff;\n"
"}\n"
"\n"
"QLabel:focus {\n"
"    border: 2px solid #4a90e2;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #2a5298, stop:1 #1e3c72);\n"
"}\n"
"\n"
"QLabel:disabled {\n"
"    background-color: #cccccc;\n"
"    border: 2px solid #999999;\n"
"    color: #666666;\n"
"}"));
        pathLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pathLabel->setWordWrap(true);

        gridLayout_2->addWidget(pathLabel, 0, 0, 1, 2);

        filePushButton = new QPushButton(centralwidget);
        filePushButton->setObjectName("filePushButton");
        filePushButton->setMinimumSize(QSize(0, 45));
        filePushButton->setMaximumSize(QSize(16777215, 45));
        filePushButton->setFont(font3);
        filePushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: 2px solid #1e3c72;\n"
"    border-radius: 10px;\n"
"    color: #ffffff;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 1px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #2a5298, stop:1 #1e3c72);\n"
"    border: 2px solid #4a90e2;\n"
"    color: #ffffff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1e3c72, stop:1 #2a5298);\n"
"    border: 2px solid #4a90e2;\n"
"    color: #ffffff;\n"
"    padding: 1px 18px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #cccccc;\n"
"    border: 2px solid #999999;\n"
"    color: #666666;\n"
"}\n"
""));

        gridLayout_2->addWidget(filePushButton, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(whatsthis)
        MainWindow->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>bacground-color: red;</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

        numberLabel->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\272\320\276\320\273\320\276\320\275\320\272\320\270:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200 \320\277\320\276 \320\263\320\276\320\264\320\260\320\274:", nullptr));
        regionLabel->setText(QCoreApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200 \320\277\320\276 \321\200\320\265\320\263\320\270\320\276\320\275\321\203:", nullptr));
        metricsPushButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \320\274\320\265\321\202\321\200\320\270\320\272\320\270 \320\270 \320\276\321\202\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        uploadPushButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        pathLabel->setText(QString());
        filePushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\204\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
