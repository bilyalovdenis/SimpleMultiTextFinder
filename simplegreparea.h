#ifndef SIMPLEGREPAREA_H
#define SIMPLEGREPAREA_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QAbstractScrollArea>
#include <QLabel>
#include <QToolBar>
#include <foundfilesmodel.h>


class SimpleGrepArea : public QObject
{
public:
    SimpleGrepArea(QWidget *parent = nullptr);
    virtual ~SimpleGrepArea(){}

    virtual  QWidget* get_area(){return area_;}
    virtual  QLabel* get_status_bar(){return status_bar_;}
    virtual  QToolBar* get_toolbar(){return toolbar_;};
    virtual  QAbstractScrollArea* get_main_view_() = 0;
protected:
    QFrame* area_;
    QLabel* status_bar_;
    QToolBar* toolbar_;


    virtual void initialization_components() = 0;
    virtual void desing_area() = 0;
    virtual void desing_main_view() = 0;
    virtual void desing_status_bar() = 0;
    virtual void desing_toolbar() = 0;
    virtual void make_connections() = 0;
    void init();
private:

};

#endif // SIMPLEGREPAREA_H
