#include "uppillar.h"
#include <QImage>
#include <QPixmap>
#include <QDebug>

upPillar::upPillar(unsigned distance, int ypos): QObject (), QGraphicsPixmapItem () {
    upPipe = new QPixmap(":/images/up.png");
    setPos(385, upPipe->height() + ypos + distance);

    setPixmap(*upPipe);

    //move pillar in fix time
    QTimer * timer = new QTimer();
    connect( timer, SIGNAL(timeout()), this, SLOT(move()) );

    timer->start(60);
}

qreal upPillar::getXCoordinate()
{
    return pos().x();
}

qreal upPillar::getYCoordinate()
{
    return pos().y();
}

void upPillar::move() {
    setPos(x() - 5, y());
}
