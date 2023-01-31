#include "foundfilesmodel.h"

FoundFilesModel::FoundFilesModel(QObject *parent) : QAbstractListModel(parent)
{
}

int FoundFilesModel::rowCount (const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return found_files_.size();
}
QVariant FoundFilesModel::data (const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    switch (role){
    case Qt::DisplayRole:
        return found_files_[index.row()].path_to_file;
        break;
    default:
        assert("Error");
        return QVariant();
    }
}
QVariant FoundFilesModel::headerData (int section,
                                      Qt::Orientation orientation,
                                      int role) const
{
    if(orientation != Qt::Orientation::Horizontal || role != Qt::DisplayRole)
        return QVariant();

    return "Found files";
}
Qt::ItemFlags FoundFilesModel::flags (const QModelIndex &index) const
{
    Q_UNUSED(index)
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

//TODO нет обработки повторного поиска в файле(если ищется таде строка)
void FoundFilesModel::find_and_add(const QString& needle,
                                   const QStringList& paths){
  for (const auto& path : paths){
      QFile file(path);

      /*TODO определить и инкапсулировать логику обработки проблем с файлом
        Можно вызывать месседж бокс с информацией вместо исключений*/
      if (!file.exists()){
          throw("file not exist");
      }
      if(!file.open(QIODevice::ReadOnly)){
          throw("file not open");
      }

      //Считывание файла целиком для скорости работы. Возможно, нужно будет
      //заменить, при обработке других форматов, на построчное
      QString file_contents = file.readAll();
      //ERROR ты все еще не находишь "иглоку" в "стоге", если он на первом месте
      std::vector<qsizetype> occurrence_indexes{sf::find_indexes_of
                                               (needle,file_contents)};
      if(occurrence_indexes.size()>0){
          //создаем локальный объект FoundFile для передачи в базу данных модели
          FoundFile tmp;
          tmp.text = std::move(file_contents);
          tmp.path_to_file = path;
          tmp.search_string = needle;
          tmp.occurrence_indexes = std::move(occurrence_indexes);
          addFile(std::move(tmp));
      }
      file.close();
  }
}

bool FoundFilesModel::addFile (FoundFile file){
    beginResetModel();
    //TODO добавить обрабтку для превышения размера  строки переданного файла

    //TODO улучшить обработку переполнения количства файлов в БД модели
    if (found_files_.size() == MAX_STORED_FILES)
        return false;
    found_files_.push_back(std::move(file));
    return true;
    endResetModel();
}
