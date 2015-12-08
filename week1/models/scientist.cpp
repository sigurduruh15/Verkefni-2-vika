#include "models/scientist.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

using namespace std;

Scientist::Scientist(int id, string name, string sex, int yearBorn)
{
    this ->id = id;
    this->name = name;
    this->sex = sex;
    this->yearBorn = yearBorn;
    this->yearDied = constants::YEAR_DIED_DEFAULT_VALUE;
}

Scientist::Scientist(int id, string name, string sex, int yearBorn, int yearDied)
{
    this ->id = id;
    this->name = name;
    this->sex = sex;
    this->yearBorn = yearBorn;
    this->yearDied = yearDied;
}

std::string Scientist::getName() const {

    return name;
}

std::string Scientist::getSex() const {

    return sex;
}

int Scientist::getYearBorn() const {

    return yearBorn;
}

int Scientist::getYearDied() const {

    return yearDied;
}
int Scientist::getid() const {

    return id;
}

void Scientist::setName(string n){

    name = n;
}
void Scientist::setSex(string s){

    sex = s;
}

void Scientist::setYearBorn(int b){

    yearBorn = b;
}

void Scientist::setYearDied(int d){

    yearDied = d;
}
