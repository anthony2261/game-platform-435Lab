#include "snakesandladders.h"
#include "gamewidget.h"

snakesandladders::snakesandladders(User *user, int gID)
{
    PushButton_Exit = new QPushButton("Exit");
    view = new QGraphicsView(this);
    this->user = user;
    this->gID = gID;
    this->setSceneRect(0,0,908,700);
    this->setBackgroundBrush(QBrush(QImage("/home/eece435l/project_ja_9/images/background.jpg").scaledToHeight(512).scaledToWidth(910)));
    this->addWidget(PushButton_Exit);
    view->setScene(this);
    view->show();

    QObject::connect(PushButton_Exit, SIGNAL(clicked(bool)), this, SLOT(exit()));
}

void snakesandladders::exit() {
    view->close();
    gamewidget *gwidget = new gamewidget(nullptr, this->user, gID);
    gwidget->show();
}
