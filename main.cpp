#include <QApplication>
#include "mainwidget.h"
#include "signupwidget.h"
int main(int argc, char **argv)
{
QApplication app (argc, argv);
mainwidget widget;
widget.show();
return app.exec();
}
