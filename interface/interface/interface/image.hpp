#ifndef IMAGE_HPP
#define IMAGE_HPP

#define FILL   true
#define ADJUST false

#include <QWidget>
#include <QImage>
#include <QPaintEvent>
#include <QPainter>
#include <QResizeEvent>

class Image : public QWidget
{
    Q_OBJECT

private:
    QImage image;
    bool policy;

public:
    explicit Image( QWidget *parent = NULL );
    void setImage( QString image, int policy );

protected:
    void paintEvent( QPaintEvent* );
    void resizeEvent( QResizeEvent* );
};

#endif // IMAGE_HPP

