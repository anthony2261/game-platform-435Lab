#ifndef SCORES1WIDGET_H
#define SCORES1WIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "user.h"

class scores1widget:public QWidget
{
    Q_OBJECT
public:
    explicit scores1widget(QWidget *parent = nullptr, User *user = new User(nullptr, "Guest", "Guest"));
private:
    QVBoxLayout *VerticalL;
    QGridLayout *GridL;
    QLabel *Label_Scores;
    QPushButton *PushButton_Exit;
    User *user;
signals:

public slots:
    void exit();
};

#endif // SCORES1WIDGET_H
