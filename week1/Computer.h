#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
using namespace std;


class Computer
{
public:
    Computer(int id, string name, int yearBuilt, string type);
    int getId() const ;
    std::string getName() const ;
    int getYearBuilt() const ;
    string getType() const ;


private:
    int id;
    std::string name;
    int yearBuilt;
    std::string type;
};

#endif // COMPUTERS_H
