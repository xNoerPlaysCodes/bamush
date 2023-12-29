#include "command_handler.h"

template<typename _Iterator>
const std::reverse_iterator<_Iterator> &strlen(const std::basic_string<char> &basicString);

using str = std::string;
inline str getHomeDirectory() {
    const char* homedir = std::getenv("HOME");
    if (homedir == nullptr) {
        return ".";
    } else {
        return homedir;
    }
}

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
            if (argc == 0) {
                // switch to user home dir
                str homedir = getHomeDirectory();
                try {
                    std::filesystem::current_path(homedir);
                    return 400;
                } catch (std::exception &e) {
                    std::cout << "Not a valid directory.\n";
                    return 401;
                }
            } else if (argc == 2) {
                try {
                    if (argv[1].find("~") == 0) {
                        std::cout << "Tilde's are not supported.\n";
                    }
                    std::filesystem::current_path(argv[1]);
                    return 400;
                } catch (std::exception &e) {
                    std::cout << "Not a valid directory.\n";

                    return 401;
                }
            }
        }
        if (argv[0] == "ls") {
            str c = "/bin/";
            for (int i = 0; i < argc; i++) {
                c += argv[i] + " ";
            }
            c += " --color=auto";
            int code = std::system(c.c_str());
            if (code == 32512) {
                std::cout << "Command not found.\n";
            }
            return 100;
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