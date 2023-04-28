#include "swatchmaker.h"
#include <QtWidgets>

SwatchMaker::SwatchMaker(QWidget *parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
}

void SwatchMaker::mousePressEvent(QMouseEvent *event) {
    QPoint point = event->pos();
    colorPicked = image.pixelColor(point);


}

void SwatchMaker::mouseMoveEvent(QMouseEvent *event){
    drawColorPreview(event->pos());
    makeSwatch(&swatch, event->pos());
}
void SwatchMaker::mouseReleaseEvent(QMouseEvent *event){

}
void SwatchMaker::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, swatch, dirtyRect);
    painter.drawImage(dirtyRect, image, dirtyRect);
//    painter.drawRect(QRect(image.width(), image.height(), image.width(), image.height()),QString(colorPicked.value()));
//    painter.drawStaticText(100, 100, QStaticText(QString("hello")));
//    update();

}

void SwatchMaker::resizeEvent(QResizeEvent *event)
//! [15] //! [16]
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, &swatch, QSize(newWidth, newHeight));
//        resizeImage(&swatch, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void SwatchMaker::drawColorPreview(const QPoint &point){
    QPainter painter(&image);

//    painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine, Qt::RoundCap,
//                        Qt::RoundJoin));
//    std::cout << point.x() << std::endl;
    image.fill(QColor(255, 255, 255, 0));
    painter.setBrush(image.pixelColor(point));
    painter.drawEllipse(point, image.width()/20, image.height()/20);
    update();

}
void SwatchMaker::resizeImage(QImage *image, QImage *swatch, const QSize &newSize)
//! [19] //! [20]
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_ARGB32);
    newImage.fill(QColor(255, 255, 255, 0));
    *image = newImage;
    *swatch = newImage;
    QPoint point = QPoint(image->width()/2, image->height()/2);
    makeSwatch(swatch, point);
}

void SwatchMaker::makeSwatch(QImage *image, const QPoint &point){
    float nPoints = 16;
    float position = 1./nPoints;
    QConicalGradient linearGrad(point, 360./nPoints);
    for(int i = 1; i < int(nPoints); i ++){
        float posT = (position * i) - (position * 0.5);
        linearGrad.setColorAt(posT, QColor::fromHslF(posT, 1.0, 0.5));
    }
    linearGrad.setColorAt(1.0, QColor::fromHslF((position * 1) - (position *0.5), 1.0, 0.5));
    QPainter painter(image);
    painter.setBrush(linearGrad);
    painter.drawRect(0, 0, image->width(), image->height());

//    *image = newImage;

}
