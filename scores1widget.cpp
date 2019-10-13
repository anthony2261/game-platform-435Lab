#include "scores1widget.h"
#include "game1widget.h"

scores1widget::scores1widget(QWidget *parent, User *user) : QWidget(parent)
{
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

void scores1widget::exit() {
    this->close();
    Game1Widget *gwidget = new Game1Widget(nullptr, this->user);
    gwidget->show();
}
