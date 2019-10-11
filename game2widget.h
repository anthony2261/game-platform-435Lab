#ifndef GAME2WIDGET_H
#define GAME2WIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

class game2widget :  public QWidget
{
    Q_OBJECT
public:
    explicit game2widget(QWidget *parent = nullptr);
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

#endif // GAME2WIDGET_H
