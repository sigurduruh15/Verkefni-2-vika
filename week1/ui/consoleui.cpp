#include "ui/consoleui.h"
#include "utilities/constants.h"
#include "utilities/utils.h"

#include <iostream>
#include <iomanip>

using namespace std;

ConsoleUI::ConsoleUI()
{
    lastCommand = command::menu;
    sortBy = "name";
    sortAscending = true;
}
void ConsoleUI::display() {

    switch (lastCommand) {
        case command::menu:
            displayMenu();
            break;
        case command::add:
            addMenu();
            displayMenu();
            break;
        case command::display:
            //displayAllScientists();
            displayChooseMenu();
            displayMenu();
            break;
        case command::search:
            //displayScientistSearchMenu();
            break;
        case command::sort:
            //displayScientistSortMenu();
            break;
        default:
            displayUnknownCommandMenu();
            break;
    }
}
void ConsoleUI::addPersonUI() {

    string name;
    string sex;
    int yearBorn, yearDied;

    cout << "Name: ";
    cin >> name;

    cout << "Gender: ";
    cin >> sex;

    cout << "Birth year: ";
    cin >> yearBorn;

    cout << "Death year: ";
    cin >> yearDied;

    scientistService.addPersonToUi(name, sex, yearBorn, yearDied);
}

void ConsoleUI::addComputerUI() {

    string name;
    string type;
    int yearBuild;

    cout << "Name: ";
    cin >> name;

    cout << "Year Build: ";
    cin >> yearBuild;

    cout << "Type: ";
    cin >> type;

    scientistService.addComputerToUi(name, yearBuild, type);
}

/*void ConsoleUI::printDisplay(){
   scientistService.printOutScientists();
}*/

void ConsoleUI::printComput(){

   vector<Computer> k = scientistService.printOutComputers();

    for(unsigned int i = 0; i < k.size(); i++){
        cout << "Id: " << k[i].getId() << endl;
        cout << "Name: " << k[i].getName() << endl;
        cout << "Year built: " << k[i].getYearBuilt() << endl;
        cout << "type: "<< k[i].getType() << endl;
        cout << endl;
    }
}

void ConsoleUI::printSciens(){

   vector<Scientist> v = scientistService.printOutScientists();

    for(unsigned int i = 0; i < v.size(); i++){
        cout << "Id: " << v[i].getid() << endl;
        cout << "Name: " << v[i].getName()<< endl;
        cout << "Gender: " << v[i].getSex()<< endl;
        cout << "Birth year: "<< v[i].getYearBorn()<< endl;
        cout << "Year of death: "<< v[i].getYearDied()<< endl;
        cout << endl;
    }
}

int ConsoleUI::start() {

    while(lastCommand != command::quit) {
        display();
        readInput();
    }

    return 0;
}



void ConsoleUI::readInput() {

   /* if (lastCommand == command::display) {
        lastCommand = command::menu;
        return;
    }*/

    string userInput;
    getline(cin, userInput);

    cout << "\n";

    bool shouldTreatInputAsCommand = (lastCommand != command::search);

    if (userInput == "display" && shouldTreatInputAsCommand) {
        lastCommand = command::display;
    }
    else if (userInput == "add" && shouldTreatInputAsCommand) {
        lastCommand = command::add;
    }
    /*else if (userInput == "search" && shouldTreatInputAsCommand) {
        lastCommand = command::search;
    }*/
    else if (userInput == "back") {
        lastCommand = command::menu;
    }
    else if (userInput == "quit") {
        lastCommand = command::quit;
    }
    else {
        lastCommand = command::unknown;
    }
}

void ConsoleUI::displayMenu() {

    cout << "       ,-------------------------------------------------," << endl;
    cout << "       |        *~~~   Enter a command:  ~~~*            |" << endl;
    cout << "       |                                                 |" << endl;
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "       |   add:         Adds a Scientists or a computer  |" << endl;

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "       |   display:     Displays scientists              |" << endl;

    /*cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "search:" << "Search for a scientist\n";*/

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "       |   quit:        Quits the program                |" << endl;
    cout << "       |                                                 |" << endl;
    cout << "       '-------------------------------------------------'" << endl;
    cout << "Command: ";
}

