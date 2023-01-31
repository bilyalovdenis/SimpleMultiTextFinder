#ifndef FOUNDFILESMODEL_H
#define FOUNDFILESMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <vector>
#include <memory>
#include <QFile>
#include <QTextStream>
#include <QStringView>
#include <QDebug>
#include "util/searchfunctions.h"

struct FoundFile
{
  QString text;
  QString path_to_file;
  QString search_string;
  std::vector<qsizetype> occurrence_indexes;

};

class FoundFilesModel : public QAbstractListModel
{
public:
    FoundFilesModel(QObject *parent = nullptr);

    enum kak : int {
        MAX_STORED_FILES = 100
    };

    //Переопределение методов интерфейса модели
    int rowCount (const QModelIndex &parent_) const override;
    QVariant data (const QModelIndex &index, int role) const override;
    QVariant headerData (int section,
                         Qt::Orientation orientation,
                         int role) const override;
    Qt::ItemFlags flags (const QModelIndex &index) const override;

    //Функция ищет и заданный шаблон в файлах, заданных списком "путей"
    void find_and_add(const QString& needle,const QStringList& paths);
private:
    using data_type = std::vector<FoundFile>;
    data_type found_files_;
    /*максимальный размер всех строк в модели(из документации QString-
      около (2-х Гигабайт)/2 оперативной памяти, такого размера достаточно
      для большинства пользовательских задач)*/
    const size_t max_size = ((size_t)-1)/2;

    bool addFile (FoundFile file);
};

#endif // FOUNDFILESMODEL_H
