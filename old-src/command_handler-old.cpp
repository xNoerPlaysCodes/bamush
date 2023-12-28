#include <iostream>
#include <vector>
#include <filesystem>
#include "shell.cpp"
#include "../libs/qt.hpp"
using str = std::string;
int handle(const int &argc, const std::vector<str> &argv) {
    if (argc == 0) {
        return 2;
    } else if (argc == 1) {
        int code = std::system((argv[0]).c_str());
        if (code == 32512) {
            std::cout << "Command not found.\n";
        }
    } else {
        if (argv[0] == "clear") {
            std::system("clear");
        } else if (argv[0] == "cd") {
            if (argc == 1) {
                // switch to user home dir
                str homedir = getHomeDirectory();
                std::filesystem::current_path(homedir);
            } else if (argc == 2) {
                std::filesystem::current_path(argv[1]);
            }
        }
        str c = "/bin/";
        for (int i = 0; i < argc; i++) {
            c += argv[i] + " ";
        }
        int code = std::system(c.c_str());
        if (code == 32512) {
            std::cout << "Command not found.\n";
        }
    }
    return 0;
}