#ifndef SEARCHAREA_H
#define SEARCHAREA_H

#include <QObject>
#include "simplegreparea.h"
#include "foundfilesmodel.h"
#include <QLineEdit>
#include <QListView>
#include <QDebug>
#include <QVBoxLayout>
#include <QFileDialog>
#include "util/searchfunctions.h"
#include <QWidget>
#include <QStringListModel>

class SearchArea;
//Паттерн Состояние
class SearchAreaState
{
public:
    SearchAreaState(SearchArea *context) : context_(context){}
    virtual ~SearchAreaState(){}
    virtual void add_path() = 0;
    virtual void delete_path() = 0;
    virtual void find_files() = 0;
protected:
    SearchArea* context_;
};

class Searching : public SearchAreaState
{
public:
    Searching(SearchArea* context);
    //TODO добавить вывод диалогового окна, которое оповестит пользователя
    //о невозможности выполнения функций во время поиска
    void add_path() override{}
    void delete_path() override{}
    void find_files() override{}
};

class ShortEmploy : public SearchAreaState
{
public:
    ShortEmploy(SearchArea* context) : SearchAreaState(context){}

    void add_path() override{}
    void delete_path() override{}
    void find_files() override{}
};

class Ready : public SearchAreaState
{
public:
    Ready(SearchArea* context);

    void add_path() override;
    void delete_path() override;
    void find_files() override;
};

//Основной класс
class SearchArea : public SimpleGrepArea
{
    friend void Ready::add_path();
    friend void Ready::delete_path();
    friend void Ready::find_files();
public:
    SearchArea(QWidget *parent = nullptr, FoundFilesModel *model = nullptr);
    ~SearchArea(){delete state_;}
    QAbstractScrollArea* get_main_view_() override{return search_paths_view_;}
    void set_state(SearchAreaState* state);
    void set_statusbar(QString label){status_bar_->setText(label);}
public slots:
    void add_path();
    void delete_path();
    void find_files();
private:
    FoundFilesModel* files_model_;
    QListView* search_paths_view_;
    QAction* add_path_;
    QAction* delete_path_;
    QAction* find_files_;
    QLineEdit* search_string_edit_; //TODO установить максимальный размер в 100.
    QStringList search_paths_;
    QStringListModel* search_paths_model_;
    SearchAreaState* state_;

    void initialization_components() override;
    void desing_area() override;
    void desing_main_view() override;
    void desing_status_bar() override;
    void desing_toolbar() override;
    void make_connections() override;

    //Инициализация модели с помощью search_paths_
    void initializing_model();
    void call_file_dialog();
};


#endif // SEARCHAREA_H
