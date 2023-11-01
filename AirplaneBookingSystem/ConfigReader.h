#pragma once
#include "Reader.h"
#include <vector>

class ConfigReader : public Reader {
public:
    ConfigReader() = default;
    std::vector<std::string> ParseFile(const std::string& initialContent);
    std::tuple<std::string, std::string, int, std::vector<std::vector<int>>> ParseConfiguration(const std::string& configString);
};

