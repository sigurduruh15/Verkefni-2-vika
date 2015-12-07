#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
using namespace std;


class Computer
{
public:
    Computer(int id, string name, int YearBuilt, string type);
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
