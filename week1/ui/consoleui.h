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
    sort,
    back,
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
    void addMenu();
    void addComputerUI();

    /**
     * @brief start is the main run loop for the application
     * @return should indicate how the program exists, currently always safely
     */
    int start();

private:
    /**
     * @brief display serves as a router to according display functions
     */
    void display();

    /**
     * @brief readInput handles user input by settings commands or processing it
     */
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
