#pragma once

#include <filesystem>
#include <fstream>
#include <string>
namespace fs = std::filesystem;

namespace computerOrganization
{
std::string readFile(const std::string &filename)
{
    std::ifstream file(filename);
    return std::string((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());
}
std::string cpuInfo() { return readFile("/proc/cpuinfo"); }
} // namespace computerOrganization
