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
    CaboCard(int number = 0, bool faceup = false);
    int number;
    QString choice;
    bool faceup;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};

#endif // CABOCARD_H
