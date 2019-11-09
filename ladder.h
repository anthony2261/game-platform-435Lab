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
    int bottom_square;
    int top_square;
};

#endif // LADDER_H
