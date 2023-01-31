#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QScreen>
#include <QDebug>
#include <QLayout>
#include "QPushButton"
#include "QString"
#include "QStringListModel"
#include "QStringList"
#include "foundfilesarea.h"
#include <QFile>
#include "searcharea.h"
#include "textviewerarea.h"
#include "foundfilesmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    //Methods for build interface
    void buildCentralWidget();

    //Contained widgets
    SearchArea* search_area_;
    FoundFilesArea* found_files_area_;
    TextViewerArea* text_viewer_area_;

    //глобальный для внутренних областей объект модели
    FoundFilesModel* found_files_model_;

};
#endif // MAINWINDOW_H
