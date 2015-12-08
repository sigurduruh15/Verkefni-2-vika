#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

/**
 * @brief The data model for scientists
 */
class Scientist
{
public:
    Scientist(int id, std::string name, std::string sex, int yearBorn);
    Scientist(int id, std::string name, std::string sex, int yearBorn, int yearDied);

    int getid() const;
    std::string getName() const;
    std::string getSex() const;
    int getYearBorn() const;
    int getYearDied() const;
    void setName(std::string n);
    void setSex(std::string s);
    void setYearBorn(int b);
    void setYearDied(int d);

    bool contains(std::string searchTerm);

private:
    int id;
    std::string name;
    std::string sex;
    int yearBorn;
    int yearDied;
};

#endif // SCIENTIST_H
