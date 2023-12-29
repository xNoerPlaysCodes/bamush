#ifndef BAMUSH_CONFIG_LOADER_H
#define BAMUSH_CONFIG_LOADER_H

#include <iostream>
#include <vector>
#include <fstream>
#include "config_parser.h"
//#include "../../libs/qt-prerel.cpp"
using str = std::string;
std::vector<str> loadPrompt();
str loadConfig();

#endif
