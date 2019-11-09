#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsPixmapItem>

class snake : public QObject, public QGraphicsPixmapItem
{
public:
    snake();
    snake(int h, int t);
    int head_square;
    int tail_square;
};

#endif // SNAKE_H
