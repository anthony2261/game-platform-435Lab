#include "game1widget.h"
#include "loggedwidget.h"

Game1Widget::Game1Widget(QWidget *parent, User *user) : QWidget(parent)
{
    VerticalL = new QVBoxLayout;
    GridL = new QGridLayout;
	this->user = user
    Label_Description =  new QLabel("Snakes and Ladders is a very popular ancient Indian board game for children.\n "
                                    "The classic game depends on sheer luck since it involves rolling a die and\n moving"
                                    " on the board accordingly.The winner is the first player to reach the\n final square. "
                                    "We will introduce some changes to tweak the no-decision nature\n of the game and add"
                                    " and educational purpose.");
    PushButton_Exit = new QPushButton("Exit");
    PushButton_Exit = new QPushButton("Exit");
    PushButton_PlayNow = new QPushButton("Play Now");
    PushButton_ViewScores = new QPushButton("View Scores");
    VerticalL->addWidget(Label_Description);
    GridL->addWidget(PushButton_PlayNow,0,0);
    GridL->addWidget(PushButton_ViewScores,0,1);
    GridL->addWidget(PushButton_Exit,0,2);
	VerticalL->addItem(GridL);
    setLayout(VerticalL);
    QObject::connect(PushButton_Exit, SIGNAL(clicked(bool)), this, SLOT(exit()));
}

void Game1Widget::exit() {
    this->close();
    loggedwidget *lwidget = new loggedwidget(nullptr, this->user);
    lwidget->show();
}


