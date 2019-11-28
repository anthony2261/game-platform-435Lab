#include "cabo.h"
#include "gamewidget.h"

Cabo::Cabo(User *user, int gID)
{
    this->user = user;
    this->gID = gID;
    GridL = new QGridLayout;
    PushButton_Exit = new QPushButton("Exit");
    PushButton_Startgame = new QPushButton("Start Game");

    drawpile = new  QVector<CaboCard*>;
    discardpile = new  QVector<CaboCard*>;
    drawpile->append(new CaboCard(0));
    drawpile->append(new CaboCard(0));
    drawpile->append(new CaboCard(13));
    drawpile->append(new CaboCard(13));
    for (int i=1;i<13;i++) {
        drawpile->append(new CaboCard(i));
        drawpile->append(new CaboCard(i));
        drawpile->append(new CaboCard(i));
        drawpile->append(new CaboCard(i));
    }
    plr1 = new CaboPlayer();
    plr2 = new CaboPlayer();
    plr3 = new CaboPlayer();

    view = new QGraphicsView(this);
    view->setFixedWidth(1100);
    view->setFixedHeight(700);
    this->setSceneRect(0,0,1100,800);

    GridL->addWidget(PushButton_Startgame,0,0); // Hi anthony
    GridL->addWidget(PushButton_Exit,7,0);
    GridL->setContentsMargins(0,0,900,200);
    GridL->setVerticalSpacing(30);

    view->setLayout(GridL);
    view->setScene(this);
    view->show();

    QObject::connect(PushButton_Exit, SIGNAL(clicked(bool)), this, SLOT(exit()));
    QObject::connect(PushButton_Startgame, SIGNAL(clicked(bool)), this, SLOT(start_game()));
}


void Cabo::start_game(){

    std::random_shuffle(drawpile->begin(), drawpile->end());
    for (int i=0;i<4;i++) {
        plr1->cards->append(drawpile->front());
        drawpile->pop_front();
    }
    for (int i=0;i<4;i++) {
        plr2->cards->append(drawpile->front());
        drawpile->pop_front();
    }
    for (int i=0;i<4;i++) {
        plr3->cards->append(drawpile->front());
        drawpile->pop_front();
    }


}

void Cabo::playerturn(int player_number) {
    if (player_number == 1) {

    }
}

void Cabo::exit() {
    view->close();
    gamewidget *gwidget = new gamewidget(nullptr, this->user, gID);
    gwidget->show();
}
