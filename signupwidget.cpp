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

    QString fname = LineEdit_firstname->text();
    QString lname = LineEdit_lastname->text();
    bool onlyLetters = true;
    for ( const auto& character: fname ) {
        if (!character.isLetter()) {
            onlyLetters = false;
            break;
        }
    }
    for ( const auto& character: lname ) {
        if (!character.isLetter()) {
            onlyLetters = false;
            break;
        }
    }
    if (!onlyLetters) {
        Label_Status->show();
        Label_Status->setText("First Name and Last Name can only be alphabetic.");
    } else {
        QString val;
        QFile file;
        file.setFileName("/home/eece435l/project_ja_9/users/users.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        file.close();
        QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
        QJsonObject sett2 = d.object();

        QString uname = LineEdit_username->text();
        QJsonValue value = sett2.value(uname);

        qWarning() << uname;
        qWarning() << value.toString();
        if(uname.isEmpty() || uname.length() < 4) {
            Label_Status->show();
            Label_Status->setText("Username  must be at least 4 characters long");
        } else {
            if(!sett2.value(uname).isUndefined()) {
                Label_Status->show();
                Label_Status->setText("Username  already taken");
            } else {

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
                    //    sett2["test2"] = "also worked again!";
                    //    if (!file.open(QIODevice::WriteOnly)) {
                    //            qWarning("Couldn't open save file.");
                    //            return false;
                    //        }

                    //    QJsonDocument saveDoc(sett2);
                    //    QString json_string = saveDoc.toJson();
                    //    file.write(json_string.toLocal8Bit());
                    //    file.close();
                }

                else {
                    valid_password = false;
                    Label_Status->show();
                    Label_Status->setText("Invalid Password");
                }
            }
        }
    }
 }

void signupwidget::signin(){
    this->close();
    mainwidget *widget = new mainwidget();
    widget->show();
}
