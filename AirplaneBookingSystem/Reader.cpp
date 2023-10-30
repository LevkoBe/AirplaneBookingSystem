#include "Reader.h"

std::string Reader::ReadFile(std::string filename) {
    std::string text = "";

    std::ifstream inputFile(filename);
    if (!inputFile) {
        inputFile.close();
        //std::cout << "\nError opening file.\n" << std::endl;
        return "";
    }
    else {
        std::string line;
        while (getline(inputFile, line)) {
            text += line + "\n";
        }
        inputFile.close();

        //std::cout << "Text successfully loaded from " << filename << std::endl;
    }
    return text;
}
