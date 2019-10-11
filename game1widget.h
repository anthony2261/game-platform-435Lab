#ifndef GAME1WIDGET_H
#define GAME1WIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

class Game1Widget:public QWidget
{
    Q_OBJECT
public:
    explicit Game1Widget(QWidget *parent = nullptr);
private:
    QVBoxLayout *VerticalL;
    QGridLayout *GridL;
    QLabel *Label_Description;
    QPushButton *PushButton_Exit;
    QPushButton *PushButton_PlayNow;
    QPushButton *PushButton_ViewScores;
signals:

public slots:
    void exit();
};

#endif // GAME1WIDGET_H
