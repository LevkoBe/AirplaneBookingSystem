#include "ConfigReader.h"
#include <vector>
#include <sstream>
#include <tuple>

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

std::tuple<std::string, std::string, int, std::vector<std::vector<int>>> ConfigReader::ParseConfiguration(const std::string& configString) {
    std::istringstream ss(configString);
    std::string date, ID;
    int seatsInRow;
    std::vector<std::vector<int>> fromToPrice;

    ss >> date >> ID >> seatsInRow;

    while (!ss.eof()) {
        int from, to, price;
        char currency;

        if (ss >> from) {
            if (ss.get() == '-' && ss >> to) {
                if (ss >> price >> currency && currency == '$') {
                    fromToPrice.push_back({ from, to, price });
                }
            }
        }
    }

    return std::make_tuple(date, ID, seatsInRow, fromToPrice);
}
