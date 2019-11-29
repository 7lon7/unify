#include "succeed.h"
#include "QPushButton"
#include "QTextEdit"
#include "QPainter"
#include "QLabel"

succeed::succeed(QWidget *parent) : QWidget(parent)
{
    resize(320,350);
    setWindowTitle("SUCCEED!");
    QLabel * label=new QLabel(this);
    QPixmap pix;
    pix.load("://image/success_500px_1201384_easyicon.net.png");
    label->move(110,120);
    label->resize(100,100);
    label->setPixmap(pix);
    label->setScaledContents(true);
}
void succeed::paintEvent(QPaintEvent *)
{
    QPixmap pix;
    pix.load("://image/b443c1cec3fdfc0351c3a990d93f8794a5c2269a.png");
    QPainter painter(this);
    painter.drawPixmap(0,0,pix);
}
