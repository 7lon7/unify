#include "widget.h"
#include "ui_widget.h"
#include "mybutton.h"
#include "level.h"
#include "choose_level.h"
#include "QPainter"
#include "QDebug"
#include "QMediaPlayer"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(320,350);
    setWindowTitle("主界面");
    QMediaPlayer * player=new QMediaPlayer(this);
    player->setMedia(QUrl("https://music.163.com/#/my/m/music/playlist?id=422935577"));
    player->setVolume(50);
    player->play();
    QPushButton * btn=new QPushButton(this);
    QPixmap pix;
    btn->setStyleSheet("QPushButton{border:0px;}");
    pix.load("://image/1229008.png");
    btn->setIcon(pix);
    btn->resize(100,100);
    btn->move(40,110);
    btn->setIconSize(QSize(100,100));
    connect(btn,&QPushButton::clicked,[=](){
        this->hide();
        choose_level * s=new choose_level();
        s->show();
        connect(s,&choose_level::rewidget,[=](){
            this->show();
        });
    });
    QPushButton * quit=new QPushButton(this);
    quit->move(180,110);
    QPixmap pix1;
    pix1.load("://image/1229009.png");
    quit->setStyleSheet("QPushButton{border:0px;}");
    quit->setIcon(pix1);
    quit->resize(100,100);
    quit->setIconSize(QSize(100,100));
    connect(quit,&QPushButton::clicked,[=](){
        this->close();
    });
}
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("://image/b443c1cec3fdfc0351c3a990d93f8794a5c2269a.png");
    pix=pix.scaled(this->width(),this->height());
    painter.drawPixmap(0,0,pix);
}
Widget::~Widget()
{
    delete ui;
}
