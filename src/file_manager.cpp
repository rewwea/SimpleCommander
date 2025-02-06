#include "file_manager.h"
#include <iostream>

using namespace std;

void listFiles(const fs::path& path) {
    cout << "Содержимое: " << path << "\n";
    for (const auto& entry : fs::directory_iterator(path)) {
        cout << (entry.is_directory() ? "[DIR] " : "      ") << entry.path().filename() << '\n';
    }
}

void changeDirectory(fs::path& currentPath, const string& newDir) {
    if (newDir == "..") {
        if (currentPath.has_parent_path()) {
            currentPath = currentPath.parent_path();
        } else {
            cout << "Ошибка: уже в корневой директории\n";
        }
    } else {
        fs::path newPath = currentPath / newDir;
        if (fs::exists(newPath) && fs::is_directory(newPath)) {
            currentPath = fs::canonical(newPath);
        } else {
            cout << "Ошибка: директория не найдена\n";
        }
    }
}

void createDirectory(const fs::path& currentPath, const string& dirName) {
    fs::path newDir = currentPath / dirName;
    if (fs::create_directory(newDir)) {
        cout << "Директория создана: " << newDir << '\n';
    } else {
        cout << "Ошибка при создании директории\n";
    }
}

void removeDirectory(const fs::path& currentPath, const string& dirName) {
    fs::path targetDir = currentPath / dirName;
    if (fs::exists(targetDir) && fs::is_directory(targetDir)) {
        fs::remove(targetDir);
        cout << "Директория удалена: " << targetDir << '\n';
    } else {
        cout << "Ошибка: директория не найдена\n";
    }
}

void copyFile(const fs::path& currentPath, const string& source, const string& destination) {
    fs::path srcPath = currentPath / source;
    fs::path destPath = currentPath / destination;

    try {
        fs::copy(srcPath, destPath, fs::copy_options::overwrite_existing);
        cout << "Файл " << source << " скопирован в " << destination << '\n';
    } catch (const exception& e) {
        cout << "Ошибка копирования: " << e.what() << '\n';
    }
}

void moveFile(const fs::path& currentPath, const string& source, const string& destination) {
    fs::path srcPath = currentPath / source;
    fs::path destPath = currentPath / destination;

    try {
        fs::rename(srcPath, destPath);
        cout << "Файл " << source << " перемещён в " << destination << '\n';
    } catch (const exception& e) {
        cout << "Ошибка перемещения: " << e.what() << '\n';
    }
}

void removeFile(const fs::path& currentPath, const string& fileName) {
    fs::path filePath = currentPath / fileName;

    if (fs::exists(filePath) && fs::is_regular_file(filePath)) {
        fs::remove(filePath);
        cout << "Файл " << fileName << " удалён\n";
    } else {
        cout << "Ошибка: файл не найден\n";
    }
}