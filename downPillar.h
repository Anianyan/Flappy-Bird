#ifndef PILLAR_H
#define PILLAR_H
#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>

class downPillar: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
    QPixmap *pillar;
public:
    downPillar(int);
    qreal getYCoordinate();
public slots:
    void move();
};

#endif // PILLAR_H
