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
    QVector<CaboCard *> *cards;

signals:

public slots:
    int Sum_of_Cards();
};

#endif // CABOPLAYER_H