void ConsoleUI::displayChooseMenu() {

    int n = 0;
    cout << "                   ,---------------------," << endl;
    cout << "                   |1. Display Scientists|" << endl;
    cout << "                   |2. Display computers |" << endl;
    cout << "                   '---------------------'" << endl;
    cout << "Choose a number: ";
    cin >> n;

    if(n == 1) {
        printSciens();
    }
    else if(n == 2) {
        printComput();
    }
    else if (n != 1 || n != 2) {
        cout << "Wrong input, try again" << endl;
        displayChooseMenu();
    }
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
}

void ConsoleUI::addMenu() {

    int n = 0;

    cout << "                   ,-------------------," << endl;
    cout << "                   |1. Input Scientists|" << endl;
    cout << "                   |2. Input computers |" << endl;
    cout << "                   '-------------------'" << endl;
    cout << "Choose a number: ";
    cin >> n;

    if(n == 1) {
        addPersonUI();
    }
    else if(n == 2) {
        addComputerUI();
    }
    else if (n != 1 || n != 2) {
        cout << "Wrong input, try again" << endl;
        addMenu();
    }
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
}

/*void ConsoleUI::displayAllScientists() {

    vector<Scientist> scientists = scientistService.getAllScientists(sortBy, sortAscending);

    displayScientists(scientists);

    cout << '\n';

    lastCommand = command::display;
}*/

/*void ConsoleUI::displayScientistSearchMenu() {

    cout << "Search for a scientist.\n\n";

    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}*/

/*void ConsoleUI::displayScientistSortMenu() {

    cout << "How should the list be sorted:\n\n";
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_NAME_ASCENDING << "Sorts by name, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_NAME_DESCENDING << "Sorts by name, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_BORN_ASCENDING << "Sorts by year born, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_BORN_DESCENDING << "Sorts by year born, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_DIED_ASCENDING << "Sorts by year died, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_DIED_DESCENDING << "Sorts by year died, descending.\n\n";

    cout << "If you would like to go back to the main menu, please type: back\n";

    cout << "Command: ";
}*/

void ConsoleUI::displayUnknownCommandMenu() {

    displayError("Unknown command");
    cout << "Command: ";
}

/*void ConsoleUI::displayScientists(std::vector<Scientist> scientists) {

    if (scientists.size() == 0) {
        cout << "No scientist found.\n";
        return;
    }

    cout << "Printing all scientists:\n";

    cout << setw(20) << std::left << "Name:"
         << setw(8) << std::left << "Sex:"
         << setw(12) << std::left << "Year born:"
         << setw(12) << std::left << "Year died:" << endl;

    for (unsigned int i = 0; i < scientists.size(); i++) {
        string scientistSex = (scientists.at(i).getSex());

        int yearDied = scientists.at(i).getYearDied();
        string died = (yearDied == constants::YEAR_DIED_DEFAULT_VALUE) ? "Alive" : utils::intToString(yearDied);

        cout << setw(20) << std::left << scientists.at(i).getName()
             << setw(8) << std::left << scientistSex
             << setw(12) << std::left << scientists.at(i).getYearBorn()
             << setw(12) << std::left << died << endl;
    }
}*/

/*bool ConsoleUI::addScientist(string data) {
 *
    vector<string> fields = utils::splitString(data, ',');

    if (fields.size() > 2 && fields.size() < 5) {
        string name = fields.at(0);

        enum sexType sex;
        if (fields.at(1) == "male") {
            sex = sexType::male;
        }
        else {
            sex = sexType::female;
        }
        int yearBorn = utils::stringToInt(fields.at(2));

        if (fields.size() == 3) {
            return scientistService.addScientist(Scientist(name, sex, yearBorn));
        }
        else {
            int yearDied = utils::stringToInt(fields.at(3));

            return scientistService.addScientist(Scientist(name, sex, yearBorn, yearDied));
        }
    }

    return false;
}*/
/*
bool ConsoleUI::setSort(string sortCommand) {

    if (sortCommand == constants::SORT_SCIENTIST_NAME_ASCENDING) {
        sortBy = "name";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_NAME_DESCENDING) {
        sortBy = "name";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_BORN_ASCENDING) {
        sortBy = "yearBorn";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_BORN_DESCENDING) {
        sortBy = "yearBorn";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_DIED_ASCENDING) {
        sortBy = "yearDied";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_DIED_DESCENDING) {
        sortBy = "yearDied";
        sortAscending = false;
    }
    else {
        return false;
    }

    return true;
}
*/
void ConsoleUI::displayError(string error) {

    cout << "There was an error: " << error << "\n";
    cout << "Please try again or type 'back' to go back.\n\n";
}
