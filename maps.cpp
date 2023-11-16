#include "maps.h"

maps::maps()
{

}

void maps::clearInfo(){
    _items.clear();
    _line.clear();
    _numbers.clear();
}

void maps::setLine(QString newLine){_line.append(newLine);}

int maps::findLucky (){
    std::string lineStr;
    lineStr.append(_line.toStdString());

    int iter = 1;
    for(int i = 0; i < lineStr.length(); i++){
        if(lineStr.at(i) == ' '){
            iter++;
        }
    }

    _items.resize(iter);

    int k = 0;
    std::string tempS;
    for(int i = 0; i < lineStr.length(); i++){
        if(lineStr.at(i) != ' '){
            tempS = lineStr.substr(i, 1);
            _items.at(k) = std::stoi(tempS);
            k++;
        }
    }


    for (int i = 0; i < iter; i++){
        auto insertValue = _numbers.insert(std::pair<int, int> (_items.at(i), 1));
        if(insertValue.second == false){
            _numbers.at(_items.at(i))++;
        }
    }

    int result = -1;

    for (int i = 1; i <= 9; i++){
        if(_numbers[i] == i){
            result = i;
        }
    }

    return result;
}
