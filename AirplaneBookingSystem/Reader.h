#pragma once
#include <iostream>
#include <Windows.h>
#include <sstream>
#include <fstream>
#include <vector>

class IReader {
public:
    virtual ~IReader() {};
    virtual std::string ReadFile(std::string filename) = 0;
};

class Reader : public IReader {
public:
    Reader(const Reader& reader) = delete;
    Reader(Reader&& reader) = delete;
    Reader() {};

    std::string ReadFile(std::string filename) override;
};
