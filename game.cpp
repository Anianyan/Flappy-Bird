#include <game.h>

Game::Game(QWidget * parent) {


    //Create the scene with background Image
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,385,448);
    setBackgroundBrush(QBrush(QImage(":/images/day.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(385,448);

    //Create the Player
    player = new Player();
    player->setPos(192,224);
    // make the player focusable and set it to be the current focus
    //for keyPress event
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    //spawn pillar
    QTimer * timer = new QTimer();
    QObject::connect( timer,SIGNAL(timeout()), player, SLOT(spawn()) );
    timer->start(2000);

    show();
}
