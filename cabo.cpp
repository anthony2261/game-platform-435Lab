#include "cabo.h"
#include "gamewidget.h"

Cabo::Cabo(User *user, int gID)
{
    this->user = user;
    this->gID = gID;
    GridL = new QGridLayout;
    PushButton_Exit = new QPushButton("Exit");
    PushButton_Startgame = new QPushButton("Start Game");

    cat_img = new QGraphicsPixmapItem();
    cat_img->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/cabo/animals/cat.png")).scaled(120,120));
    cat_img->setPos(950,300);
    this->addItem(cat_img);

    dog_img = new QGraphicsPixmapItem();
    dog_img->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/cabo/animals/dog.png")).scaled(120,120));
    dog_img->setPos(230,300);
    this->addItem(dog_img);

    wolf_img = new QGraphicsPixmapItem();
    wolf_img->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/cabo/animals/wolf.png")).scaled(120,120));
    wolf_img->setPos(600,30);
    this->addItem(wolf_img);

    player_img = new QGraphicsPixmapItem();
    player_img->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/cabo/animals/morty_face.png")).scaled(120,120));
    player_img->setPos(600,600);
    this->addItem(player_img);

    card_back_img = new QGraphicsPixmapItem();
    card_back_img->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/cabo/cards/card_back_background.png")).scaled(70,95));
    card_back_img->setPos(550,300);
    this->addItem(card_back_img);

    drawpile = new  QVector<CaboCard*>;
    discardpile = new  QVector<CaboCard*>;
    drawpile->append(new CaboCard(0));
    drawpile->append(new CaboCard(0));
    drawpile->append(new CaboCard(13));
    drawpile->append(new CaboCard(13));
    for (int i=1;i<13;i++) {
        drawpile->append(new CaboCard(i));
        drawpile->append(new CaboCard(i));
        drawpile->append(new CaboCard(i));
        drawpile->append(new CaboCard(i));
    }
    plr1 = new CaboPlayer();
    plr2 = new CaboPlayer();
    plr3 = new CaboPlayer();

    view = new QGraphicsView(this);
    view->setFixedWidth(1100);
    view->setFixedHeight(700);
    this->setSceneRect(0,0,1100,800);

    GridL->addWidget(PushButton_Startgame,0,0); // Hi anthony
    GridL->addWidget(PushButton_Exit,7,0);
    GridL->setContentsMargins(0,0,900,200);
    GridL->setVerticalSpacing(30);

    view->setLayout(GridL);
    view->setScene(this);
    view->show();

    QObject::connect(PushButton_Exit, SIGNAL(clicked(bool)), this, SLOT(exit()));
    QObject::connect(PushButton_Startgame, SIGNAL(clicked(bool)), this, SLOT(start_game()));
}


void Cabo::start_game(){

    std::random_shuffle(drawpile->begin(), drawpile->end());
    for (int i=0;i<4;i++) {
        plr1->cards->append(drawpile->front());
        drawpile->pop_front();
    }
    for (int i=0;i<4;i++) {
        plr2->cards->append(drawpile->front());
        drawpile->pop_front();
    }
    for (int i=0;i<4;i++) {
        plr3->cards->append(drawpile->front());
        drawpile->pop_front();
    }

    PushButton_Startgame->hide();
    display_cards();

}

void Cabo::display_cards() {

}

void Cabo::playerturn(int player_number) {
    if (player_number == 1) {

    }
}

void Cabo::exit() {
    view->close();
    gamewidget *gwidget = new gamewidget(nullptr, this->user, gID);
    gwidget->show();
}
