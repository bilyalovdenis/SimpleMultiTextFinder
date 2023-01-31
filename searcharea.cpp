#include "searcharea.h"

//*----Searching State----*//
Searching::Searching(SearchArea* context) : SearchAreaState(context){
    if(context_==nullptr) return;
    context_->set_statusbar("Идет поиск...");
}

//*----Ready state----*//
Ready::Ready(SearchArea* context) : SearchAreaState(context)
{
    if(context_==nullptr) return;
    context_->set_statusbar("Введите строку для поиска:");
}
void Ready::add_path()
{
    context_->call_file_dialog();
}
void Ready::delete_path()
{

}
void Ready::find_files()
{
     context_->initializing_model();
}
//**-----SearchArea**-----//
//*---Public---*//
SearchArea::SearchArea(QWidget *parent, FoundFilesModel *model)
    :SimpleGrepArea(parent), files_model_(model)
{
    init();
}
void SearchArea::set_state(SearchAreaState* state){
   //WARNING возможна динамическая ошибка выполнения
    delete state_;
    state_ = state;
}
//*---Slots---*//
void SearchArea::add_path(){
    state_->add_path();
}
void SearchArea::delete_path(){
    state_->delete_path();
}
void SearchArea::find_files(){
    state_->find_files();
}
//*---Private---*//
void SearchArea::initialization_components()
{
    search_paths_view_ = new QListView(area_);
    add_path_=new QAction(area_);
    delete_path_ = new QAction (area_);
    find_files_ = new QAction (area_);
    search_string_edit_ = new QLineEdit(area_);
    state_ = new Ready(this);
    search_paths_model_ = new QStringListModel(search_paths_, area_);
}
void SearchArea::desing_area()
{
    auto area_layout = new QVBoxLayout(area_);
    area_->setLayout(area_layout);
    area_layout->addWidget(status_bar_);
    area_layout->addWidget(search_string_edit_);
    area_layout->addWidget(toolbar_);
    area_layout->addWidget(search_paths_view_);

    area_->setFrameShadow(QFrame::Raised);
    area_->setFrameShape(QFrame::StyledPanel);
    area_->setMidLineWidth(3);
    area_->setLineWidth(3);
}
void SearchArea::desing_main_view()
{
    search_paths_view_->setModel(search_paths_model_);
    search_paths_view_->setSelectionBehavior(QAbstractItemView::SelectRows);
    search_paths_view_->setSelectionMode(QAbstractItemView::ExtendedSelection);
}
void SearchArea::desing_status_bar()
{

}
void SearchArea::desing_toolbar()
{
    add_path_->setText("Добавить путь");
    toolbar_->addAction(add_path_);

    delete_path_->setText("Удалить путь");
    toolbar_->addAction(delete_path_);

    find_files_->setText("Найти");
    toolbar_->addAction(find_files_);
}
void SearchArea::make_connections()
{
    connect (add_path_, &QAction::triggered, this, &SearchArea::add_path);
    connect (delete_path_, &QAction::triggered, this, &SearchArea::delete_path);
    connect (find_files_, &QAction::triggered, this, &SearchArea::find_files);

}
void SearchArea::initializing_model(){
    set_state(new Searching(this));

    //TODO сделать корректную обработку serch_string_edit
    if (search_paths_.size()==0||search_string_edit_->text()==""){
    //TODO вызывать диалоговое окно с предупреждением об отсутвиии путей
        return;
    }
    files_model_->find_and_add(search_string_edit_->text(), search_paths_);
    set_state(new Ready(this));
}

void SearchArea::call_file_dialog()
{
    set_state(new ShortEmploy(this));
    /*TODO реализовать более гибкую систему задания параметров файлового диалога
    Доьавить возможность выбора директории, а не конкретного файла*/
    search_paths_ = QFileDialog::getOpenFileNames((QWidget*)parent(),
                                                tr("Open Text File"),
                                                "/home",
                                                tr("Text Files(*txt)"));
    search_paths_model_->setStringList(search_paths_);
    set_state(new Ready(this));
}
