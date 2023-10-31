#pragma once
#include "Reader.h"
#include <vector>

class ConfigReader : public Reader {
public:
    ConfigReader() = default;
    std::vector<std::string> ParseFile(const std::string& initialContent);
};

