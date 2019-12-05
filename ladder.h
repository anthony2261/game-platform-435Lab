#ifndef LADDER_H
#define LADDER_H

#include <QObject>
#include <QWidget>
#include <QGraphicsPixmapItem>

/**
  * \file ladder.h
  * \brief Contains the ladder class
  */

/**
 * @brief Contains all the information about the coordinates of a ladder in the "snakes and ladders" game.
 */

class ladder : public QObject, public QGraphicsPixmapItem
{
public:
    /**
     * @brief ladder
     * @param bx int x coordinate of ladder's bottom square
     * @param by int y coordinate of ladder's bottom square
     * @param tx int x coordinate of ladder's top square
     * @param ty int y coordinate of ladder's top square
     */
    ladder(int bx = 200, int by = 200, int tx = 200, int ty = 200);

    int bx;
    int by;
    int tx;
    int ty;
};

#endif // LADDER_H
