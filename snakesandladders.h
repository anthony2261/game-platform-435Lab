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
    QPushButton *PushButton_Exit;
    QPushButton *PushButton_Roll;
    QPushButton *PushButton_Die1;
    QPushButton *PushButton_Die2;
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
public slots:
    void exit();
    void rolldice();

};

#endif // SNAKESANDLADDERS_H
