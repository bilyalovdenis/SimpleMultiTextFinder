 #include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    found_files_model_ = new FoundFilesModel(this);
    search_area_ = new SearchArea(this, found_files_model_);
    found_files_area_ = new FoundFilesArea(this, found_files_model_);
    text_viewer_area_ = new TextViewerArea(this);
    buildCentralWidget();


}

MainWindow::~MainWindow()
{

}

void MainWindow::buildCentralWidget()
{
    setCentralWidget(new QWidget(this));
    auto central_widget = centralWidget();
    auto widget_layout =new QHBoxLayout(central_widget);
    central_widget->setLayout(widget_layout);
    central_widget->setMinimumSize(600,600);

    auto left_widget = new QWidget(central_widget);
    auto left_layout =new QVBoxLayout(central_widget);
    left_widget->setLayout(left_layout);
    left_layout->addWidget(search_area_->get_area());
    left_layout ->addWidget(found_files_area_->get_area());


    widget_layout ->addWidget(left_widget);

    widget_layout ->addWidget(text_viewer_area_->get_area());







  //  ui->centralwidget->setStyleSheet("background-color: #D9A566");
//    add_files_ = new QAction(QIcon("/home/bloodyclaw/projects/qt/MultiTextFinder/circle.png"),
//                             tr("&Add"), central_widget);

}
