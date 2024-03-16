#pragma once

#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include <cstdlib>
#include <thread>
#include <future>
#include <random>
#include <chrono>
#include <limits>
#include <conio.h>
#include <psapi.h>
#include <cstring>
#include <tlhelp32.h>

namespace fs = boost::filesystem;

void searchFile(const fs::path& directory, const std::string& targetFileName, std::vector<fs::path>& foundFiles);
void searchDirectory(const fs::path& directory, const std::string& targetDirectoryName, std::vector<fs::path>& foundDirectories);
void renameFilesAndDirectories(const std::vector<fs::path>& files, const std::vector<fs::path>& directories, const std::string& newFileName, const std::string& newDirectoryName);
void logPath(const fs::path& path, bool success);
int getRandomNumber(int min, int max);