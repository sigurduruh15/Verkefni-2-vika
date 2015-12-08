#include "services/scientistservice.h"
#include "utilities/scientistcomparator.h"

#include <algorithm>

using namespace std;

ScientistService::ScientistService() {

}

std::vector<Scientist> ScientistService::getAllScientists(std::string orderBy, bool orderAscending) {

    //vector<Scientist> scientists = scientistRepo.getAllScientists();

    //std::sort(scientists.begin(), scientists.end(), ScientistComparator(orderBy, orderAscending));
    vector<Scientist> scientists;
    return scientists;
}

/*std::vector<Scientist> ScientistService::searchForScientists(std::string searchTerm) {
 *
    return scientistRepo.searchForScientists(searchTerm);
}*/

bool ScientistService::addScientist(Scientist scientist) {

    return scientistRepo.addScientist(scientist);
}

bool ScientistService::addComputer(Scientist computer) {

    return scientistRepo.addComputer(computer);
}

vector<Scientist> ScientistService::printOutScientists(){

    return scientistRepo.printScientists();
}

vector<Computer> ScientistService::printOutComputers(){

    return scientistRepo.printComputers();
}
