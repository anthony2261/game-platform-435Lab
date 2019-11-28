#ifndef CABOCARD_H
#define CABOCARD_H

#include <QWidget>
#include <QObject>
#include <QtWidgets>
#include <QGraphicsPixmapItem>

class CaboCard : public QObject, public QGraphicsPixmapItem
{
public:
    //CaboCard();
    CaboCard(int number = 0);
    int number;
    QString choice;
};

#endif // CABOCARD_H
