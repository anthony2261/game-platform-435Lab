#ifndef SQUARE_H
#define SQUARE_H

#include <QtWidgets>
#include <QWidget>

class Square : public QWidget
{
    Q_OBJECT
public:
    explicit Square(QWidget *parent = nullptr, int num = 1);

private:
    QGridLayout *GridL; //!< Grid
    QLabel *Label_number;

signals:

public slots:
};

#endif // SQUARE_H
