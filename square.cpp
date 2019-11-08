#include "square.h"
//#include<string>
//using namespace std;

Square::Square(QWidget *parent, int num) : QWidget(parent)
{
    GridL = new QGridLayout;
    Label_number = new QLabel(QString::number(num));
    GridL->addWidget(Label_number,0,0);
//    QRect *rect = new QRect(0,0,300,300);
//    GridL->setGeometry(*rect);
    setLayout(GridL);
}
