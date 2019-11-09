#include "snakesandladders.h"
#include "gamewidget.h"
#include "square.h"
#include <vector>

snakesandladders::snakesandladders(User *user, int gID)
{
    GridL = new QGridLayout;
    PushButton_Exit = new QPushButton("Exit");
    PushButton_Roll = new QPushButton("Roll Dice");
    PushButton_Die1 = new QPushButton("");
    PushButton_Die2 = new QPushButton("");
    PushButton_Die1->hide();
    PushButton_Die2->hide();

    //board goes from x:200 y:0 to x:980 y:550 so each square is 78x55
    board = new QGraphicsPixmapItem();
    board->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/background2.png")));
    board->setPos(200,0);

    player1_pin = new QGraphicsPixmapItem();
    player1_pin->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/pin1.png")).scaled(40,40));
    player1_pin->setPos(980,0);

    player2_pin = new QGraphicsPixmapItem();
    player2_pin->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/pin2.png")).scaled(40,40));
    player2_pin->setPos(200,550);

    snake1= new snake(20,5);
    snake1->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/snake1.png")).scaled(200,200));
    snake1->setPos(400,400);

    snake2= new snake(30,15);
    snake2->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/snake2.png")).scaled(200,200));
    snake2->setPos(800,400);

    snake3= new snake(40,25);
    snake3->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/snake3.png")).scaled(200,200));
    snake3->setPos(900,200);

    snake4= new snake(20,5);
    snake4->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/snake4.png")).scaled(200,200));
    snake4->setPos(500,300);

    ladder1= new ladder(9,29);
    ladder1->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/ladder1.png")).scaled(200,200));
    ladder1->setPos(300,200);

    ladder2= new ladder(20,5);
    ladder2->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/ladder2.png")).scaled(200,200));
    ladder2->setPos(600,470);


    view = new QGraphicsView(this);
    view->setFixedWidth(1100);
    view->setFixedHeight(700);
    this->addItem(board);
    this->addItem(player1_pin);
    this->addItem(player2_pin);
    this->addItem(snake1);
    this->addItem(snake2);
    this->addItem(snake3);
    this->addItem(snake4);
    this->addItem(ladder1);
    this->addItem(ladder2);
    this->user = user;
    this->gID = gID;
    this->setSceneRect(0,0,1100,650);


    GridL->addWidget(PushButton_Exit,7,0);
    GridL->addWidget(PushButton_Roll,0,0);
    GridL->addWidget(PushButton_Die1,2,0);
    GridL->addWidget(PushButton_Die2,2,1);
    GridL->setContentsMargins(0,0,900,200);
    GridL->setVerticalSpacing(30);


    view->setLayout(GridL);
    view->setScene(this);
    view->show();

    QObject::connect(PushButton_Exit, SIGNAL(clicked(bool)), this, SLOT(exit()));
    QObject::connect(PushButton_Roll, SIGNAL(clicked(bool)), this, SLOT(rolldice()));
}

void snakesandladders::exit() {
    view->close();
    gamewidget *gwidget = new gamewidget(nullptr, this->user, gID);
    gwidget->show();
}

void snakesandladders::rolldice() {
    int rand1 = rand() % 6 + 1;
    int rand2 = rand() % 6 + 1;
    PushButton_Die1->setText(QString::number(rand1));
    PushButton_Die2->setText(QString::number(rand2));
    PushButton_Die1->show();
    PushButton_Die2->show();
}
