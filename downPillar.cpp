#include "downPillar.h"
#include <QDebug>

downPillar::downPillar(int ypos): QObject (), QGraphicsPixmapItem () {

    setPos(385, ypos);

    pillar = new QPixmap(":/images/down.png");

    setPixmap( *pillar );

    //move pillar in fix time
    QTimer * timer = new QTimer();
    connect( timer, SIGNAL(timeout()), this, SLOT(move()) );

    timer->start(60);
}

qreal downPillar::getYCoordinate()
{
    //get pillar left-down coordinate
    return pos().y() + pillar->height();
}

void downPillar::move() {
    setPos(x() - 5, y());
}
