#pragma once
#include "Reader.h"
#include <vector>

class ConfigReader : public Reader {
public:
    ConfigReader(const ConfigReader& reader) = delete;
    ConfigReader(ConfigReader&& reader) = delete;
    ConfigReader() {};

    //std::string ReadFile(std::string filename) {};
    std::vector<std::string> ParseFile(std::string initialContent) {};
};

