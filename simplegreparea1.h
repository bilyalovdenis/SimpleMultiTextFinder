#ifndef SIMPLEGREPAREA_H
#define SIMPLEGREPAREA_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QAbstractScrollArea>
#include <QLabel>
#include <QToolBar>

class SimpleGrepArea : public QObject
{
public:
    SimpleGrepArea(QWidget *parent = nullptr):QObject(parent){}
    virtual ~SimpleGrepArea(){}

    virtual  QWidget* get_area(){return area_;}
protected:
    QFrame* area_;
    QAbstractScrollArea* main_view_;
    QLabel* status_bar_;
    QToolBar* toolbar_;

    virtual void initialization_components() = 0;
    virtual void desing_area() = 0;
    virtual void desing_main_view() = 0;
    virtual void desing_status_bar() = 0;
    virtual void desing_toolbar() = 0;
};

#endif // SIMPLEGREPAREA_H
