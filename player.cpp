#include "player.h"
#include "game.h"
#include <QDebug>

extern Game * game;

Player::Player(QGraphicsPixmapItem *parent):QGraphicsPixmapItem (parent)
{
    //set speed for Bird
    velocity = 1;
    //set dinstance two pipes
    distance = 100;
    //draw image Bird(Player)
    bird = new QPixmap( ":/images/player.png" );
    setPixmap( *bird );

    QTimer * timer = new  QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()) );

    timer->start( 50 / velocity );

}

void Player::keyPressEvent(QKeyEvent *event)
{
    if ( event->key() == Qt::Key_Space ) {
        setPos(x(),y() - 18 );
        if( isCollision() ) {
            scene()->removeItem(this);
            delete(this);
            qDebug() << "Game Over";
        }

    }
}

bool Player::isCollision()
{
    if ( uppillar != nullptr ) {
        if( ( x() + bird->width() ) > uppillar->getXCoordinate() ) {
            if( ( y() + bird->height() ) < uppillar->getYCoordinate() && y() > downpillar->getYCoordinate() ) {
                return false;
            } else if( bird->height() < uppillar->getYCoordinate() || bird->height() >= downpillar->getYCoordinate() ) {
                return true;
            }
            return true;
        }
    }
    return false;
}

void Player::move()
{
    //move bird diagonal
    setPos(x(),y() + 3);

    // check for game over
    if( pos().y() > 448 || pos().x() > 385 || isCollision()  ) {
        scene()->removeItem(this);
        delete(this);
         qDebug() << "gameOver";
        //QPixmap * gameOver = new QPixmap(":/images/gameover.png");
        qDebug() << "setPixmap";
        //gameOver->setPixmap(*gameOver);
        qDebug() << "Game Over";
    }
}

void Player::spawn()
{
    //generate random number for y() position
    srand (time(nullptr));
    int ypos = 0 - rand() % 151;

    //create down Pillar
    downpillar = new downPillar(ypos);
    scene()->addItem(downpillar);

    //create up pillar
    uppillar = new upPillar(distance, ypos);
    scene()->addItem(uppillar);
}
