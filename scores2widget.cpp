#include "scores2widget.h"
#include "game2widget.h"

scores2widget::scores2widget(QWidget *parent, User *user) : QWidget(parent)
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

void scores2widget::exit() {
    this->close();
    game2widget *gwidget = new game2widget(nullptr, this->user);
    gwidget->show();
}
