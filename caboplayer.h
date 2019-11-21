#ifndef CABOPLAYER_H
#define CABOPLAYER_H

#include <QObject>
#include "cabocard.h"
#include <QWidget>
class CaboPlayer : public QObject
{
    Q_OBJECT
public:
    explicit CaboPlayer(QObject *parent = nullptr);
    QVector<CaboCard> *playerCards;

signals:

public slots:
};

#endif // CABOPLAYER_H
