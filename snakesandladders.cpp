#include "snakesandladders.h"
#include "gamewidget.h"
#include "square.h"
//#include <vector>
//#include <QtTest/QTest>
//#include <unistd.h>

snakesandladders::snakesandladders(User *user, int gID)
{
    pin1_x = 0;
    pin1_y = 0;
    pin2_x = 0;
    pin2_y = 0;
    player_rolled = false;
    player_picked = false;
    GridL = new QGridLayout;
    PushButton_Exit = new QPushButton("Exit");
    PushButton_Roll = new QPushButton("Roll Dice");
    PushButton_Computer = new QPushButton("Computer");
    PushButton_Die1 = new QPushButton("");
    PushButton_Die2 = new QPushButton("");
    Label_Text = new QLabel("");
    Label_Text->hide();
    PushButton_Die1->hide();
    PushButton_Die2->hide();

    // OLD: board goes from x:200 y:0 to x:980 y:550 so each square is 78x55
    // NEW: each square is 65x65
    board = new QGraphicsPixmapItem();
    board->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/background2.png")));
    board->setPos(200,0);

    player1_pin = new QGraphicsPixmapItem();
    player1_pin->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/pin1.png")).scaled(40,40));
//    player1_pin->setPos(980,0);old
//    player1_pin->setPos(785,10); new top right
    player1_pin->setPos(200,595); // new bot left
//    player1_pin->setPos(200 + 65, 595 - 65);

    player2_pin = new QGraphicsPixmapItem();
    player2_pin->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/pin2.png")).scaled(40,40));
//    player2_pin->setPos(200,550);
    player2_pin->setPos(230,595); // new bot left
//    player2_pin->setPos(230 + 65*9, 595 - 65*8);

//    int snake1_topxrand = rand() % 9 + 1;
//    int snake1_topyrand = rand() % 7 + 3;
//    snake1= new snake(37,6);
//    snake1->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/snake1.png")).scaled(200,200));
//    snake1->setPos(400,430);

//    snake2= new snake(98,62);
//    snake2->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/snake2.png")).scaled(200,200));
//    snake2->setPos(265,45);

//    snake3= new snake(75,49);
//    snake3->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/snake1.png")).scaled(200,200));
//    snake3->setPos(550,170);

//    snake4= new snake(55,28);
//    snake4->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/snake4.png")).scaled(200,200));
//    snake4->setPos(530,300);

    int ladder1_topxrand = rand() % 10;
    int ladder1_topyrand = rand() % 8 + 2;
//    int ladder1_topxrand = 5;
//    int ladder1_topyrand = 2;
    qWarning() << QString::number(ladder1_topxrand);
    qWarning() << QString::number(ladder1_topyrand);
//    ladder1= new ladder(8,28);
    ladder1 = new ladder(ladder1_topxrand, ladder1_topyrand - 2, ladder1_topxrand, ladder1_topyrand);
//    ladder1->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/ladder1.png")).scaled(200,200));
    ladder1->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/ladder1.png")).scaled(49,175));
//    ladder1->setPos(300,200);
    ladder1->setPos(220 + 65*ladder1_topxrand, 600 - 65*ladder1_topyrand);

//    ladder2= new ladder(43,64);
//    ladder2->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/ladder2.png")).scaled(200,200));
//    ladder2->setPos(600,470);


    view = new QGraphicsView(this);
    view->setFixedWidth(1100);
    view->setFixedHeight(700);
    this->addItem(board);
    this->addItem(player1_pin);
    this->addItem(player2_pin);
//    this->addItem(snake1);
//    this->addItem(snake2);
//    this->addItem(snake3);
//    this->addItem(snake4);
    this->addItem(ladder1);
//    this->addItem(ladder2);
    this->user = user;
    this->gID = gID;
    this->setSceneRect(0,0,1100,800);


    GridL->addWidget(PushButton_Exit,7,0);
    GridL->addWidget(PushButton_Roll,0,0);
    GridL->addWidget(PushButton_Computer,0,1);
    GridL->addWidget(Label_Text,1,0);
    GridL->addWidget(PushButton_Die1,2,0);
    GridL->addWidget(PushButton_Die2,2,1);
    GridL->setContentsMargins(0,0,900,200);
    GridL->setVerticalSpacing(30);


    view->setLayout(GridL);
    view->setScene(this);
    view->show();

    QObject::connect(PushButton_Exit, SIGNAL(clicked(bool)), this, SLOT(exit()));
    QObject::connect(PushButton_Roll, SIGNAL(clicked(bool)), this, SLOT(rolldice()));
    QObject::connect(PushButton_Computer, SIGNAL(clicked(bool)), this, SLOT(computer_turn()));
    QObject::connect(PushButton_Die1, SIGNAL(clicked(bool)), this, SLOT(player_picked_die1()));
    QObject::connect(PushButton_Die2, SIGNAL(clicked(bool)), this, SLOT(player_picked_die2()));
}

