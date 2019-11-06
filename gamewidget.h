#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "user.h"


/**
  * \file gamewidget.h
  * \brief Contains the gamewidget class (game menu page)
  */

/**
 * @brief The gamewidget displays the game description and has 3 buttons: "Play Now" to starts the game,"View Scores" to
 * the scores widget and "Exit" to go back to the logged widget.
 *
 */

class gamewidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief gamewidget Constructor
     * @param user User that logged in (Even if Guest)
     * @param gID Id of the selected game
     */
        explicit gamewidget(QWidget *parent = nullptr, User *user = new User(nullptr, "Guest", "Guest"), int gID = 1);
private:
    QVBoxLayout *VerticalL;
    QGridLayout *GridL;
    QLabel *Label_Description;
    QPushButton *PushButton_Exit;
    QPushButton *PushButton_PlayNow;
    QPushButton *PushButton_ViewScores;
    User *user;
    int gID;
signals:

public slots:
    void play();
    /**
     * @brief go back to the loggedwidget
     */
    void exit();
    /**
     * @brief go to the scoreswidget
     */
    void view_scores();
};

#endif // GAMEWIDGET_H
