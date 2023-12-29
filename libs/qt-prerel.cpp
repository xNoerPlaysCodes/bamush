#include "qt-prerel.h"
using str = std::string;
namespace fs = std::filesystem;

inline str getHomeDirectory() {
    const char* homedir = std::getenv("HOME");
    if (homedir == nullptr) {
        return ".";
    } else {
        return homedir;
    }
}

inline int saveFile(const str &path, const str &data) {
    std::ofstream file;
    file.open(path);
    if (file.is_open()) {
        file << data << '\n';
    } else {
        return 1;
    }
    file.close();
    return 0;
}

inline str readFile(const str &path) {
    std::ifstream file;
    file.open(path);
    if (file.is_open()) {
        int lineCount = 0;
        str line;

        while (std::getline(file, line)) {
            lineCount++;
        }
        return line;
    } else {
        return "FILE_NOT_FOUND";
    }
}

/*
str listContentsOfDirectory(const str &path) {
    str list;
    for (const auto &entry : fs::directory_iterator(path)) {
        list += entry.path() + "\n".c_str();
    }
    return list;
}
*/

inline bool directoryExists(const str &path) {
    return fs::exists(path) && fs::is_directory(path);
}

inline auto splitVariable(str &input) {
    std::istringstream iss(input);
    std::vector<std::string> args;
    std::string arg;
    while (iss >> arg) {
        args.push_back(arg);
    }
    return args;
}
