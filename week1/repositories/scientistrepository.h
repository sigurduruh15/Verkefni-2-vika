#ifndef SCIENTISTREPOSITORY_H
#define SCIENTISTREPOSITORY_H
#include <QCoreApplication>
#include <QtSql>
#include "string"
#include <iostream>
#include <QString>

#include <vector>
#include <string>

#include "models/scientist.h"
#include "Computer.h"
#include "ConnectTab.h"


/**
 * @brief The ScientistRepository class handles reading and writing scientists to and from a file
 */
class ScientistRepository
{
public:
    ScientistRepository();
    QSqlDatabase openDatabase();
    std::vector<Computer> printComputers();
    std::vector<Scientist> printScientists();
    void addPerson(std::string name, std::string sex, int yearBorn, int yearDeath);
    void addComputer(string name, int yearBuild, string type);
    void connectTables(int inputScientists, int inputComputers);
    vector<ConnectTab> printConnectTable();
private:
    std::string fileName;
};

#endif // SCIENTISTREPOSITORY_H
