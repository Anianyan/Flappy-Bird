#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QDebug>
#include <QFont>
#include <QImage>
#include "player.h"

class Game: public QGraphicsView {
public:
    Game(QWidget * parent = nullptr);

    QGraphicsScene * scene;
    Player * player;
};

#endif // GAME_H
