#pragma once
#ifndef QUIKTOOLS_QT_PREREL_H
#define QUIKTOOLS_QT_PREREL_H
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
using str = std::string;
namespace fs = std::filesystem;

inline str getHomeDirectory();
inline int saveFile(const str &path, const str &data);
inline str readFile(const str &path);
inline bool directoryExists(const str &path);
inline auto splitVariable(str &input);

#endif
