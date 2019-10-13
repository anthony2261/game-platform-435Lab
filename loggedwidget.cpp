#include "loggedwidget.h"
#include "mainwidget.h"
#include "gamewidget.h"
//#include "game2widget.h"
#include <string>

loggedwidget::loggedwidget(QWidget *parent, User *user) : QWidget(parent)
{
    GridL = new QGridLayout;
    this->user = user;
    QString *format = new QString("dd.MM.yyyy");
    std::string currentDate = QDate::currentDate().toString(*format).toStdString();
    std::string dob_str = user->dob.toStdString();

    if (currentDate.substr(0, currentDate.length() - 4) == dob_str.substr(0, dob_str.length() - 4)){
        Label_username = new QLabel("Happy Birthday " + user->username + "!");
    }
    else
        Label_username = new QLabel(user->username);
    Label_profilepic = new QLabel("");
    inputImg = new QImage("/home/eece435l/project_ja_9/users/pictures/" + user->username + ".jpg");
    if (inputImg->isNull()) {
        inputImg = new QImage("/home/eece435l/project_ja_9/users/pictures/Guest.jpg");
    }
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
    gamewidget *gwidget = new gamewidget(nullptr, user, 1);
    gwidget->show();
}

void loggedwidget::playgame2(){
    this->close();
    gamewidget *gwidget = new gamewidget(nullptr, user, 2);
    gwidget->show();
}
