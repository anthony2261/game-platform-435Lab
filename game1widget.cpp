#include "game1widget.h"
#include "loggedwidget.h"

Game1Widget::Game1Widget(QWidget *parent) : QWidget(parent)
{
    GridL = new QGridLayout;
    Label_Description =  new QLabel("Game 1 Description");
    PushButton_Exit = new QPushButton("Exit");
    PushButton_PlayNow = new QPushButton("Play Now");
    PushButton_ViewScores = new QPushButton("View Scores");
    GridL->addWidget(Label_Description,0,0);
    GridL->addWidget(PushButton_PlayNow,1,0);
    GridL->addWidget(PushButton_ViewScores,1,1);
    GridL->addWidget(PushButton_Exit,1,2);
    setLayout(GridL);
    QObject::connect(PushButton_Exit, SIGNAL(clicked(bool)), this, SLOT(exit()));
}

void Game1Widget::exit() {
    this->close();
    loggedwidget *lwidget = new loggedwidget;
    lwidget->show();
}


