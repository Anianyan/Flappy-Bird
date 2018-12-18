#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include <QTimer>
#include "downPillar.h"
#include "uppillar.h"


class Player: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
    unsigned velocity;
    unsigned distance; // between two pipes
    QPixmap * bird = nullptr;
    downPillar * downpillar = nullptr;
    upPillar * uppillar = nullptr;
public:
    Player( QGraphicsPixmapItem * parent = nullptr );
    void keyPressEvent(QKeyEvent * event);
    bool isCollision();
public slots:
    void move();
    void spawn();
};

#endif // PLAYER_H
