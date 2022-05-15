#include "../Header Files/Utils.h"

char* makecopy(const char* str)
{
	char* copy = new (std::nothrow) char[strlen(str) + 1];
	if (!copy)
	{
		std::cout << "Memory problem!" << std::endl;
		return nullptr;
	}
	strcpy(copy, str);

	return copy;
}

void eraseFileLine(std::string path, std::string eraseLine) {
    std::string line;
    std::ifstream fin;

    fin.open(path);
    std::ofstream temp;
    temp.open("temp.txt");

    while (getline(fin, line)) {
        if (line != eraseLine)
            temp << line << std::endl;
    }

    temp.close();
    fin.close();

    const char* p = path.c_str();
    remove(p);
    rename("temp.txt", p);
}

std::string toUpperCase(const std::string& str)
{
    std::string newStr(str);
    int size = newStr.size();
    for (int i = 0; i < size; i++) {
        if (newStr[i] >= 'a' && newStr[i] <= 'z') {
            newStr[i] += ('A' - 'a');
        }
    }
    return newStr;
}
