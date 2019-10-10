#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include "signupwidget.h"

class mainwidget : public QWidget
{
    Q_OBJECT
public:
    explicit mainwidget(QWidget *parent = nullptr);
private:
    QGridLayout *GridL;
    QLabel *Label_username;
    QLabel *Label_password;
    QLabel *Label_NoAccount;
    QLineEdit *LineEdit_username;
    QLineEdit *LineEdit_password;
    QPushButton *PushButton_Enter;
    QPushButton *PushButton_Guest;
    QPushButton *PushButton_Signup;
    signupwidget *swidget;
signals:

public slots:
    void signin();
    void signin_guest();
    void signup();
};

#endif // MAINWIDGET_H
