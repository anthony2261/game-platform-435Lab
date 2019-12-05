#include "cabo.h"
#include "gamewidget.h"

Cabo::Cabo(User *user, int gID)
{
    this->user = user;
    this->gID = gID;
    GridL = new QGridLayout;
    PushButton_Exit = new QPushButton("Exit");
    PushButton_Startgame = new QPushButton("Start Game");
    PushButton_PickFromDraw = new QPushButton("Pick from draw pile");
    PushButton_PickFromDiscard = new QPushButton("Pick from discard pile");
    PushButton_CallCabo = new QPushButton("Call Cabo");
    PushButton_ReplaceCardFromDraw = new QPushButton("Replace card");
    PushButton_UseSpecial = new QPushButton("");
    PushButton_Peek = new QPushButton("Peek");
    PushButton_Spy= new QPushButton("Spy");
    PushButton_Swap= new QPushButton("Swap");
    PushButton_DiscardFromDraw = new QPushButton("Discard");
    TESTB = new QPushButton("TEST");

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
    if(user->gender == "f") {
        player_img->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/cabo/animals/diane.png")).scaled(120,120));
    } else {
        player_img->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/cabo/animals/morty_face.png")).scaled(120,120));
    }
    player_img->setPos(600,650);
    this->addItem(player_img);

    card_back_img = new QGraphicsPixmapItem();
    card_back_img->setPixmap((QPixmap("/home/eece435l/project_ja_9/images/cabo/cards/card_back_background.png")).scaled(80,105));
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
    plr4 = new CaboPlayer();

    view = new QGraphicsView(this);
    view->setFixedWidth(1100);
    view->setFixedHeight(800);
    this->setSceneRect(0,0,1100,800);

    //GridL:
    //0  Startgame
    //1  pickfromdraw
    //2  pickfrom discard
    //3  callcabo
    //4  replacecardfromdraw      usespecial
    //5  discardfromdraw
    //6  peek
    //7  spy
    //8  swap
    //9  exit                     Testbutton

    GridL->addWidget(PushButton_Startgame,0,0); // Hi anthony
    GridL->addWidget(PushButton_PickFromDraw,1,0);
    GridL->addWidget(PushButton_PickFromDiscard,2,0);
    GridL->addWidget(PushButton_CallCabo,3,0);
    GridL->addWidget(PushButton_ReplaceCardFromDraw,4,0);
    GridL->addWidget(PushButton_UseSpecial,4,1);
    GridL->addWidget(PushButton_DiscardFromDraw,5,0);
    GridL->addWidget(PushButton_Peek,6,0);
    GridL->addWidget(PushButton_Spy,7,0);
    GridL->addWidget(PushButton_Swap,8,0);
    GridL->addWidget(TESTB,9,1);
    PushButton_PickFromDiscard->hide();
    PushButton_PickFromDraw->hide();
    PushButton_CallCabo->hide();
    PushButton_ReplaceCardFromDraw->hide();
    PushButton_UseSpecial->hide();
    PushButton_Peek->hide();
    PushButton_Spy->hide();
    PushButton_Swap->hide();
    PushButton_DiscardFromDraw->hide();
    GridL->addWidget(PushButton_Exit,9,0);
    GridL->setContentsMargins(0,0,900,200);
    GridL->setVerticalSpacing(30);

    view->setLayout(GridL);
    view->setScene(this);
    view->show();

    QObject::connect(PushButton_PickFromDraw, SIGNAL(clicked(bool)), this, SLOT(fromDraw()));
    QObject::connect(TESTB, SIGNAL(clicked(bool)), this, SLOT(TESTF()));
    QObject::connect(PushButton_PickFromDiscard, SIGNAL(clicked(bool)), this, SLOT(fromDiscard()));
    QObject::connect(PushButton_CallCabo, SIGNAL(clicked(bool)), this, SLOT(calledCabo()));
    QObject::connect(PushButton_Exit, SIGNAL(clicked(bool)), this, SLOT(exit()));
    QObject::connect(PushButton_Startgame, SIGNAL(clicked(bool)), this, SLOT(start_game()));
    QObject::connect(PushButton_ReplaceCardFromDraw, SIGNAL(clicked(bool)), this, SLOT(replaceFromDraw()));
    QObject::connect(PushButton_UseSpecial, SIGNAL(clicked(bool)), this, SLOT(useSpecial()));
    QObject::connect(PushButton_Peek, SIGNAL(clicked(bool)), this, SLOT(peek()));
    QObject::connect(PushButton_Spy, SIGNAL(clicked(bool)), this, SLOT(spy()));
    QObject::connect(PushButton_Swap, SIGNAL(clicked(bool)), this, SLOT(swap()));
    QObject::connect(PushButton_DiscardFromDraw, SIGNAL(clicked(bool)), this, SLOT(discardFromDraw()));

}

