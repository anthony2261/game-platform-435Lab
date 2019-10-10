#include "loggedwidget.h"

loggedwidget::loggedwidget(QWidget *parent, QString username) : QWidget(parent)
{
    GridL = new QGridLayout;
    Label_username = new QLabel(username);
    Label_profilepic = new QLabel("");
    inputImg = new QImage("/home/eece435l/435lproject_ja9/index.jpeg");
    Label_profilepic->setPixmap(QPixmap::fromImage(*inputImg));
    Label_profilepic->adjustSize();
    PushButton_Game1 = new QPushButton("Game 1");
    PushButton_Game2 = new QPushButton("Game2");
    GridL->addWidget(Label_username,0,1);
    GridL->addWidget(Label_profilepic,0,0);
    GridL->addWidget(PushButton_Game1,1,0);
    GridL->addWidget(PushButton_Game2,1,1);
    setLayout(GridL);
}
