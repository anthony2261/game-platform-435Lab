#ifndef LOGGEDWIDGET_H
#define LOGGEDWIDGET_H

#include <QWidget>
#include <QtWidgets>

class loggedwidget:public QWidget
{
    Q_OBJECT
public:
    explicit loggedwidget(QWidget *parent = nullptr,QString="");

private:
    QGridLayout *GridL;
    QLabel *Label_username;
    QLabel *Label_profilepic;
    QImage *inputImg;
    QPushButton *PushButton_Game1;
    QPushButton *PushButton_Game2;
};

#endif // LOGGEDWIDGET_H
