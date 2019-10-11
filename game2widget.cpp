#include "game2widget.h"
#include "loggedwidget.h"

game2widget::game2widget(QWidget *parent) : QWidget(parent)
{
    GridL = new QGridLayout;
    VerticalL = new QVBoxLayout;
    Label_Description =  new QLabel("Cabo is a card game that combines memory, luck and tactics.\n The objective of the game is "
                                    "to collect the lowest cards in each \nhand to accumulate the fewest points"
                                    " by the end of the game.");
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

void game2widget::exit() {
    this->close();
    loggedwidget *lwidget = new loggedwidget;
    lwidget->show();
}
