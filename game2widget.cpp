#include "game2widget.h"
#include "loggedwidget.h"
#include "user.h"

game2widget::game2widget(QWidget *parent, User *user) : QWidget(parent)
{
    GridL = new QGridLayout;
    this->user = user;
    Label_Description =  new QLabel("Game 2 Description");
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

void game2widget::exit() {
    this->close();
    loggedwidget *lwidget = new loggedwidget(nullptr, this->user);
    lwidget->show();
}
