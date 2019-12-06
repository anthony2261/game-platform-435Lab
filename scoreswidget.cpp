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
                User_Scores = new QString("0");
            } else {
                User_Scores = new QString(inventory_list1[0]);
            }
            Label_Scores->setText(Label_Scores->text() + User_Scores);
//            GridL->addWidget(User_Scores,0,1);
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
        } else {
            if(gID == 2) {
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
                QStringList inventory_list2 = stat_map.value("score2").toStringList();
                if (inventory_list2.size() == 0) {
                    inventory_list2.append("0");
                    User_Scores = new QString("0. Play to get an average score!");
                } else {
                    if(inventory_list2.size() == 1) {
                        User_Scores = new QString("0. Play to get an average score!");
                    } else {
                        int user_avg = 0;
                        for(int i = 1; i <  inventory_list2.size(); i++) {
                            user_avg += inventory_list2[i].toInt();
                        }
                        user_avg = user_avg/(inventory_list2.size()-1);
                        User_Scores = new QString(inventory_list2[0] + ". Your average score: " + QString::number(user_avg));
                    }
                }
                Label_Scores->setText(Label_Scores->text() + User_Scores);
//                GridL->addWidget(User_Scores,0,1);
                ///// now top score
                int top_score = 0;
                int top_avg = 0;
                QString top_user = "Guest";
                for(QVariantMap::const_iterator iter = root_map.begin(); iter != root_map.end(); ++iter) {
    //              qDebug() << iter.key() << iter.value();
                  QVariantMap u_map = root_map.value(iter.key()).toMap();
                  QStringList inventory_list2 = u_map.value("score2").toStringList();
                  if (inventory_list2.size() == 0) {
                      inventory_list2.append("0");
                  } else {
                      if (inventory_list2[0].toInt() > top_score) {
                          top_avg = 0;
                          top_score = inventory_list2[0].toInt();
                          top_user = iter.key();
                          if(inventory_list2.size() > 1) {
                              for(int i = 1; i <  inventory_list2.size(); i++) {
                                  top_avg += inventory_list2[i].toInt();
                              }
                              top_avg = top_avg/(inventory_list2.size()-1);
                          }
                      }
                  }
                }
                Top_Score = new QLabel(" Top score: " + QString::number(top_score) + " with average points: " + QString::number(top_avg) + ". Top User: " + top_user);
                GridL->addWidget(Top_Score,1,0);

            }
        }
    } else {
        Label_Scores = new QLabel("Login to view scores");
    }

    PushButton_Exit = new QPushButton("Exit");
    GridL->addWidget(Label_Scores,0,0);
    GridL->addWidget(PushButton_Exit,4,0);
    VerticalL->addItem(GridL);
    setLayout(VerticalL);
    QObject::connect(PushButton_Exit, SIGNAL(clicked(bool)), this, SLOT(exit()));
}

void scoreswidget::exit() {
    this->close();
    gamewidget *gwidget = new gamewidget(nullptr, this->user, this->gID);
    gwidget->show();
}
