#include "scoreswidget.h"
#include "gamewidget.h"

scoreswidget::scoreswidget(QWidget *parent, User *user, int gID) : QWidget(parent)
{
    this->gID = gID;
    VerticalL = new QVBoxLayout;
    GridL = new QGridLayout;
    this->user = user;
    if(user->username != "Guest") {
        Label_Scores = new QLabel(user->username + "'s score:");
        if(gID == 1) {
            QString val;
            QFile file;
            file.setFileName("/home/eece435l/project_ja_9/users/users.json");
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            val = file.readAll();
            file.close();
            QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
            QJsonObject sett2 = d.object();

            QVariantMap root_map = sett2.toVariantMap();
            QVariantMap stat_map = root_map.value(user->username).toMap();
            QStringList inventory_list1 = stat_map.value("score1").toStringList();
            if (inventory_list1.size() == 0) {
                inventory_list1.append("0");
                User_Scores = new QLabel("0");
            } else {
                User_Scores = new QLabel(inventory_list1[0]);
            }
            GridL->addWidget(User_Scores,0,1);
            ///// now top score
            int top_score = 0;
            QString top_user = "Guest";
            for(QVariantMap::const_iterator iter = root_map.begin(); iter != root_map.end(); ++iter) {
//              qDebug() << iter.key() << iter.value();
              QVariantMap u_map = root_map.value(iter.key()).toMap();
              QStringList inventory_list1 = u_map.value("score1").toStringList();
              if (inventory_list1.size() == 0) {
                  inventory_list1.append("0");
              } else {
                  if (inventory_list1[0].toInt() > top_score) {
                      top_score = inventory_list1[0].toInt();
                      top_user = iter.key();
                  }
              }
            }
            Top_Score = new QLabel(" Top score: " + QString::number(top_score) + ". Top User: " + top_user);
            GridL->addWidget(Top_Score,1,0);
        }
    } else {
        Label_Scores = new QLabel("Login to view scores");
    }

    PushButton_Exit = new QPushButton("Exit");
    GridL->addWidget(Label_Scores,0,0);
    GridL->addWidget(PushButton_Exit,2,0);
    VerticalL->addItem(GridL);
    setLayout(VerticalL);
    QObject::connect(PushButton_Exit, SIGNAL(clicked(bool)), this, SLOT(exit()));
}

void scoreswidget::exit() {
    this->close();
    gamewidget *gwidget = new gamewidget(nullptr, this->user, this->gID);
    gwidget->show();
}
