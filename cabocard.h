#ifndef CABOCARD_H
#define CABOCARD_H

#include <QWidget>
#include <QtWidgets>

class CaboCard
{
public:
    //CaboCard();
    CaboCard(int number = 0);
    int number;
    QGraphicsPixmapItem *pixmap;
    QString choice;
};

#endif // CABOCARD_H
