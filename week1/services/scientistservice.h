#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include "repositories/scientistrepository.h"

/**
 * @brief The ScientistService acts as a middle layer between the UI and Data layers, also handles sorting
 */
class ScientistService
{
public:
    ScientistService();
    std::vector<Scientist> printOutScientists();
    std::vector<Computer> printOutComputers();

    void addPersonToUi(std::string name, std::string sex, int yearBorn, int yearDeath);
    void addComputerToUi(std::string name, int yearBuild, std::string type);
    void connectTablesInput(int inputScientists, int inputComputers);
    vector<ConnectTab> printConnectService();
private:
    ScientistRepository scientistRepo;
    ScientistRepository  Serv;
};

#endif // SCIENTISTSERVICE_H
