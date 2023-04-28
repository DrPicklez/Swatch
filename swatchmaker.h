#ifndef SWATCHMAKER_H
#define SWATCHMAKER_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>
//#include <QtDebug>
#include <iostream>


class SwatchMaker : public QWidget
{
    Q_OBJECT

public:
    SwatchMaker(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
//    void qHoverEvent(QHoverEvent *event) override;

    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *image, QImage *swatch, const QSize &newSize);
    void makeSwatch(QImage *image, const QPoint &point);

    QColor colorPicked;
    QImage image;
    QImage swatch;
    QPoint lastPoint;
    bool pressed;

    void drawColorPreview(const QPoint &point);
};
#endif // SWATCHMAKER_H
