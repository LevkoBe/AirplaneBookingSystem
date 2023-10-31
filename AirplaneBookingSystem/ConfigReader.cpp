#include "ConfigReader.h"
#include <vector>

std::vector<std::string> ConfigReader::ParseFile(const std::string& initialContent) {
    std::vector<std::string> text;

    if (initialContent.empty()) {
        std::cout << "Sorry, the plane crashed...";
        return std::vector<std::string>();
    }

    std::istringstream contentStream(initialContent);
    std::string line;
    while (std::getline(contentStream, line)) {
        text.push_back(line);
    }

    return text;
}
