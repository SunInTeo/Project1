#include "../Header Files/CommandHandler.h"

CommandHandler& CommandHandler::getInstance()
{
    static CommandHandler object;

    return object;
}

void CommandHandler::printHelp()
{
    std::cout << "-==========Supported commands==========-"<< std::endl;
    std::cout << "sort <criteria> <order> -> displays books in <order> sorted by <criteria>" << std::endl;
    std::cout << "find <criteria> -> finds the desired book by <criteria>" << std::endl;
    std::cout << "add -> adds a new book to the library" << std::endl;
    std::cout << "remove <title> -> removes book" << std::endl;
    std::cout << "display -> displays book's text" << std::endl;
    std::cout << "help -> displays help menu" << std::endl;
    std::cout << "exit -> exits the program" << std::endl;
}

void CommandHandler::execute(Command command)
{
    std::string mainCommand = toUpperCase(command[0]);
    std::size_t size = command.getSize();

    if (mainCommand == "HELP")
    {
        this->printHelp();
    }
    else if (mainCommand == "EXIT")
    {
        hasOpened = true;
        std::cout << "Exiting the program..." << std::endl;
    }
    else if (mainCommand == "SORT")
    {
        if (size == 3) 
        {
            my_lib.displaySorted((command[1] == "1" ? 1:0), std::stoi(command[2]));
        }
        else
        {
            my_lib.displaySorted();
        }
    }
    else if (mainCommand == "FIND")
    {
        my_lib.find(command[1].c_str(), command[1].c_str(), command[1].c_str(), command[1].c_str());
    }
    else if (mainCommand == "ADD")
    {
        my_lib.addBook();
    }
    else if (mainCommand == "REMOVE")
    {
        my_lib.removeBook(command[1].c_str(), command[1].c_str());
    }
    else if (mainCommand == "DISPLAY")
    {
        if (size == 3)
        {
            my_lib.printBook(my_lib.getBookByTitle(command[1].c_str()), std::stoi(command[2]));
            my_lib.printBook(my_lib.getBookByTitle(command[1].c_str()), 0, (char)command[2].c_str());
        }
        my_lib.printBook(my_lib.getBookByTitle(command[1].c_str()));
    }
}

void CommandHandler::startReading(std::string path)
{
    my_lib.open(path.c_str());

    while (!hasOpened)
    {
        std::string command;
        std::cout << "> ";
        std::getline(std::cin, command);

        Command cmd(command);
        this->execute(command);
    }
}