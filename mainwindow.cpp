#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(640, 480);
}

MainWindow::~MainWindow()
{
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter{this};

    QPointF center{100, 100};
    painter.setPen( QPen(Qt::red, 3) );
    painter.drawPoint(center);

    // -------------

    painter.setPen( QPen(Qt::black, 2) );

    double pointCount = 16;
    double radius = 50;

    for( int i{0}; i < pointCount ; ++i) {

        qreal angle = qDegreesToRadians(180.0*i/pointCount);

        qreal x = center.x() + radius * sin(angle);
        qreal y = center.y() + radius * cos(angle);

        painter.drawPoint(QPointF(x, y));
    }
}
