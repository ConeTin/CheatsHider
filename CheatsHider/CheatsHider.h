#pragma once

#include <string>
#include <vector>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

class CheatsHider {
public:
    std::string storagePath_;
    std::vector<std::string> folders_;
    std::vector<std::string> modsPaths_;
    std::vector<std::string> forbiddenWords_;

    CheatsHider(const std::string& storagePath);

    void addForbiddenWord(const std::string& forbiddenWord);
    void addModPath(const std::string& modsPath);
    void checkAndMoveCheats();
    void addFolder(const std::string& folderName);
    void cleanCheats();
    void uncleanCheats();

private:
    void moveCheats(const std::string& sourcePath);
    void recordPath(const std::string& destinationPath, const std::string& sourcePath);
};