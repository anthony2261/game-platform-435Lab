#ifndef LADDER_H
#define LADDER_H

#include <QObject>
#include <QWidget>
#include <QGraphicsPixmapItem>

class ladder : public QObject, public QGraphicsPixmapItem
{
public:
    ladder();
    ladder(int b, int t);
    ladder(int bx, int by, int tx, int ty);
    int bottom_square;
    int top_square;
    int bx;
    int by;
    int tx;
    int ty;
};

#endif // LADDER_H