void Cabo::TESTF() {
    QList<QGraphicsItem*> list = this->selectedItems();
//    QMessageBox::information(NULL, "Information!", QString::number(list.size()));
    if(list.size() > 0) {
        CaboCard* selected = (CaboCard*) list.at(0);
        QMessageBox::information(NULL, "Information!", QString::number(selected->number));
    }
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

    for (int i=0;i<4;i++) {
        plr4->cards->append(drawpile->front());
        drawpile->pop_front();
    }

    PushButton_Startgame->hide();
    display_cards();

    discardpile->append(drawpile->front());
    drawpile->pop_front();
    place(5,discardpile->front());
    PushButton_PickFromDiscard->show();
    PushButton_PickFromDraw->show();
    PushButton_CallCabo->show();

}

void Cabo::place(int plrnum, CaboCard * card, int pos) {
    // plrnum 1 = plr1, plrnum 2 = plr2, plrnum 3 = plr3, plrnum 4 = plr4, plrnum 5 = middle
    // pos of card except if pos = -1 then to the left of plr1 (and plrnum must be = 1)
    int y = 0;
    int x = 0;
    if(plrnum == 1) { // 600, 600
        x += 600;
        y += 550;
    } else {
        if (plrnum == 4) { // 950, 300
            x += 800;
            y += 350;
        } else {
            if (plrnum == 2) { //230, 300
                x += 330;
                y += 350;
            } else { //600,30 (plr3)
                if (plrnum == 3) {
                    x += 450;
                    y += 130;
                } else { // middle
                    x += 645;
                    y += 300;
                    card->faceup = true;
                }
            }
        }
    }
    if(pos == -1) {
        x -= 150;
        y += 50;
        card->faceup = true;
    } else {
        if(pos%2 == 0) {
            x += 82*(pos/2);
        } else {
            y -= 107;
            x += 82*(pos-1)/2;
        }
    }

    if(card->faceup) {
        card->setPixmap((QPixmap(QString("/home/eece435l/project_ja_9/images/cabo/cards/card%1.png").arg(card->number))).scaled(80,105));
    } else {
        card->setPixmap((QPixmap(QString("/home/eece435l/project_ja_9/images/cabo/cards/card_back_background.png"))).scaled(80,105));
    }
    card->setPos(x, y);
    card->show();
    this->addItem(card);
}
void Cabo::display_cards() {
    //p1
    for(int i = 0; i < plr1->cards->size(); i++) {
        place(1, plr1->cards->at(i), i);
    }

    //p2
    for(int i = 0; i < plr2->cards->size(); i++) {
        place(2, plr2->cards->at(i), i);
    }

    //p3
    for(int i = 0; i < plr3->cards->size(); i++) {
        place(3, plr3->cards->at(i), i);
    }

    //p4
    for(int i = 0; i < plr4->cards->size(); i++) {
        place(4, plr4->cards->at(i), i);
    }
}

void Cabo::playerturn(int player_number) {
    if (player_number == 1) {

    }
}

void Cabo::fromDraw() {
    CaboCard * drawn = drawpile->front();

    PushButton_PickFromDiscard->hide();
    PushButton_PickFromDraw->hide();
    PushButton_CallCabo->hide();
    PushButton_ReplaceCardFromDraw->show();
    PushButton_DiscardFromDraw->show();
    if(drawn->choice == "none") {
        PushButton_UseSpecial->setText("no special");
        PushButton_UseSpecial->setEnabled(false);
    } else {
        PushButton_UseSpecial->setText("use special");
        PushButton_UseSpecial->setEnabled(true);
    }
    PushButton_UseSpecial->show();
    place(1,drawn,-1);
    for(auto card=plr1->cards->begin();card<plr1->cards->end();card++) {
        (*card)->setFlag(QGraphicsItem::ItemIsSelectable,true);
    }
}

