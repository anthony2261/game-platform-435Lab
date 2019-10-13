#include <QApplication>
#include "mainwidget.h"
#include "signupwidget.h"

/**
 * \mainpage Project_ja_9
 * \authors Anthony Malkoun, Joseph Sabbagh
 * \date 13-10-2019
 * \brief Launch the application to play games with your own personal account!
 */

int main(int argc, char **argv)
{
QApplication app (argc, argv);
mainwidget widget;
widget.show();
return app.exec();
}
