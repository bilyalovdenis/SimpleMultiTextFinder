#ifndef SEARCHFUNCTIONS_H
#define SEARCHFUNCTIONS_H

#include <QString>
#include <QStringView>
#include <vector>

namespace sf {
//Поиск пересекающихся вхождений
std::vector<qsizetype> find_indexes_of (QStringView needle,
                                        QStringView haystack);
}
#endif // SEARCHFUNCTIONS_H