void snakesandladders::exit() {
    view->close();
    gamewidget *gwidget = new gamewidget(nullptr, this->user, gID);
    gwidget->show();
}

void snakesandladders::computer_turn() {
    if(player_picked) {
        PushButton_Die1->hide();
        PushButton_Die2->hide();
        Label_Text->show();
        int rand1 = rand() % 6 + 1;
        int rand2 = rand() % 6 + 1;
        int die_picked = rand() % 2  + 1;

        if (die_picked == 1) {
            Label_Text->setText(QString("The computer\n rolled %1 \n and %2 and \n picked %1").arg(rand1).arg(rand2));
            move_pins(rand2,rand1);
        }

        else {
            Label_Text->setText(QString("The computer\n rolled %1 \n and %2 and \n picked %2").arg(rand1).arg(rand2));
            move_pins(rand1,rand2);
        }
        player_rolled = false;
        player_picked = false;
    }
}

void snakesandladders::rolldice() {
    Label_Text->hide();
    if (!player_rolled) {
        int rand1 = rand() % 6 + 1;
        int rand2 = rand() % 6 + 1;
        PushButton_Die1->setText(QString::number(rand1));
        PushButton_Die2->setText(QString::number(rand2));
        PushButton_Die1->show();
        PushButton_Die2->show();
        player_rolled = true;
    }
}

void snakesandladders::player_picked_die1() {
    if (!player_picked) {
//        qWarning() << PushButton_Die1->text().toInt();
        move_pins(PushButton_Die1->text().toInt(), PushButton_Die2->text().toInt());
        player_picked = true;
    }
}

void snakesandladders::player_picked_die2() {
    if (!player_picked) {
//        qWarning() << PushButton_Die2->text().toInt();
        move_pins(PushButton_Die2->text().toInt(), PushButton_Die1->text().toInt());
        player_picked = true;
    }
}

