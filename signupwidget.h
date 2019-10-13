#ifndef SIGNUPWIDGET_H
#define SIGNUPWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <string>

/**
  * \file signupwidget.h
  * \brief Contains the signupwidget class (sign up page)
  */

/**
 * @brief The signupwidget allows for creation of new accounts
 */

class signupwidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief generates the signupwidget
     */
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
    QString imagePath;
    QPushButton *PushButton_UploadImg;
    QPushButton *PushButton_Enter;
    QPushButton *PushButton_SignIn;

public slots:
    /**
     * @brief create the user
     *
     * First, multiple checks are run:
     * The first and last names must be alphabetical and not null.
     * The username must be at least 4 characters long.
     * The username must not be taken
     * The password must be at least 8 characters long, must contain at least one uppercase letter, one lowercase letter, and one number.
     * If a check fails, a message is shown via a QLabel showing which rule was not followed.
     *
     * The user is not required to upload an image as profile picture.
     * If all checks pass, the data is collected from the sign up form and added to the database (users.json). If a picture was uploaded, the picture is saved in the "pictures" folder and renamed as "<username>.jpg". The message "User created" is shown.
     * Two empty arrays, each representing scores for a game, are also created and added to the user's account.
     *
     */
    void create_user();

    /**
     * @brief upload an img
     *
     * If an image is selected, the imagePath member of this class is set to the path of the image. The actual image is not saved until the user sucessfully creates an account.
     */
    void uploadimg();

    /**
     * @brief Go back to the sign in page (mainwidget)
     */
    void signin();
};

#endif // SIGNUPWIDGET_H
