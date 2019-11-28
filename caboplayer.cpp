#include "caboplayer.h"

CaboPlayer::CaboPlayer(QObject *parent) : QObject(parent)
{
    cards = new QVector<CaboCard>;
}

int CaboPlayer::Sum_of_Cards(){
    int sum=0;
    for (auto i=cards->begin();i<cards->end();i++){
        sum += i->number;
    }
    return sum;
}
