#include "ui/consoleui.h"
#include "utilities/constants.h"
#include "utilities/utils.h"

#include <iostream>
#include <iomanip>

using namespace std;

ConsoleUI::ConsoleUI()
{
    lastCommand = command::menu;
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
            displayChooseMenu();
            displayMenu();
            break;
        case command::connect:
            connectTables();
            displayMenu();
            break;
        default:
            displayUnknownCommandMenu();
            break;
    }
}

void ConsoleUI::connectTables() {

    int inputScientists, inputComputers;

    cout << "Input ID of computer scientist: ";
    cin >> inputScientists;
    cout << "Input ID of computer: ";
    cin >> inputComputers;

    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    scientistService.connectTablesInput(inputScientists, inputComputers);
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

    cout << "Year Build (if computer was not built, put 0): ";
    cin >> yearBuild;

    cout << "Type: ";
    cin >> type;

    scientistService.addComputerToUi(name, yearBuild, type);
}

void ConsoleUI::printComput(){

   vector<Computer> k = scientistService.printOutComputers();

    for(unsigned int i = 0; i < k.size(); i++){
        cout << "Id: " << k[i].getId() << endl;
        cout << "Name: " << k[i].getName() << endl;
        cout << "Year built: ";
        if(k[i].getYearBuilt() == 0) {
            cout << "Was not built" << endl;
        }
        else {
            cout << k[i].getYearBuilt() << endl;
        }
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
    else if (userInput == "connect" && shouldTreatInputAsCommand) {
        lastCommand = command::connect;
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
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "       |   connect:     Connect computer to scientists   |" << endl;

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

void ConsoleUI::displayUnknownCommandMenu() {

    displayError("Unknown command");
    cout << "Command: ";
}


void ConsoleUI::displayError(string error) {

    cout << "There was an error: " << error << "\n";
    cout << "Please try again or type 'back' to go back.\n\n";
}
