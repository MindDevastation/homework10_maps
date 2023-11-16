#ifndef MAPS_H
#define MAPS_H

#include <QString>
#include <map>


class maps
{
    std::vector<int> _items;
    QString _line;
    std::map<int, int> _numbers;
public:
    maps();

    void clearInfo();

    void setLine(QString newLine);

    int findLucky ();
};

#endif // MAPS_H
