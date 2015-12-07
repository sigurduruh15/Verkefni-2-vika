#ifndef COMPUTERS_H
#define COMPUTERS_H

#include <string>
using namespace std;


class Computers
{
public:
    Computers();
    int getId();
    std::string getName();
    int getYearBuilt();
    string getType();


private:
    int id;
    std::string name;
    int YearBuilt;
    std::string type;
};

#endif // COMPUTERS_H
