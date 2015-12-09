#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "services/scientistservice.h"

/**
 * @brief Holds commands that are available in the UI
 */
enum command {
    menu,
    add,
    display,
    search,
    connect,
    pretty,
    quit,
    unknown
};

class ConsoleUI
{
public:
    ConsoleUI();
    void printSciens();
    void printComput();
    void addPersonUI();
    void addComputerUI();
    void addMenu();
    void connectTables();
    void printConnectTabl();
    void printPretty();

    int start();

private:
    void display();
    void readInput();
    void displayMenu();
    void displayChooseMenu();
    void displayUnknownCommandMenu();
    void displayError(std::string error);

    ScientistService scientistService;
    ScientistService Serv;
    enum command lastCommand;
};

#endif // CONSOLEUI_H
