#include "foundfilesarea.h"

//*---Public---*//
FoundFilesArea::FoundFilesArea(QWidget *parent, FoundFilesModel *model)
    :SimpleGrepArea(parent), files_model_(model)
{
    init();
}

//*---Slots---*//
void FoundFilesArea::show_file(){
    files_model_->find_and_add("l",{":/res/text2.txt"});
}
void FoundFilesArea::delete_files(){
    files_model_->find_and_add("l",{":/res/text2.txt"});
    main_view_->setModel(files_model_);
}

//*---Private---*//
void FoundFilesArea::initialization_components()
{
    main_view_ = new QListView(area_);
    show_file_=new QAction(area_);
    delete_files_ = new QAction (area_);
}
void FoundFilesArea::desing_area()
{
    auto area_layout = new QVBoxLayout(area_);
    area_->setLayout(area_layout);
    area_layout->addWidget(toolbar_);
    area_layout->addWidget(status_bar_);
    area_layout->addWidget(main_view_);

    area_->setFrameShadow(QFrame::Raised);
    area_->setFrameShape(QFrame::StyledPanel);
    area_->setMidLineWidth(3);
    area_->setLineWidth(3);
}
void FoundFilesArea::desing_main_view()
{
    main_view_->setModel(files_model_);
    main_view_->setSelectionBehavior(QAbstractItemView::SelectRows);
    main_view_->setSelectionMode(QAbstractItemView::SingleSelection);

      files_model_->find_and_add("l",{":/res/text2.txt"});
}
void FoundFilesArea::desing_status_bar()
{
    status_bar_->setText("Найденные файлы:");
}
void FoundFilesArea::desing_toolbar()
{
    show_file_->setText("Открыть");
    toolbar_->addAction(show_file_);

    delete_files_->setText("Удалить");
    toolbar_->addAction(delete_files_);
}
void FoundFilesArea::make_connections()
{
    connect (show_file_,    &QAction::triggered,
             this,          &FoundFilesArea::show_file);
    connect (delete_files_, &QAction::triggered,
             this,          &FoundFilesArea::delete_files);
}
