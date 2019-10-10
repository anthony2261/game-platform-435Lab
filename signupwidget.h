#ifndef SIGNUPWIDGET_H
#define SIGNUPWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <string>

class signupwidget : public QWidget
{
    Q_OBJECT
public:
    signupwidget(QWidget *parent = nullptr);
private:

    QGridLayout *GridL;
    QLabel *Label_Status;
    QLabel *Label_firstname;
    QLabel *Label_lastname;
    QLabel *Label_username;
    QLabel *Label_password;
    QLabel *Label_Already;
    QLabel *Label_dob;
    QLineEdit *LineEdit_username;
    QLineEdit *LineEdit_password;
    QLineEdit *LineEdit_firstname;
    QLineEdit *LineEdit_lastname;

    QDateEdit *DateEdit;
    QDate *mindate;
    QString *format;

    QLabel *genderLabel;
    QRadioButton *maleRadio;
    QRadioButton *femaleRadio;
    QGroupBox *groupBox;
    QVBoxLayout *VgroupLayout;

    QImage  *imageObject;
    QPixmap image;
    QPushButton *PushButton_UploadImg;
    QPushButton *PushButton_Enter;
    QPushButton *PushButton_SignIn;

public slots:
    void create_user();

    void uploadimg();

    void signin();
};

#endif // SIGNUPWIDGET_H
