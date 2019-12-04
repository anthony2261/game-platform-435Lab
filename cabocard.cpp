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

CaboCard::CaboCard(int number, bool faceup)
{
//    this->setFlag(QGraphicsItem::ItemIsSelectable,true);
    this->number = number;
    this->faceup = faceup;
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

void CaboCard::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
//    QMessageBox::information(NULL, "Information!", "Mouse release Detected!");
  }
