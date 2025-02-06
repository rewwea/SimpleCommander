#pragma once
#include <filesystem>

namespace fs = std::filesystem;

void listFiles(const fs::path& path);
void changeDirectory(fs::path& currentPath, const std::string& newDir);
void createDirectory(const fs::path& currentPath, const std::string& dirName);
void removeDirectory(const fs::path& currentPath, const std::string& dirName);