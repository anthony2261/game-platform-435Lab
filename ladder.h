#ifndef LADDER_H
#define LADDER_H

#include <QObject>
#include <QWidget>
#include <QGraphicsPixmapItem>

class ladder : public QObject, public QGraphicsPixmapItem
{
public:
//    ladder();
//    ladder(int b, int t);
    ladder(int bx = 200, int by = 200, int tx = 200, int ty = 200);
//    int bottom_square;
//    int top_square;
    int bx;
    int by;
    int tx;
    int ty;
};

#endif // LADDER_H
