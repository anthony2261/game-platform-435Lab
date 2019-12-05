#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsPixmapItem>

/**
  * \file snake.h
  * \brief Contains the snake class
  */

/**
 * @brief Contains all the information about the coordinates of a snake in the "snakes and ladders" game.
 */

class snake : public QObject, public QGraphicsPixmapItem
{
public:

    /**
     * @brief snake
     * @param bx int x coordinate of snake's bottom square
     * @param by int y coordinate of snake's bottom square
     * @param tx int x coordinate of snake's top square
     * @param ty int y coordinate of snake's top square
     */
    snake(int bx = 200, int by = 200, int tx = 200, int ty = 200);
    int bx;
    int by;
    int tx;
    int ty;
};

#endif // SNAKE_H
