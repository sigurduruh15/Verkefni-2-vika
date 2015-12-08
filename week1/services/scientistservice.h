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

    /**
     * @brief searchForScientists fetches all scientists from file and filters them on searchTerm
     * @param searchTerm Contains the input that the user wishes to filter on
     * @return a vector of scientists filtered by searchTerm
     */
    //std::vector<Scientist> searchForScientists(std::string searchTerm);

    std::vector<Scientist> printOutScientists();
    std::vector<Computer> printOutComputers();

    void addPersonToUi(std::string name, std::string sex, int yearBorn, int yearDeath);
    void addComputerToUi(std::string name, int yearBuild, std::string type);
    void connectTablesInput(std::string inputScientists, std::string inputComputers);
private:
    ScientistRepository scientistRepo;
    ScientistRepository  Serv;
};

#endif // SCIENTISTSERVICE_H
