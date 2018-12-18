#ifndef UPPILLER_H
#define UPPILLER_H
#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>

class upPillar: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
    QPixmap* upPipe = nullptr;
public:
    upPillar(unsigned = 0, int = 0 );
    qreal getXCoordinate();
    qreal getYCoordinate();
public slots:
    void move();
};

#endif // UPPILLER_H
