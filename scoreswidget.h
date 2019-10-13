#ifndef SCORESWIDGET_H
#define SCORESWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "user.h"

class scoreswidget:public QWidget
{
    Q_OBJECT
public:
    explicit scoreswidget(QWidget *parent = nullptr, User *user = new User(nullptr, "Guest", "Guest"), int gID = 1);
private:
    QVBoxLayout *VerticalL;
    QGridLayout *GridL;
    QLabel *Label_Scores;
    QPushButton *PushButton_Exit;
    User *user;
    int gID;
signals:

public slots:
    void exit();
};



#endif // SCORESWIDGET_H
