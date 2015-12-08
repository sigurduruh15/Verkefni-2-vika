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

    /**
     * @brief searchForScientists fetches all scientists from file and filters them on searchTerm
     * @param searchTerm Contains the input that the user wishes to filter on
     * @return a vector of scientists filtered by searchTerm
     */
    std::vector<Scientist> searchForScientists(std::string searchTerm);

private:
    std::string fileName;
};

#endif // SCIENTISTREPOSITORY_H
