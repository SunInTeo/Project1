#pragma once

#include "Command.h"
#include "Library.h"

class CommandHandler {
private:
    Library my_lib;
    bool hasOpened = false;

public:
    CommandHandler() = delete;
    CommandHandler(const CommandHandler& other) = delete;
    CommandHandler& operator = (const CommandHandler& other) = delete;

    static CommandHandler& getInstance();

    void execute(Command command);

    void startReading();
};