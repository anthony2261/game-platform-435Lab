#include "mainwidget.h"

mainwidget::mainwidget(QWidget *parent) : QWidget(parent)
{
    GridL = new QGridLayout;
    Label_username = new QLabel("Username");
    Label_password = new QLabel("Password");
    Label_NoAccount = new QLabel("Dont have an account?");
    LineEdit_username = new QLineEdit();
    LineEdit_password = new QLineEdit();
    LineEdit_password->setEchoMode(QLineEdit::Password);
    PushButton_Enter = new QPushButton("Enter");
    PushButton_Signup = new QPushButton("SignUp");
    GridL->addWidget(Label_username,0,0);
    GridL->addWidget(Label_password,1,0);
    GridL->addWidget(LineEdit_username,0,1);
    GridL->addWidget(LineEdit_password,1,1);
    GridL->addWidget(PushButton_Enter,2,0);
    GridL->addWidget(Label_NoAccount,3,0);
    GridL->addWidget(PushButton_Signup,3,1);
    setLayout(GridL);
    swidget = new signupwidget();
    QObject::connect(PushButton_Enter, SIGNAL(clicked(bool)), this, SLOT(signin()));
    QObject::connect(PushButton_Signup, SIGNAL(clicked(bool)), this, SLOT(signup()));
}

void mainwidget::signin() {
    QString username = LineEdit_username->text();
    QString password = LineEdit_password->text();
}

void mainwidget::signup(){
    this->close();
    swidget->show();
}

