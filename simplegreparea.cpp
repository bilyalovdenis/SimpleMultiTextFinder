#include "simplegreparea.h"

SimpleGrepArea::SimpleGrepArea(QWidget *parent):QObject(parent)
{
    area_ = new QFrame(parent);
    toolbar_ = new QToolBar(area_);
    status_bar_ = new QLabel(area_);
}
void SimpleGrepArea::init(){
    initialization_components();
    desing_area();
    desing_main_view();
    desing_status_bar();
    desing_toolbar();
    make_connections();
}
