#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "appcontext.h"
#include "entrypoint.h"
#define MIN_YEAR 1990
#define MAX_YEAR 2017

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onFileClicked();
    void onUploadClicked();
    void onMetricsClicked();
    void onExitClicked();
    void filterTable(int regionIndex);

private:
    Ui::MainWindow *ui;
    AppContext context;

    QVector<QPointF> filterValidPoints(const QVector<QPointF>& points);
    void drawChart(const QVector<QPointF>& points, const QString& title);
    void setupChartScene(QGraphicsScene* scene);
    void calculateDataRange(const QVector<QPointF>& points, double& minX, double& maxX, double& minY, double& maxY);
    void drawAxes(QGraphicsScene* scene, int width, int height, int margin);
    void drawGrid(QGraphicsScene* scene, int width, int height, int margin,double minY, double maxY, double yStep);
    void drawLineChart(QGraphicsScene* scene, const QVector<QPointF>& points,int width, int height, int margin, double minX, double maxX, double minY, double maxY);
    void drawDataPoints(QGraphicsScene* scene, const QVector<QPointF>& points,int width, int height, int margin,double minX, double maxX, double minY, double maxY);
    void drawLabels(QGraphicsScene* scene, const QString& title,int width, int height, int margin, double minX, double maxX);
};

#endif // MAINWINDOW_H