void snakesandladders::move_pins(int move1, int move2) {
    bool pin1_hitTheTop = false;
    bool pin2_hitTheTop = false;

//    while(move1>0)
    for (int i = 0; i < move1; i++) {
        if (pin1_y == 9 && pin1_x == 0) {
            pin1_hitTheTop = true;
        }
        if (!pin1_hitTheTop) {
            if (pin1_y % 2 == 0) {
                if (pin1_x < 9) {
                    pin1_x++;
                } else {
                    pin1_y++;
                }
            } else {
                if (pin1_x > 0) {
                    pin1_x--;
                } else {
                    pin1_y++;
                }
            }
        } else {
            pin1_x++;
        }
        relocate();
        QTime dieTime = QTime::currentTime().addMSecs(300);
        while (QTime::currentTime() < dieTime) {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
    }
    check_for_snakes_and_ladders();

    for (int i = 0; i < move2; i++) {
        if (pin2_y == 9 && pin2_x == 0) {
            pin2_hitTheTop = true;
        }
        if (!pin2_hitTheTop) {
            if (pin2_y % 2 == 0) {
                if (pin2_x < 9) {
                    pin2_x++;
                } else {
                    pin2_y++;
                }
            } else {
                if (pin2_x > 0) {
                    pin2_x--;
                } else {
                    pin2_y++;
                }
            }
        } else {
            pin2_x++;
        }
        relocate();
        QTime dieTime = QTime::currentTime().addMSecs(300);
        while (QTime::currentTime() < dieTime) {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
    }

    check_for_snakes_and_ladders();
    relocate();
}

void snakesandladders::relocate() {
    player1_pin->setPos(200 + 65*pin1_x, 595 - 65*pin1_y);
    player2_pin->setPos(230 + 65*pin2_x, 595 - 65*pin2_y);
}

void snakesandladders::check_for_snakes_and_ladders() {

    int square_number_1;
    int square_number_2;

    if (pin1_y % 2 == 0) {
        square_number_1 = pin1_y*10 + pin1_x + 1;
    }

    else {
        square_number_1 = pin1_y*10 + 10 - pin1_x;
    }

//    if (snake1->head_square == square_number_1) {
//        pin1_x = snake1->tail_square % 10 -1;
//        pin1_y = snake1->tail_square / 10 ;
//    }

//    if (snake2->head_square == square_number_1) {
//        pin1_x = snake2->tail_square % 10 -1;
//        pin1_y = snake2->tail_square / 10 ;
//    }

//    if (snake3->head_square == square_number_1) {
//        pin1_x = snake3->tail_square % 10 -1;
//        pin1_y = snake3->tail_square / 10 ;
//    }

//    if (snake4->head_square == square_number_1) {
//        pin1_x = snake4->tail_square % 10 -1;
//        pin1_y = snake4->tail_square / 10 ;
//    }

//    if (ladder1->bottom_square == square_number_1) {
//        pin1_x = ladder1->top_square % 10 -1;
//        pin1_y = ladder1->top_square / 10 ;
//    }

    if (ladder1->bx == pin1_x && ladder1->by == pin1_y) {
        pin1_x = ladder1->tx;
        pin1_y = ladder1->ty;
        check_for_snakes_and_ladders();
    }


//    if (ladder2->bottom_square == square_number_1) {
//        pin1_x = ladder2->top_square % 10 -1;
//        pin1_y = ladder2->top_square / 10 ;
//    }

    //now same for pin2

    if (pin2_y % 2 == 0) {
        square_number_2 = pin2_y*10 + pin2_x + 1;
    }

    else {
        square_number_2 = pin2_y*10 + 10 - pin2_x;
    }

//    if (snake1->head_square == square_number_2) {
//        pin2_x = snake1->tail_square % 10 -1;
//        pin2_y = snake1->tail_square / 10 ;
//    }

//    if (snake2->head_square == square_number_2) {
//        pin2_x = snake2->tail_square % 10 -1;
//        pin2_y = snake2->tail_square / 10 ;
//    }

//    if (snake3->head_square == square_number_2) {
//        pin2_x = snake3->tail_square % 10 -1;
//        pin2_y = snake3->tail_square / 10 ;
//    }

//    if (snake4->head_square == square_number_2) {
//        pin2_x = snake4->tail_square % 10 -1;
//        pin2_y = snake4->tail_square / 10 ;
//    }

//    if (ladder1->bottom_square == square_number_2) {
//        pin2_x = ladder1->top_square % 10 -1;
//        pin2_y = ladder1->top_square / 10 ;
//    }
    if (ladder1->bx == pin2_x && ladder1->by == pin2_y) {
        pin2_x = ladder1->tx;
        pin2_y = ladder1->ty;
    }

//    if (ladder2->bottom_square == square_number_2) {
//        pin2_x = ladder2->top_square % 10 -1;
//        pin2_y = ladder2->top_square / 10 ;
//    }

}
