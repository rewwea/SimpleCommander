#include "../src/include/file_manager.h"
#include <iostream>

int main() {
    fs::path currentPath = fs::current_path();
    std::string command;

    while (true) {
        std::cout << "\nТекущая директория: " << currentPath << "\n";
        listFiles(currentPath);

        std::cout << "\nКоманды: cd [dir], mkdir [name], rmdir [name], exit\n";
        std::cout << "> ";
        std::cin >> command;

        if (command == "exit") break;
        else if (command == "cd") {
            std::string dir;
            std::cin >> dir;
            changeDirectory(currentPath, dir);
        } else if (command == "mkdir") {
            std::string dirName;
            std::cin >> dirName;
            createDirectory(currentPath, dirName);
        } else if (command == "rmdir") {
            std::string dirName;
            std::cin >> dirName;
            removeDirectory(currentPath, dirName);
        } else {
            std::cout << "Неизвестная команда" << '\n';
        }
    }
    return 0;
}