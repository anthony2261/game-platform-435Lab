#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include "signupwidget.h"

/**
 * \file mainwidget.h
 * \brief Contains the mainwidget class (for logins)
 */

/**
 * \brief The mainwidget allows user to sign in with their account or as a guest and proceed to the "loggedwidget", or to go to the signup page (signupwidget)
 */
class mainwidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * \brief generates the mainwidget
     */
    explicit mainwidget(QWidget *parent = nullptr);
private:
    QGridLayout *GridL; //!< Grid containing all the items
    QLabel *Label_username;
    QLabel *Label_password;
    QLabel *Label_NoAccount;//!< Informing the user that they can sign up
    QLabel *Label_invalidAccount;//!< appears in case the account info inserted was invalid
    QLineEdit *LineEdit_username;
    QLineEdit *LineEdit_password;
    QPushButton *PushButton_Enter;
    QPushButton *PushButton_Guest;
    QPushButton *PushButton_Signup;
    signupwidget *swidget; //!< Jumps to signup widget, might be removed from this class
signals:

public slots:
    /**
     * @brief checks whether inserted user info matches any of the accounts in the users.json database, and signs in in case of a match
     */
    void signin();
    /**
     * @brief Signs in as a guest
     */
    void signin_guest();
    /**
     * @brief To create new accounts, goes to signup widget and closes this one.
     */
    void signup();
};

#endif // MAINWIDGET_H
