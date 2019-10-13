#ifndef USER_H
#define USER_H

#include <QObject>

/**
  * \file user.h
  * \brief Contains the user class
  */

/**
 * @brief Contains all the information about an account except for its game scores.
 */

class User : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief User
     * @param uname QString Username
     * @param fname QString First Name
     * @param lname QString Last Name
     * @param dobirth QString Date Of Birth
     * @param gend QString Gender
     */
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
