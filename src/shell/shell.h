//
// Created by noerlol on 3/12/23.
//
#pragma once
#ifndef BAMUSH_SHELL_H
#define BAMUSH_SHELL_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>
#include <readline/history.h>
#include <readline/readline.h>
#include "../command_handler/command_handler.h"
#include "../config/config_loader.h"

using str = std::string;
namespace fs = std::filesystem;

void loadHistory();

#endif //BAMUSH_SHELL_H
