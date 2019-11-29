#include "choose_level.h"
#include "level.h"
#include "QPushButton"
#include "QPainter"
#include "QDebug"

choose_level::choose_level(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("选择关卡");
    setFixedSize(320,350);
    level * ss[9];
    int a[9][16];
    a[0][0]=0;
    a[1][0]=1;
    a[2][0]=11;
    a[3][0]=0;a[3][1]=1;
    a[4][0]=11;a[4][1]=10;
    a[5][0]=11;a[5][1]=21;
    a[6][0]=0;a[6][1]=1;a[6][2]=2;
    a[7][0]=0;a[7][1]=11;a[7][2]=22;
    a[8][0]=11;a[8][1]=21;a[8][2]=22;
    int j=0;
    for(int i=0;i<9;i++)
    {
        if(i%3==0)
        {
            j++;
        }
        ss[i]=new level(a[i],j);
    }
    QPushButton * back=new QPushButton(this);
    QPixmap backpix;
    backpix.load("://image/return_981px_1153788_easyicon.net.png");
    back->setStyleSheet("QPushButton{border:0px;}");
    back->setIcon(backpix);
    back->move(280,315);
    back->setIconSize(QSize(30,30));
    connect(back,&QPushButton::clicked,[=](){
        this->hide();
        emit this->rewidget();
    });
    QString s[9];
    s[0]="://image/1168269.png";
    s[1]="://image/1168271.png";
    s[2]="://image/1168273.png";
    s[3]="://image/1168275.png";
    s[4]="://image/1168277.png";
    s[5]="://image/1168279.png";
    s[6]="://image/1168281.png";
    s[7]="://image/1168283.png";
    s[8]="://image/1168285.png";
    QPushButton * btn[9];
    for(int i=0;i<9;i++)
    {
        btn[i]=new QPushButton(this);
        btn[i]->setStyleSheet("QPushButton{border:0px;}");
        btn[i]->resize(60,60);
        btn[i]->move(((i)%3)*95+35,((i)/3)*95+35);
        QPixmap pix;
        pix.load(s[i]);
        btn[i]->setIcon(pix);
        btn[i]->setIconSize(QSize(55,55));
        connect(btn[i],&QPushButton::clicked,[=](){
            this->hide();
            ss[i]->show();
            ss[i]->id=ss[i]->startTimer(1);
            connect(ss[i],&level::rechoose,[=](){
                this->show();
            });
        });
    }
}
void choose_level::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("://image/b443c1cec3fdfc0351c3a990d93f8794a5c2269a.png");
    pix=pix.scaled(this->width(),this->height());
    painter.drawPixmap(0,0,pix);
}
