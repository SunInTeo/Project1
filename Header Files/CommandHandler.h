#pragma once

#include "Command.h"
#include "Library.h"

class CommandHandler {
private:
    Library my_lib;
    bool hasOpened = false;

    CommandHandler() {}

    void printHelp(); 

public:
    CommandHandler(const CommandHandler& other) = delete;
    CommandHandler& operator = (const CommandHandler& other) = delete;

    static CommandHandler& getInstance();

    void execute(Command command);

    void startReading(std::string path);
};