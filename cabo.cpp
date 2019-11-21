#include "cabo.h"

Cabo::Cabo(User *user, int gID)
{
    this->user = user;
    this->gID = gID;
    plr1 = new CaboPlayer();
    plr2 = new CaboPlayer();
    plr3 = new CaboPlayer();
}


void Cabo::exit() {
//    view->close();
//    gamewidget *gwidget = new gamewidget(nullptr, this->user, gID);
//    gwidget->show();
}
