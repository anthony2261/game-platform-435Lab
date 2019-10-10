#include "mainwidget.h"
#include "signupwidget.h"


signupwidget::signupwidget(QWidget *parent) : QWidget(parent)
{
    GridL = new QGridLayout;
    Label_Status = new QLabel("");
    Label_Status->hide();
    Label_firstname = new QLabel("First Name");
    Label_lastname = new QLabel("Last Name");
    Label_username = new QLabel("Username");
    Label_password = new QLabel("Password");
    Label_Already = new QLabel("Already have an account?");
    LineEdit_username = new QLineEdit();
    LineEdit_password = new QLineEdit();
    LineEdit_firstname = new QLineEdit();
    LineEdit_lastname= new QLineEdit();
    LineEdit_password->setEchoMode(QLineEdit::Password);
    PushButton_Enter = new QPushButton("Enter");
    PushButton_SignIn = new QPushButton("SignIn");
    GridL->addWidget(Label_firstname,0,0);
    GridL->addWidget(Label_lastname,1,0);
    GridL->addWidget(Label_username,2,0);
    GridL->addWidget(Label_password,3,0);
    GridL->addWidget(LineEdit_firstname,0,1);
    GridL->addWidget(LineEdit_lastname,1,1);
    GridL->addWidget(LineEdit_username,2,1);
    GridL->addWidget(LineEdit_password,3,1);
    GridL->addWidget(PushButton_Enter,4,0);
    GridL->addWidget(Label_Already,5,0);
    GridL->addWidget(PushButton_SignIn,5,1);
    GridL->addWidget(Label_Status,6,0);
    setLayout(GridL);
    QObject::connect(PushButton_Enter, SIGNAL(clicked(bool)), this, SLOT(create_user()));
    QObject::connect(PushButton_SignIn, SIGNAL(clicked(bool)), this, SLOT(signin()));
}

void signupwidget::create_user() {
    bool valid_password;
    QString Password = LineEdit_password->text();
    bool contains_upper = false;
    bool contains_lower = false;
    bool contains_digit = false;

    for ( const auto& character : Password )
    {
        if ( character.isUpper() )
             contains_upper= true;
        else if ( character.isLower() )
             contains_lower = true;
        else if ( character.isDigit() )
             contains_digit = true;
     }

    if (Password.length() >= 8 && contains_digit && contains_lower && contains_upper){
        Label_Status->clear();
        valid_password = true;
    }

    else {
        valid_password = false;
        Label_Status->show();
        Label_Status->setText("Invalid Password");
    }

 }

void signupwidget::signin(){
    this->close();
    mainwidget *widget = new mainwidget();
    widget->show();
}
