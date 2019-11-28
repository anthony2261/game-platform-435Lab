#include "cabocard.h"

//CaboCard::CaboCard()
//{
//    int number = rand() % 14;
//    this->number = number;
//    if(number < 7 || number == 13) {
//        this->choice = "none";
//    } else {
//        if(number < 9) {
//            this->choice = "peek";
//        } else {
//            if(number < 11) {
//                this->choice = "spy";
//            } else {
//                this->choice = "swap";
//            }
//        }
//    }
//}

CaboCard::CaboCard(int number)
{
    pixmap = new QGraphicsPixmapItem();
    pixmap->setPixmap((QPixmap(QString("/home/eece435l/project_ja_9/images/cards/card%1.png").arg(number))).scaled(50,150));
    this->number = number;
    if(number < 7 || number == 13) {
        this->choice = "none";
    } else {
        if(number < 9) {
            this->choice = "peek";
        } else {
            if(number < 11) {
                this->choice = "spy";
            } else {
                this->choice = "swap";
            }
        }
    }
}

