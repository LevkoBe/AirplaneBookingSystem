#include "ConfigReader.h"
#include <vector>

std::vector< std::string> ConfigReader::ParseFile(std::string initialContent) {
    std::vector<std::string> text;

    if (initialContent.empty()) { // == ""
        std::cout << "Sorry, the plane crashed...";
        return std::vector<std::string>();
    }

    std::istringstream contentStream(initialContent);
    std::string line;
    while (std::getline(contentStream, line)) {
        // creating AirFlight instance and putting it inside the vector
        text.push_back(line); // instead of line: instance
    }

    return text;
}
