#include "user.h"

User::User(QObject *parent, QString uname, QString fname, QString lname, QString dobirth, QString gend) : QObject(parent)
{
    this->username = uname;
    this->firstname = fname;
    this->lastname= lname;
    this->dob = dobirth;
    this->gender = gend;
}
