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

class snakesandladders: public QGraphicsScene
{
   Q_OBJECT
public:
    snakesandladders(User *user = new User(nullptr, "Guest", "Guest"), int gID = 1);

private:
    QGraphicsView *view;
    QGridLayout *GridL; //!< Grid
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
    bool player_rolled;
    bool player_picked;
    bool gameover;
    int pin1_x;
    int pin1_y;
    int pin2_x;
    int pin2_y;
public slots:
    void exit();
    void rolldice();
    void player_picked_die1();
    void player_picked_die2();
    void move_pins(int move1, int move2);
    void relocate();
    void check_for_snakes_and_ladders();
    void computer_turn();
    void who_starts();
};

#endif // SNAKESANDLADDERS_H
