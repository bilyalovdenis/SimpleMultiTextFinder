#include "textviewerarea.h"

//*---Public---*//
TextViewerArea::TextViewerArea(QWidget *parent):SimpleGrepArea(parent)
{
    init();
}

//*---Slots---*//
void TextViewerArea::next(){
    //TODO....
    qDebug() << "next"<<'\n';
}
void TextViewerArea::previous(){
    //TODO.....
    qDebug() << "previous"<<'\n';
}

//*---Private---*//
void TextViewerArea::initialization_components()
{
    text_viewer_ = new QTextEdit(area_);
    next_=new QAction(area_);
    previous_=new QAction(area_);
}
void TextViewerArea::desing_area()
{
    auto area_layout = new QVBoxLayout(area_);
    area_->setLayout(area_layout);
    area_layout->addWidget(toolbar_);
    area_layout->addWidget(status_bar_);
    area_layout->addWidget(text_viewer_);

    area_->setFrameShadow(QFrame::Raised);
    area_->setFrameShape(QFrame::StyledPanel);
    area_->setMidLineWidth(3);
    area_->setLineWidth(3);
}
void TextViewerArea::desing_main_view()
{
    text_viewer_->setReadOnly(true);
    QFile file (":/res/test.txt");

    if(!file.exists()){
       // qDebug() << "No existe file";
    }
    else{
        //qDebug() << "File exist";
    }
 //   struct rusage r;
//    getrusage(RUSAGE_SELF, &r);
//    qDebug() << "PreROM: " <<r.ru_maxrss;
    QString line;
    text_viewer_->clear();
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
       line = stream.readAll();
    }
    text_viewer_->setText(line);
    file.close();
}
void TextViewerArea::desing_status_bar()
{
    status_bar_->setText("Show");
}
void TextViewerArea::desing_toolbar()
{
    next_->setText("Следущее");
    toolbar_->addAction(next_);

    previous_->setText("ПредЪидущяя");
    toolbar_->addAction(previous_);
}
void TextViewerArea::make_connections()
{
    connect (next_,     &QAction::triggered,
             this,      &TextViewerArea::next);
    connect (previous_, &QAction::triggered,
             this,      &TextViewerArea::previous);
}
