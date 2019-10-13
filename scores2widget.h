#ifndef SCORES2WIDGET_H
#define SCORES2WIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "user.h"

class scores2widget:public QWidget
{
    Q_OBJECT
public:
    explicit scores2widget(QWidget *parent = nullptr, User *user = new User(nullptr, "Guest", "Guest"));
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

#endif // SCORES2WIDGET_H
