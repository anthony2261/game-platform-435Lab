#include "mainwidget.h"
#include "loggedwidget.h"
#include "user.h"

mainwidget::mainwidget(QWidget *parent) : QWidget(parent)
{
    GridL = new QGridLayout;
    Label_username = new QLabel("Username");
    Label_password = new QLabel("Password");
    Label_NoAccount = new QLabel("Dont have an account?");
    Label_invalidAccount = new QLabel("");
    Label_invalidAccount->hide();
    LineEdit_username = new QLineEdit();
    LineEdit_password = new QLineEdit();
    LineEdit_password->setEchoMode(QLineEdit::Password);
    PushButton_Enter = new QPushButton("SignIn");
    PushButton_Guest = new QPushButton("SignIn as guest");
    PushButton_Signup = new QPushButton("SignUp");
    GridL->addWidget(Label_username,0,0);
    GridL->addWidget(Label_password,1,0);
    GridL->addWidget(LineEdit_username,0,1);
    GridL->addWidget(LineEdit_password,1,1);
    GridL->addWidget(PushButton_Enter,2,0);
    GridL->addWidget(PushButton_Guest,2,1);
    GridL->addWidget(Label_NoAccount,3,0);
    GridL->addWidget(PushButton_Signup,3,1);
    GridL->addWidget(Label_invalidAccount,4,0);
    setLayout(GridL);
    swidget = new signupwidget();
    QObject::connect(PushButton_Enter, SIGNAL(clicked(bool)), this, SLOT(signin()));
    QObject::connect(PushButton_Guest, SIGNAL(clicked(bool)), this, SLOT(signin_guest()));
    QObject::connect(PushButton_Signup, SIGNAL(clicked(bool)), this, SLOT(signup()));
}

void mainwidget::signin() {
    QString username = LineEdit_username->text();
    QString password = LineEdit_password->text();

    QString val;
    QFile file;
    file.setFileName("/home/eece435l/project_ja_9/users/users.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();

//    QVariantList inv_list = root_map["inventory"].toList();
//    qWarning() << stat_map.value("password").toString();
//    QJsonValue value = sett2.value(username);
//    QJsonValue value = sett2["anthony2261"];
//    qWarning() << value.toString();
//    qWarning() << value;

    if(sett2.value(username).isUndefined() ) {
        Label_invalidAccount->show();
        Label_invalidAccount->setText("Invalid Username or Password");
    } else {
        QVariantMap root_map = sett2.toVariantMap();
        QVariantMap stat_map = root_map.value(username).toMap();
        QString pass = stat_map.value("password").toString();

        if (pass.compare(password) != 0) {
            Label_invalidAccount->show();
            Label_invalidAccount->setText("Invalid Username or Password");
        } else {
            // create new user here
            User *user = new User(nullptr, username, stat_map.value("fname").toString(), stat_map.value("lname").toString(), stat_map.value("dob").toString(), stat_map.value("gender").toString());
            this->close();
            loggedwidget *lwidget = new loggedwidget(nullptr, user);
            lwidget->show();
        }
    }
}

void mainwidget::signin_guest(){
    this->close();
    User *guest = new User(nullptr, "Guest", "Guest");
    loggedwidget *lwidget = new loggedwidget(nullptr, guest);
    lwidget->show();
}

void mainwidget::signup(){
    this->close();
    swidget->show();
}

