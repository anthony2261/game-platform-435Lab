#ifndef CABO_H
#define CABO_H

#include <QObject>
#include <QMainWindow>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "user.h"
#include "caboplayer.h"
#include "cabocard.h"
#include <QtWidgets>
#include <algorithm>

class Cabo : public QGraphicsScene
{
    Q_OBJECT
public:
    Cabo(User *user = new User(nullptr, "Guest", "Guest"), int gID = 2);

    void place(int plrnum, CaboCard *card, int pos = 0);
private:
    User *user;
    int gID;

    QGraphicsView *view;
    QGridLayout *GridL; //!< Grid
    QPushButton *PushButton_Exit;
    QPushButton *PushButton_Startgame;
    QPushButton *PushButton_PickFromDraw;
    QPushButton *PushButton_PickFromDiscard;
    QPushButton *PushButton_CallCabo;
    QPushButton *PushButton_ReplaceCard;
    //QPushButton *PushButton_ReplaceCardFromDiscard;
    QPushButton *PushButton_DiscardFromDraw;
    QPushButton *PushButton_UseSpecial;
    QPushButton *PushButton_Peek;
    QPushButton *PushButton_Spy;
    QPushButton *PushButton_Swap;
    QPushButton *PushButton_SwapWith;
    QPushButton *PushButton_EndTurn;

    QPushButton *TESTB;

    QLabel *Label_Text;
    QGraphicsPixmapItem *cat_img;
    QGraphicsPixmapItem *dog_img;
    QGraphicsPixmapItem *wolf_img;
    QGraphicsPixmapItem *player_img;
    QGraphicsPixmapItem *card_back_img;

    QVector<CaboCard *> *discardpile;
    QVector<CaboCard *> *drawpile;
    CaboPlayer *plr1;
    CaboPlayer *plr2;
    CaboPlayer *plr3;
    CaboPlayer *plr4;

    void display_cards();
signals:

public slots:
    void start_game();
    void computerTurn();
    void exit();

    void fromDraw();
    void fromDiscard();
    void calledCabo();
    void TESTF();
    void replace();
    //void replaceFromDraw();
    //void replaceFromDiscard();
    void discardFromDraw();
    void useSpecial();
    void peek();
    void spy();
    void swap();
    void swap_with();
};

#endif // CABO_H
