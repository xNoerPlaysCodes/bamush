#include "config_loader.h"
inline str getHomeDirectory() {
    const char* homedir = std::getenv("HOME");
    if (homedir == nullptr) {
        return ".";
    } else {
        return homedir;
    }
}
using str = std::string;
std::vector<str> loadPrompt() { // .bamushrc loading
    str homedir = getHomeDirectory();
    str config;
    str path = (homedir + "/.bamush_prompt");
    std::fstream file(path);
    if (file.is_open()) {
        str line;
        while(getline(file,line)) {
            config += line + "\n";
        }
    }
    file.close();
    std::vector<str> configa;
    configa.emplace_back(config); // PROMPT
    return configa;
}

str loadConfig() {
    str homedir = getHomeDirectory();
    str config;
    str path = (homedir + "/.bamushrc");
    std::fstream file(path);
    if (file.is_open()) {
        str line;
        while(getline(file,line)) {
            config += line + "\n";
        }
    }
    file.close();
    return config;
}