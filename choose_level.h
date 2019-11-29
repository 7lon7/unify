#ifndef CHOOSE_LEVEL_H
#define CHOOSE_LEVEL_H

#include <QWidget>

class choose_level : public QWidget
{
    Q_OBJECT
public:
    explicit choose_level(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
signals:
    void rewidget();
public slots:
};

#endif // CHOOSE_LEVEL_H
