#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "user.h"

class gamewidget : public QWidget
{
    Q_OBJECT
public:
        explicit gamewidget(QWidget *parent = nullptr, User *user = new User(nullptr, "Guest", "Guest"), int gID = 1);
private:
    QVBoxLayout *VerticalL;
    QGridLayout *GridL;
    QLabel *Label_Description;
    QPushButton *PushButton_Exit;
    QPushButton *PushButton_PlayNow;
    QPushButton *PushButton_ViewScores;
    User *user;
    int gID;
signals:

public slots:
    void exit();
    void view_scores();
};

#endif // GAMEWIDGET_H
