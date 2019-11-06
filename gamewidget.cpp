#include "gamewidget.h"
#include "loggedwidget.h"
#include "scoreswidget.h"
#include "snakesandladders.h"

gamewidget::gamewidget(QWidget *parent,  User *user, int gID) : QWidget(parent)
{
    VerticalL = new QVBoxLayout;
    GridL = new QGridLayout;
    this->user = user;
    this->gID = gID;
    if (this->gID == 1) {
        Label_Description =  new QLabel("Snakes and Ladders is a very popular ancient Indian board game for children.\n "
                                        "The classic game depends on sheer luck since it involves rolling a die and\n moving"
                                        " on the board accordingly.The winner is the first player to reach the\n final square. "
                                        "We will introduce some changes to tweak the no-decision nature\n of the game and add"
                                        " and educational purpose.");
    } else {
        Label_Description =  new QLabel("Cabo is a card game that combines memory, luck and tactics.\n The objective of the game is "
                                        "to collect the lowest cards in each \nhand to accumulate the fewest points"
                                        " by the end of the game.");
    }
    PushButton_Exit = new QPushButton("Exit");
    PushButton_PlayNow = new QPushButton("Play Now");
    PushButton_ViewScores = new QPushButton("View Scores");
    VerticalL->addWidget(Label_Description);
    GridL->addWidget(PushButton_PlayNow,0,0);
    GridL->addWidget(PushButton_ViewScores,0,1);
    GridL->addWidget(PushButton_Exit,0,2);
    VerticalL->addItem(GridL);
    setLayout(VerticalL);
    QObject::connect(PushButton_PlayNow, SIGNAL(clicked(bool)), this, SLOT(play()));
    QObject::connect(PushButton_Exit, SIGNAL(clicked(bool)), this, SLOT(exit()));
    QObject::connect(PushButton_ViewScores, SIGNAL(clicked(bool)), this, SLOT(view_scores()));
}


void gamewidget::play() {
    if (this->gID == 1){
        this->close();
        snakesandladders *g1scene = new snakesandladders(this->user, gID);
    }
}

void gamewidget::exit() {
    this->close();
    loggedwidget *lwidget = new loggedwidget(nullptr, this->user);
    lwidget->show();
}

void gamewidget::view_scores() {
    this->close();
    scoreswidget *swidget = new scoreswidget(nullptr, this->user, this->gID);
    swidget->show();
}


