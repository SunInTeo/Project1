#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

class Command {
private:
    std::string rawString;
    std::vector<std::string> arrString;

public:
    Command(std::string raw);

    std::string& operator[](const std::size_t pos);
    const std::string& operator[](const std::size_t pos) const;

    const std::string& getRaw() const;
    int getSize() const;

    void print() const;
};
