#include "searchfunctions.h"

namespace sf {

std::vector<qsizetype> find_indexes_of (QStringView needle,
                                        QStringView haystack)
{
    std::vector<qsizetype> indexes;
    qsizetype last_found = 0;
    while (!haystack.isEmpty()){
        qsizetype found_index = haystack.indexOf(needle, Qt::CaseSensitive);
        if (found_index == -1) break;
        last_found += found_index;
        indexes.push_back(last_found);
        haystack = {(haystack.begin()+found_index), haystack.end()};
        }
    return indexes;
}
\

}
