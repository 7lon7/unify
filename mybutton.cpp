#include "mybutton.h"
#include <QPushButton>
#include "QPainter"

mybutton::mybutton(QWidget *parent) : QPushButton(parent)
{

    i=0;
    QPixmap pix;
    pix.load("://image/1177006.png");
    this->setIcon(pix);
    this->setIconSize(QSize(70,70));
}
void mybutton::turn()
{
    QPixmap pix1,pix2;
    pix1.load("://image/1177003.png");
    pix2.load("://image/1177006.png");
    if(i==0)
    {
        this->setIcon(pix1);
        this->setIconSize(QSize(70,70));
        i=1;
    }
    else
    {
        this->setIcon(pix2);
        this->setIconSize(QSize(70,70));
        i=0;
    }
}
