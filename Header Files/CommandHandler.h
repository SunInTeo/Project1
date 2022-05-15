#pragma once

#include "Command.h"
#include "Library.h"

/** 
 * class CommandHandler deals with the user's input.
 */
class CommandHandler {
private:
    Library my_lib;
    bool hasOpened = false;

    CommandHandler() {}

    /** Prints information about all valid commands
    */
    void printHelp(); 

public:
    CommandHandler(const CommandHandler& other) = delete;
    CommandHandler& operator = (const CommandHandler& other) = delete;

   
    /** Static function for getting the oneand only instance of the class
    */
    static CommandHandler& getInstance();

    /** executes the given command
    *  @return Void.
    */
    void execute(Command command);

    /** When called starts the process of reading commands.
    * The function reads a line from the console and puts it in a variable from type Command.
    * Which gets split into different strings.
    * After that execute() is called and the process of performing commands continues until the user types "EXIT".
    *  @return Void.
    */
    void startReading(std::string path);
};