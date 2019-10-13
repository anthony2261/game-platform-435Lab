#ifndef LOGGEDWIDGET_H
#define LOGGEDWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include "user.h"

/**
  * \file loggedwidget.h
  * \brief Contains the loggedwidget class (main account page)
  */

/**
 * @brief The loggedwidget displays the username, profile picture, and allows the user to play two different games.
 *
 * If it's the account's birthday, username is replaced by "Happy birthday <username>!"
 * If the user signed in with an account that did not upload an image, the default image (batman) is displayed.
 */

class loggedwidget:public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief loggedwidget Constructor
     * @param user User that logged in (Even if Guest)
     */
    explicit loggedwidget(QWidget *parent = nullptr, User *user = new User(nullptr, "Guest", "Guest"));

private:
    QGridLayout *GridL;
    QLabel *Label_username;
    QLabel *Label_profilepic;
    QImage *inputImg;
    QPushButton *PushButton_Game1;
    QPushButton *PushButton_Game2;
    QPushButton *PushButton_Signout;
    User *user;

public slots:
    /**
     * @brief Sign out, and go to the sign in page (mainwidget)
     */
    void signout();

    /**
     * @brief playgame1
     * Goes to Game 1 page
     */
    void playgame1();
    /**
     * @brief playgame2
     * Goes to Game 2 page
     */
    void playgame2();
};

#endif // LOGGEDWIDGET_H
