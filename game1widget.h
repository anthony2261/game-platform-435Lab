#ifndef GAME1WIDGET_H
#define GAME1WIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "user.h"

class Game1Widget:public QWidget
{
    Q_OBJECT
public:
    explicit Game1Widget(QWidget *parent = nullptr, User *user = new User(nullptr, "Guest", "Guest"));
private:
    QGridLayout *GridL;
    QLabel *Label_Description;
    QPushButton *PushButton_Exit;
    QPushButton *PushButton_PlayNow;
    QPushButton *PushButton_ViewScores;
    User *user;
signals:

public slots:
    void exit();
};

#endif // GAME1WIDGET_H
