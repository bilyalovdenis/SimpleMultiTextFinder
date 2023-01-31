#ifndef FOUNDFILESAREA_H
#define FOUNDFILESAREA_H

#include <simplegreparea.h>
#include <QListView>
#include <QDebug>
#include <QVBoxLayout>
#include <QElapsedTimer>

class FoundFilesArea : public SimpleGrepArea
{
public:
    FoundFilesArea(QWidget *parent = nullptr, FoundFilesModel *model=nullptr);
    QAbstractScrollArea* get_main_view_() override{return main_view_;}
public slots:
    void show_file();
    void delete_files();
private:
    QListView* main_view_;
    QAction* show_file_;
    QAction* delete_files_;
    FoundFilesModel* files_model_;

    void initialization_components() override;
    void desing_area() override;
    void desing_main_view() override;
    void desing_status_bar() override;
    void desing_toolbar() override;
    void make_connections() override;

};


#endif // FOUNDFILESAREA_H
