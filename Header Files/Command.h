#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

/**
 *  Class Command helps with processing given commands.
 */
class Command {
private:
    std::string rawString;
    std::vector<std::string> arrString;

public:
    /** Constructor. Receives a raw string of commands and
     *               divides them into different ones and
     *               puts them in a container(the vector of commands).
     *  @param raw string which is parsed into different commands
     */
    Command(std::string raw);
    
    /** Returns the string that is at the given position in the vector.
    *
    *  @param pos the position of the command we are looking for
    *  @return command as a string
    */
    std::string& operator[](const std::size_t pos);
    /** Returns the string that is at the given position in the vector.
    *         But wurks for const.
    *  @param pos the position of the command we are looking for
    *  @return command as a string
    */
    const std::string& operator[](const std::size_t pos) const;

    /** When called returns the raw string that was first handed.
    *  @return the original string passed to the constructor
    */
    const std::string& getRaw() const;
    /** When called returns the size of the vector(the container).
    *  @return int value
    */
    int getSize() const;

    void print() const;
};
