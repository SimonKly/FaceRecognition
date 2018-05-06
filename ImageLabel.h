#ifndef IMAGELABEL_H
#define IMAGELABEL_H

#include <QLabel>
#include <QVector>
#include <QRect>

/*
 * @brief: 自定义Label空间以实现在图片上绘图的功能
 */
class ImageLabel : public QLabel
{
    Q_OBJECT
public:
    ImageLabel(QWidget *parent);

    int x() const;
    void setX(int x);

    int y() const;
    void setY(int y);

    int width() const;
    void setWidth(int width);

    int height() const;
    void setHeight(int height);

    QVector<QRect> getRectangles() const;
    void setRectangles(const QVector<QRect> &value);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;

    QVector<QRect> m_rectangles;
};

#endif // IMAGELABEL_H
