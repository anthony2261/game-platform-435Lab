#ifndef USER_H
#define USER_H

#include <QObject>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr, QString u ="", QString f ="", QString l ="");
private:
    QString *username;
    QString *firstname;
    QString *lastname;
    QDate *dob;

signals:

public slots:
};

#endif // USER_H
