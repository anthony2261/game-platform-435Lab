#include "snakesandladders.h"
#include "gamewidget.h"
#include "square.h"
#include <vector>

snakesandladders::snakesandladders(User *user, int gID)
{
    GridL = new QGridLayout;
    PushButton_Exit = new QPushButton("Exit");
    view = new QGraphicsView(this);
    this->user = user;
    this->gID = gID;
    this->setSceneRect(0,0,908,700);
    this->setBackgroundBrush(QBrush(QImage("/home/eece435l/project_ja_9/images/background.jpg").scaledToHeight(512).scaledToWidth(910)));
    GridL->addWidget(PushButton_Exit,1,0);
    QVector<Square*> squareArr;
    for(int i = 0; i < 10; i++) {
        squareArr.push_back(new Square(nullptr,i+1));
        GridL->addWidget(squareArr[i],0,i);
    }

    view->setLayout(GridL);
    view->setScene(this);
    view->show();

    QObject::connect(PushButton_Exit, SIGNAL(clicked(bool)), this, SLOT(exit()));
}

void snakesandladders::exit() {
    view->close();
    gamewidget *gwidget = new gamewidget(nullptr, this->user, gID);
    gwidget->show();
}
