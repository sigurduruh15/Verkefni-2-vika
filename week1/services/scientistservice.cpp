#include "services/scientistservice.h"
#include "utilities/scientistcomparator.h"

#include <algorithm>

using namespace std;

ScientistService::ScientistService() {

}

/*std::vector<Scientist> ScientistService::searchForScientists(std::string searchTerm) {
 *
    return scientistRepo.searchForScientists(searchTerm);
}*/

void ScientistService::addPersonToUi(std::string name, std::string sex, int yearBorn, int yearDeath) {
    return scientistRepo.addPerson(name, sex, yearBorn, yearDeath);
}

void ScientistService::addComputerToUi(std::string name, int yearBuild, std::string type) {
    return scientistRepo.addComputer(name, yearBuild, type);
}

vector<Scientist> ScientistService::printOutScientists(){

    return scientistRepo.printScientists();
}

vector<Computer> ScientistService::printOutComputers(){

    return scientistRepo.printComputers();
}

void ScientistService::connectTablesInput(std::string inputScientists, std::string inputComputers) {
    return scientistRepo.connectTables(inputScientists, inputComputers);
}
