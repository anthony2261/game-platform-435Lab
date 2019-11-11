#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsPixmapItem>

class snake : public QObject, public QGraphicsPixmapItem
{
public:
//    snake();
//    snake(int h, int t);
//    int head_square;
//    int tail_square;
    snake(int bx = 200, int by = 200, int tx = 200, int ty = 200);
    int bx;
    int by;
    int tx;
    int ty;
};

#endif // SNAKE_H
