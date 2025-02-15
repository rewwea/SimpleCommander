#pragma once
#include <filesystem>

namespace fs = std::filesystem;

void listFiles(const fs::path& path);
void changeDirectory(fs::path& currentPath, const std::string& newDir);
void createDirectory(const fs::path& currentPath, const std::string& dirName);
void removeDirectory(const fs::path& currentPath, const std::string& dirName);
void copyFile(const fs::path& currentPath, const std::string& source, const std::string& destination);
void moveFile(const fs::path& currentPath, const std::string& source, const std::string& destination);
void removeFile(const fs::path& currentPath, const std::string& fileName);