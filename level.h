#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>
#include <mybutton.h>

class level : public QWidget
{
    Q_OBJECT
public:
    //explicit level(int x,int y,QWidget *parent = nullptr);
    level(int x[],int n);
    typedef mybutton * btnp;
    btnp a[4][4];
    void timerEvent(QTimerEvent *);
    void paintEvent(QPaintEvent *);
    //QPushButton * succeed;
    QWidget w;
    int id;
signals:
    void rechoose();
public slots:
};

#endif // LEVEL_H
