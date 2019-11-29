#ifndef SUCCEED_H
#define SUCCEED_H

#include <QWidget>

class succeed : public QWidget
{
    Q_OBJECT
public:
    explicit succeed(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // SUCCEED_H
