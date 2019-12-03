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

private:
    User *user;
    int gID;

    QGraphicsView *view;
    QGridLayout *GridL; //!< Grid
    QPushButton *PushButton_Exit;
    QPushButton *PushButton_Startgame;
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

    void display_cards();
signals:

public slots:
    void start_game();
    void playerturn(int player_number);
    void exit();

};

#endif // CABO_H
