#include "Computer.h"
#include <string>
using namespace std;

Computer::Computer(int id, string name, int yearBuilt, string type) {
    this->id = id;
    this->name = name;
    this->yearBuilt = yearBuilt;
    this->type = type;
}

int Computer::getId() const {

    return id;
}

string Computer::getName() const {

    return name;
}

int Computer::getYearBuilt() const {

    return yearBuilt;
}

string Computer::getType() const {

    return type;
}


