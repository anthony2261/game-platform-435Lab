#ifndef SNAKESANDLADDERS_H
#define SNAKESANDLADDERS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "user.h"
#include <QtWidgets>

class snakesandladders: public QGraphicsScene
{
   Q_OBJECT
public:
    snakesandladders(User *user = new User(nullptr, "Guest", "Guest"), int gID = 1);

private:
    QGraphicsView *view;
    QPushButton *PushButton_Exit;
    User *user;
    int gID;
public slots:
    void exit();

};

#endif // SNAKESANDLADDERS_H
