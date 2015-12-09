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
        case command::pretty:
            printPretty();
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

    if(yearBorn > yearDied && yearDied != 0){
        cout << "You can't die before you are born! input again!" << endl;
        cout << "Birth year: ";
        cin >> yearBorn;
        cout << "Death year: ";
        cin >> yearDied;

    }

    scientistService.addPersonToUi(name, sex, yearBorn, yearDied);
}

void ConsoleUI::addComputerUI() {

    string name;
    string type;
    int yearBuild;

    cout << "Name: ";
    cin >> name;

    cout << "Year Build (if computer was not built, input 0): ";
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
void ConsoleUI::printConnectTabl(){

   vector<ConnectTab> c = scientistService.printConnectService();

    for(unsigned int i = 0; i < c.size(); i++){
        cout << "Name of scientist: " << c[i].getSciName() << endl;
        cout << "Name of computer: " << c[i].getComName()<< endl;
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
    else if (userInput == "pretty" && shouldTreatInputAsCommand) {
        lastCommand = command::pretty;
    }
    else if (userInput == "quit") {
        lastCommand = command::quit;
    }
    else {
        lastCommand = command::unknown;
    }
}

void ConsoleUI::displayMenu() {

    cout << "       ,---------------------------------------------------------------," << endl;
    cout << "       |               *~~~   Enter a command:  ~~~*                   |" << endl;
    cout << "       |                                                               |" << endl;
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "       |   add:         Add a scientist or a computer                  |" << endl;

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "       |   display:     Display scientists, computers or connect table |" << endl;
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "       |   connect:     Connect computer and scientist                 |" << endl;
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "       |   pretty:      print pretty                                   |" << endl;
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "       |   quit:        Quits the program                              |" << endl;
    cout << "       |                                                               |" << endl;
    cout << "       '---------------------------------------------------------------'" << endl;
    cout << "Command: ";
}

void ConsoleUI::displayChooseMenu() {

    int n = 0;
    cout << "                   ,---------------------," << endl;
    cout << "                   |1. Display Scientists|" << endl;
    cout << "                   |2. Display computers |" << endl;
    cout << "                   |3. Display connection|" << endl;
    cout << "                   '---------------------'" << endl;
    cout << "Choose a number: ";
    cin >> n;

    if(n == 1) {
        printSciens();
    }
    else if(n == 2) {
        printComput();
    }
    else if(n == 3) {
        printConnectTabl();
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
    cout << "Please try again.\n\n";
}

void ConsoleUI::printPretty() {

    cout << "" << endl;
    cout << "                        8888888888  888    88888 " << endl;
    cout << "                       88     88   88 88   88  88" << endl;
    cout << "                        8888  88  88   88  88888" << endl;
    cout << "                           88 88 888888888 88   88" << endl;
    cout << "                    88888888  88 88     88 88    888888" << endl;
    cout << "" << endl;
    cout << "                    88  88  88   888    88888    888888" << endl;
    cout << "                    88  88  88  88 88   88  88  88" << endl;
    cout << "                     88 8888 88 88   88  88888    8888" << endl;
    cout << "                      888  888 888888888 88   88     88" << endl;
    cout << "                       88  88  88     88 88    8888888" << endl;
    cout << endl;
}
