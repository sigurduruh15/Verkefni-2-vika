#include "Computer.h"
#include <string>
using namespace std;

Computer::Computer(int id, string name, int YearBuilt, string type)
{
    this ->id = id;
    this->name = name;
    this->YearBuilt = YearBuilt;
    this->type = type;
}
int Computer::getId(){
    return id;
}
string Computer::getName(){
    return name;
}
int Computer::getYearBuilt(){
    return YearBuilt;
}
string Computer::getType(){
    return type;
}

