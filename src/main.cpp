#include "../src/include/file_manager.h"
#include <iostream>

using namespace std;

int main() {
    fs::path currentPath = fs::current_path();
    string command;

    while (true) {
        cout << "\nТекущая директория: " << currentPath << "\n";
        listFiles(currentPath);

        cout << "\nКоманды: cd [dir], mkdir [name], rmdir [name], rm [file], cp [src] [dest], mv [src] [dest], exit\n";
        cout << "> ";
        cin >> command;

        if (command == "exit") break;
        else if (command == "cd") {
            string dir;
            cin >> dir;
            changeDirectory(currentPath, dir);
        } else if (command == "mkdir") {
            string dirName;
            cin >> dirName;
            createDirectory(currentPath, dirName);
        } else if (command == "rmdir") {
            string dirName;
            cin >> dirName;
            removeDirectory(currentPath, dirName);
        } else if (command == "rm") {
            string fileName;
            cin >> fileName;
            removeFile(currentPath, fileName);
        } else if (command == "cp") {
            string source, destination;
            cin >> source >> destination;
            copyFile(currentPath, source, destination);
        } else if (command == "mv") {
            string source, destination;
            cin >> source >> destination;
            moveFile(currentPath, source, destination);
        } else {
            cout << "Неизвестная команда" << '\n';
        }
    }
    return 0;
}
