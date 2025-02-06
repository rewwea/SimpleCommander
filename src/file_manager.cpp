#include "file_manager.h"
#include <iostream>

void listFiles(const fs::path& path) {
    std::cout << "Содержимое: " << path << "\n";
    for (const auto& entry : fs::directory_iterator(path)) {
        std::cout << (entry.is_directory() ? "[DIR] " : "      ") << entry.path().filename() << '\n';
    }
}

void changeDirectory(fs::path& currentPath, const std::string& newDir) {
    if (newDir == "..") {
        if (currentPath.has_parent_path()) {
            currentPath = currentPath.parent_path();
        } else {
            std::cout << "Ошибка: уже в корневой директории\n";
        }
    } else {
        fs::path newPath = currentPath / newDir;
        if (fs::exists(newPath) && fs::is_directory(newPath)) {
            currentPath = fs::canonical(newPath);
        } else {
            std::cout << "Ошибка: директория не найдена\n";
        }
    }
}

void createDirectory(const fs::path& currentPath, const std::string& dirName) {
    fs::path newDir = currentPath / dirName;
    if (fs::create_directory(newDir)) {
        std::cout << "Директория создана: " << newDir << '\n';
    } else {
        std::cout << "Ошибка при создании директории\n";
    }
}

void removeDirectory(const fs::path& currentPath, const std::string& dirName) {
    fs::path targetDir = currentPath / dirName;
    if (fs::exists(targetDir) && fs::is_directory(targetDir)) {
        fs::remove(targetDir);
        std::cout << "Директория удалена: " << targetDir << '\n';
    } else {
        std::cout << "Ошибка: директория не найдена\n";
    }
}