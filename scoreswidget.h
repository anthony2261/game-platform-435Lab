#ifndef SCORESWIDGET_H
#define SCORESWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "user.h"

/**
  * \file scoreswidget.h
  * \brief Contains the score class (history of scores page)
  */

/**
 * @brief The scoreswidget displays the history of the scores of the selected game of the user and has an "Exit"
 * button to go back to the gamewidget. Guests need to log in to view scores.
 *
 */
class scoreswidget:public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief scoreswidget Constructor
     * @param user User that logged in (Even if Guest)
     * @param gID Id of the selected game
     */
    explicit scoreswidget(QWidget *parent = nullptr, User *user = new User(nullptr, "Guest", "Guest"), int gID = 1);
private:
    QVBoxLayout *VerticalL;
    QGridLayout *GridL;
    QLabel *Label_Scores;
    QString *User_Scores;
    QLabel *Avg_User_Scores;
    QLabel *Top_Score;
    QPushButton *PushButton_Exit;
    User *user;
    int gID;
signals:

public slots:
    /**
     * @brief go back to the gamewidget.
     */
    void exit();
};



#endif // SCORESWIDGET_H
