#include "loggedwidget.h"
#include "mainwidget.h"
#include "game1widget.h"
#include "game2widget.h"

loggedwidget::loggedwidget(QWidget *parent, User *user) : QWidget(parent)
{
    GridL = new QGridLayout;
    this->user = user;
    Label_username = new QLabel(user->username);
    Label_profilepic = new QLabel("");
    inputImg = new QImage("/home/eece435l/435lproject_ja9/index.jpeg");
    Label_profilepic->setPixmap(QPixmap::fromImage(*inputImg).scaled(80,100,Qt::KeepAspectRatio,Qt::FastTransformation));
    Label_profilepic->adjustSize();
    PushButton_Game1 = new QPushButton("Game 1");
    PushButton_Game2 = new QPushButton("Game2");
    PushButton_Signout = new QPushButton("Signout");
    GridL->addWidget(Label_username,0,1);
    GridL->addWidget(Label_profilepic,0,0);
    GridL->addWidget(PushButton_Game1,1,0);
    GridL->addWidget(PushButton_Game2,1,1);
    GridL->addWidget(PushButton_Signout,1,2);
    setLayout(GridL);
    QObject::connect(PushButton_Signout, SIGNAL(clicked(bool)), this, SLOT(signout()));
    QObject::connect(PushButton_Game1, SIGNAL(clicked(bool)), this, SLOT(playgame1()));
    QObject::connect(PushButton_Game2, SIGNAL(clicked(bool)), this, SLOT(playgame2()));
}

void loggedwidget::signout() {
    this->close();
    mainwidget *mwidget = new mainwidget();
    mwidget->show();
}

void loggedwidget::playgame1(){
    this->close();
    Game1Widget *g1widget = new Game1Widget(nullptr, user);
    g1widget->show();
}

void loggedwidget::playgame2(){
    this->close();
    game2widget *g2widget = new game2widget(nullptr, user);
    g2widget->show();
}
