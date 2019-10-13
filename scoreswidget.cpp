#include "scoreswidget.h"
#include "gamewidget.h"

scoreswidget::scoreswidget(QWidget *parent, User *user, int gID) : QWidget(parent)
{
    this->gID = gID;
    VerticalL = new QVBoxLayout;
    GridL = new QGridLayout;
    this->user = user;
    Label_Scores = new QLabel("Scores");
    PushButton_Exit = new QPushButton("Exit");
    GridL->addWidget(Label_Scores,0,0);
    GridL->addWidget(PushButton_Exit,1,0);
    VerticalL->addItem(GridL);
    setLayout(VerticalL);
    QObject::connect(PushButton_Exit, SIGNAL(clicked(bool)), this, SLOT(exit()));
}

void scoreswidget::exit() {
    this->close();
    gamewidget *gwidget = new gamewidget(nullptr, this->user, this->gID);
    gwidget->show();
}
