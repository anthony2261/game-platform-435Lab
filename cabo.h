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

/**
  * \file cabo.h
  * \brief Contains the cabo class
  */

/**
 * @brief The core of the "cabo" game resides here.
 */

class Cabo : public QGraphicsScene
{
    Q_OBJECT
public:
    /**
     * @brief cabo Constructor
     * @param user User that logged in (Even if Guest)
     * @param gID Id of the selected game
     *
     *  Sets everything in place: the ready button and exit button and the head of the players.
     */
    Cabo(User *user = new User(nullptr, "Guest", "Guest"), int gID = 2);


    /**
     * @brief places the card in desired location
     * @param plrnum int the number of the player the card belongs to.
     * @param card CaboCard* a pointer to the card that has to be placed
     * @param pos int the index of the card in the player's card vector
     *
     *  computes x and y coordinates using the plrnum and pos parameters before ssetting the location of the CaboCard pixmap
     */
    void place(int plrnum, CaboCard *card, int pos = 0);
private:
    User *user;
    int gID;

    QGraphicsView *view;
    QGridLayout *GridL; //!< Grid
    QPushButton *PushButton_Exit;
    QPushButton *PushButton_Startgame;
    QPushButton *PushButton_Ready;
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

    /**
     * @brief show the cards
     *  Called when the start button is pressed. Calls the place function on each of the player's 4 starting cards
     */
    void display_cards();
signals:

public slots:
    /**
     * @brief start the game
     *  invoked when the startgame button is pressed. giving each player 4 cards and putting one card in the discard pile before calling display_cards()
     */
    void start_game();
    /**
     * @brief handle the 3 computers'turns
     *  each player picks from the drawpile and randomly replaces one of his cards
     */
    void computerTurn();
    /**
     * @brief exit cabo
     *  deletes this scene and creates a gamewidget to display
     */
    void exit();
    /**
     * @brief pick from draw
     *  picks the front of the drawpile and put it in the global variable CardInPlay
     */
    void fromDraw();
    /**
     * @brief pick from discard
     *  picks the front of the discard pile and put it in the global variable CardInPlay
     */
    void fromDiscard();
    /**
     * @brief player calls cabo
     *  let the computers play one last round before all the cards are revealed, the sums are calculated and the winner is announced
     */
    void calledCabo();
    void TESTF();
    /**
     * @brief replace one of your cards with CardInPlay
     *  the player select the card he wants to replace before it is put in the discard pile and replaced with the CardInPlay
     */
    void replace();
    //void replaceFromDraw();
    //void replaceFromDiscard();
    /**
     * @brief discard CardInPlay
     *  can only be called when the card is drawn from the drawpile and will place the drawn card in the discardpile
     */
    void discardFromDraw();
    /**
     * @brief use the special card ability
     *  can only be called if the drawn card is from the drawpile and has a special ability.Checks this ability and displays the corresponding button
     */
    void useSpecial();
    /**
     * @brief peek special ability
     *  the player selects one of his cards and he is informed about its number in the Label_Text
     */
    void peek();
    /**
     * @brief spy special ability
     *  the player selects one of his opponents cards and he is informed about its number in the Label_Text
     */
    void spy();
    /**
     * @brief swap special ability
     *  the player selects one of his cards before pressing swap_with. This card will be swapped with the card he choses next
     */
    void swap();
    /**
     * @brief swap special ability part2
     *  the player selects one of his opponents cards which will be swapped with the card he chose in the previous step
     */
    void swap_with();
    /**
     * @brief refill drawpile
     *  all the cards from discard pile except the top one are shuffled and put back in the drawpile
     */
    void refill_draw();
    /**
     * @brief ready button
     *  the player presses this button after he memorised the 2 cards he is being shown. These cards are now face down.
     */
    void ready();
};

#endif // CABO_H
