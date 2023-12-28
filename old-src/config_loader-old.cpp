#include <iostream>
#include <vector>
#include <fstream>
#include "config_parser.cpp"
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
    str prompt = getPrompt(config);
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