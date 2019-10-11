#ifndef USER_H
#define USER_H

#include <QObject>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr, QString uname ="", QString fname ="", QString lname ="", QString dobirth = "", QString gend = "");

    QString username;
    QString firstname;
    QString lastname;
    QString dob;
    QString gender;

signals:

public slots:
};

#endif // USER_H
