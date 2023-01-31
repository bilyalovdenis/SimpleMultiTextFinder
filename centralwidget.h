#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QObject>

class CentralWidget
{
public:
    CentralWidget(QWidget *widget);
private:
    QWidget *this_;
};

#endif // CENTRALWIDGET_H
