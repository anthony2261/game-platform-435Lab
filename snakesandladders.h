#ifndef SNAKESANDLADDERS_H
#define SNAKESANDLADDERS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "user.h"
#include "snake.h"
#include "ladder.h"
#include <QtWidgets>


/**
  * \file snakesandladders.h
  * \brief Contains the snakesandladders class
  */

/**
 * @brief The core of the "snakes and ladders" game resides here.
 */

class snakesandladders: public QGraphicsScene
{
   Q_OBJECT
public:
    /**
     * @brief snakesandladdes Constructor
     * @param user User that logged in (Even if Guest)
     * @param gID Id of the selected game
     *
     *  Sets everything in place: the start button and exit button, the board, the pins, the snakes and the ladders. The "snakes&ladders.json" file inside the users folder decides on the locations of the snakes and ladders. If it is random ("random":"yes"), then the obstacles are set at random but within range. If not, the coordinates are extracted from the json file.
     */
    snakesandladders(User *user = new User(nullptr, "Guest", "Guest"), int gID = 1);

private:
    QGraphicsView *view;
    QGridLayout *GridL; //!< Grid containing all the buttons
    QPushButton *PushButton_WhoStarts;
    QPushButton *PushButton_Exit;
    QPushButton *PushButton_Roll;
    QPushButton *PushButton_Computer;
    QPushButton *PushButton_Die1;
    QPushButton *PushButton_Die2;
    QLabel *Label_Text;
    QLabel *Label_Turn;
    User *user;
    QGraphicsPixmapItem *board;
    QGraphicsPixmapItem *player1_pin;
    QGraphicsPixmapItem *player2_pin;
    snake *snake1;
    snake *snake2;
    snake *snake3;
    snake *snake4;
    ladder *ladder1;
    ladder *ladder2;
    ladder *ladder3;
    ladder *ladder4;
    int gID;
    bool player_rolled; //!< false if the player needs to roll
    bool player_picked; //!< false if the player has to pick a die
    bool gameover; //!< true if the game is over
    int pin1_x;
    int pin1_y;
    int pin2_x;
    int pin2_y;
public slots:
    /**
     * @brief exit game, and go to gamewidget (snakes and ladders main page)
     */
    void exit();

    /**
     * @brief player rolls the dice. Both dice are randomly "rolled" and can assume numbers from 1 to 6 inclusive.
     */
    void rolldice();

    /**
     * @brief called when player picks die1.
     *  Pin1 moves by amount on die 1. Pin2 moves by amount on die 2. (calls move_pins function)
     */
    void player_picked_die1();

    /**
     * @brief called when player picks die2.
     *  Pin1 moves by amount on die 2. Pin2 moves by amount on die 1. (calls move_pins function)
     */
    void player_picked_die2();

    /**
     * @brief move pins after picking which die. Computer also uses this function.
     * @param move1 int how many squares to move pin1 by.
     * @param move2 int how many squares to move pin2 by.
     *
     *  Moves pin1 first. Calls relocate after each increment, and waits 300 ms before next increment. After completely moving pin1, checks for snakes and ladders by calling check_for_snakes_and_ladders(). Finally moves pin2 the same way and also checks for snakes/ladders at the end. If a pin reaches square 100 and still has to move, it moves the opposite direction. Wins if reached top with no more moves.
     */
    void move_pins(int move1, int move2);

    /**
     * @brief relocate the pins: Calculates and sets the position of the image of the pins based on their coordinate (1 coordinate).
     */
    void relocate();

    /**
     * @brief checks if any pin is at the bottom of a ladder or at the top of a snake. Moves the pin accordingly if true, and relocates their image with relocate(). Good/Bad practice messages pop if a ladder/snake was used, respectively.
     */
    void check_for_snakes_and_ladders();

    /**
     * @brief computer rolls dice, picks one randomly, and calls move_pins function.
     */
    void computer_turn();

    /**
     * @brief who_starts decides who should start based on rolling two dice. Player with higher roll starts.
     */
    void who_starts();

    /**
     * @brief wins
     * @param winner
     *
     *  Called when someone wins. gameover flag gets set to true. Shows message of who won. If the user wins, his score gets increased by 1 in the database.
     */
    void wins(int winner);
};

#endif // SNAKESANDLADDERS_H
