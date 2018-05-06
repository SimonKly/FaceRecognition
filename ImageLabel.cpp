#include "ImageLabel.h"
#include <QPainter>

ImageLabel::ImageLabel(QWidget *parent)
    : QLabel(parent), m_x(0), m_y(0), m_width(0), m_height(0)
{

}

void ImageLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 2));

//    painter.drawRect(this->m_x, this->m_y, this->m_width, this->m_height);
    painter.drawRects(this->m_rectangles);
}

QVector<QRect> ImageLabel::getRectangles() const
{
    return m_rectangles;
}

void ImageLabel::setRectangles(const QVector<QRect> &value)
{
    m_rectangles = value;
}

int ImageLabel::height() const
{
    return m_height;
}

void ImageLabel::setHeight(int height)
{
    m_height = height;
}

int ImageLabel::width() const
{
    return m_width;
}

void ImageLabel::setWidth(int width)
{
    m_width = width;
}

int ImageLabel::y() const
{
    return m_y;
}

void ImageLabel::setY(int y)
{
    m_y = y;
}

int ImageLabel::x() const
{
    return m_x;
}

void ImageLabel::setX(int x)
{
    m_x = x;
}