void Cabo::replaceFromDraw() {
        QList<QGraphicsItem*> list = this->selectedItems();
    //    QMessageBox::information(NULL, "Information!", QString::number(list.size()));
        if(list.size() < 1) {
            QMessageBox::information(NULL, "Information!", "Must select a card!");
        } else {
            for(auto card=plr1->cards->begin();card<plr1->cards->end();card++) {
                (*card)->setFlag(QGraphicsItem::ItemIsSelectable,false);
            }
            CaboCard * drawn = drawpile->front();
            drawpile->pop_front();
            CaboCard* selected = (CaboCard*) list.at(0);
            int index = -1;
            for (int i = 0; i < plr1->cards->size(); i++) {
                if(plr1->cards->at(i) == selected) {
                    index = i;
                    break;
                }
            }

            plr1->cards->replace(index, drawn);
            drawn->faceup = false;
            place(1,drawn,index);
            discardpile->at(discardpile->size()-1)->hide();
            discardpile->append(selected);
            place(5,selected);
        }
}

void Cabo::useSpecial() {
    for(auto card=plr1->cards->begin();card<plr1->cards->end();card++) {
        (*card)->setFlag(QGraphicsItem::ItemIsSelectable, false);
    }
    PushButton_ReplaceCardFromDraw->hide();
    PushButton_UseSpecial->hide();
    PushButton_DiscardFromDraw->hide();

    CaboCard * drawn = drawpile->front();
    drawpile->pop_front();
    discardpile->at(discardpile->size()-1)->hide();
    discardpile->append(drawn);
    place(5,drawn);
    if(drawn->choice == "peek") {
        PushButton_Peek->show();
        for(auto card=plr1->cards->begin();card<plr1->cards->end();card++) {
            (*card)->setFlag(QGraphicsItem::ItemIsSelectable, true);
        }
    } else {
        if(drawn->choice == "spy") {
            PushButton_Spy->show();
            for(auto card=plr2->cards->begin();card<plr2->cards->end();card++) {
                (*card)->setFlag(QGraphicsItem::ItemIsSelectable, true);
            }
            for(auto card=plr3->cards->begin();card<plr3->cards->end();card++) {
                (*card)->setFlag(QGraphicsItem::ItemIsSelectable, true);
            }
            for(auto card=plr4->cards->begin();card<plr4->cards->end();card++) {
                (*card)->setFlag(QGraphicsItem::ItemIsSelectable, true);
            }
        } else {
            if(drawn->choice == "swap") {
                PushButton_Swap->show();
                for(auto card=plr1->cards->begin();card<plr1->cards->end();card++) {
                    (*card)->setFlag(QGraphicsItem::ItemIsSelectable, true);
                }
                for(auto card=plr2->cards->begin();card<plr2->cards->end();card++) {
                    (*card)->setFlag(QGraphicsItem::ItemIsSelectable, true);
                }
                for(auto card=plr3->cards->begin();card<plr3->cards->end();card++) {
                    (*card)->setFlag(QGraphicsItem::ItemIsSelectable, true);
                }
                for(auto card=plr4->cards->begin();card<plr4->cards->end();card++) {
                    (*card)->setFlag(QGraphicsItem::ItemIsSelectable, true);
                }
            }
        }
    }
}

void Cabo::peek() {

}

void Cabo::spy() {

}

void Cabo::swap() {

}

void Cabo::discardFromDraw() {
    for(auto card=plr1->cards->begin();card<plr1->cards->end();card++) {
        (*card)->setFlag(QGraphicsItem::ItemIsSelectable, false);
    }
    CaboCard * drawn = drawpile->front();
    drawpile->pop_front();
    discardpile->at(discardpile->size()-1)->hide();
    discardpile->append(drawn);
    place(5,drawn);
}

void Cabo::fromDiscard() {
}

void Cabo::calledCabo() {
}

void Cabo::exit() {
    view->close();
    gamewidget *gwidget = new gamewidget(nullptr, this->user, gID);
    gwidget->show();
}
