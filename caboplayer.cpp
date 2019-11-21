#include "caboplayer.h"

CaboPlayer::CaboPlayer(QObject *parent) : QObject(parent)
{
    for(int i = 0; i < 4; i++) {
        CaboCard *card = new CaboCard();
        playerCards->insert(i, *card);
    }
}
