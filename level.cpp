#include "level.h"
#include "mybutton.h"
#include "QPainter"
#include "widget.h"
#include "choose_level.h"
#include "QDebug"
#include "succeed.h"

level::level(int x[],int n) : QWidget(nullptr)
{
    setWindowTitle("level");
    setFixedSize(320,350);
    QPushButton * back=new QPushButton(this);
    QPixmap backpix;
    backpix.load("://image/return_981px_1153788_easyicon.net.png");
    back->setStyleSheet("QPushButton{border:0px;}");
    back->setIcon(backpix);
    back->move(280,315);
    back->setIconSize(QSize(30,30));
    connect(back,&QPushButton::clicked,[=](){
        this->hide();
        emit this->rechoose();
    });
    for(int i=0,m=0;i<4;i++,m+=80)
    {
        for(int j=0,n=0;j<4;j++,n+=80)
        {
            a[i][j]=new mybutton(this);
            a[i][j]->move(m,n);
            a[i][j]->resize(80,80);
        }
    }
    for(int i=0;i<n;i++)
    {
        a[x[i]/10][x[i]%10]->i=1;
        a[x[i]/10][x[i]%10]->setStyleSheet("QPushButton{border:0px;}");
        QPixmap pix;
        pix.load("://image/1177003.png");
        a[x[i]/10][x[i]%10]->setIcon(pix);
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            a[i][j]->setStyleSheet("QPushButton{border:0px;}");
            connect(a[i][j],&mybutton::clicked,[=](){
                QPixmap pix1,pix2;
                pix1.load("://image/1177003.png");
                pix2.load("://image/1177006.png");
                a[i][j]->turn();
                if(i-1>=0&&i-1<4)
                {
                    if(a[i-1][j]->i==0)
                    {
                        a[i-1][j]->setIcon(pix1);
                        a[i-1][j]->setIconSize(QSize(70,70));
                        a[i-1][j]->i=1;
                    }
                    else
                    {
                        a[i-1][j]->setIcon(pix2);
                        a[i-1][j]->setIconSize(QSize(70,70));
                        a[i-1][j]->i=0;
                    }
                }
                if(i+1>=0&&i+1<4)
                {
                    if(a[i+1][j]->i==0)
                    {
                        a[i+1][j]->setIcon(pix1);
                        a[i+1][j]->setIconSize(QSize(70,70));
                        a[i+1][j]->i=1;
                    }
                    else
                    {
                        a[i+1][j]->setIcon(pix2);
                        a[i+1][j]->setIconSize(QSize(70,70));
                        a[i+1][j]->i=0;
                    }
                }
                if(j-1>=0&&j-1<4)
                {
                    if(a[i][j-1]->i==0)
                    {
                        a[i][j-1]->setIcon(pix1);
                        a[i][j-1]->setIconSize(QSize(70,70));
                        a[i][j-1]->i=1;
                    }
                    else
                    {
                        a[i][j-1]->setIcon(pix2);
                        a[i][j-1]->setIconSize(QSize(70,70));
                        a[i][j-1]->i=0;
                    }
                }
                if(j+1>=0&&j+1<4)
                {
                    if(a[i][j+1]->i==0)
                    {
                        a[i][j+1]->setIcon(pix1);
                        a[i][j+1]->setIconSize(QSize(70,70));
                        a[i][j+1]->i=1;
                    }
                    else
                    {
                        a[i][j+1]->setIcon(pix2);
                        a[i][j+1]->setIconSize(QSize(70,70));
                        a[i][j+1]->i=0;
                    }
                }
            });
        }
    }
}
void level::paintEvent(QPaintEvent *)
{
    QPixmap pix;
    pix.load("://image/b443c1cec3fdfc0351c3a990d93f8794a5c2269a.png");
    QPainter painter(this);
    painter.drawPixmap(0,0,pix);
}
void level::timerEvent(QTimerEvent *)
{
    int i,j,n=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]->i==1)
            {
                n++;
            }
        }
    }
    if(n==16)
    {
        this->close();
        succeed * sced=new succeed;
        sced->show();
        killTimer(id);
    }
}
