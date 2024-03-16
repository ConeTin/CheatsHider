#include "FileUtils.h"

// Генератор случайных чисел
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// Генерация случайного числа в диапазоне
int getRandomNumber(int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(rng);
}

void logPath(const fs::path& path, bool success) {
    if (success) {
        std::cout << "\x1B[32m" << path << "\x1B[0m" << std::endl; // Зелёный цвет для успешных операций
    }
    else {
        std::cerr << "\x1B[31m" << path << "\x1B[0m" << std::endl; // Красный цвет для ошибок
    }
}

void searchFile(const fs::path& directory, const std::string& targetFileName, std::vector<fs::path>& foundFiles) {
    try {
        for (const auto& entry : fs::recursive_directory_iterator(directory, fs::directory_options::skip_permission_denied | fs::directory_options::none)) {
            try {
                if (fs::is_regular_file(entry) && entry.path().filename() == targetFileName) {
                    foundFiles.push_back(entry.path());
                    logPath(entry.path(), true);
                }
            }
            catch (const fs::filesystem_error& e) {
                logPath(entry.path(), false);
            }
        }
    }
    catch (const fs::filesystem_error& e) {
        logPath(directory, false);
    }
}

void searchDirectory(const fs::path& directory, const std::string& targetDirectoryName, std::vector<fs::path>& foundDirectories) {
    try {
        for (const auto& entry : fs::recursive_directory_iterator(directory, fs::directory_options::skip_permission_denied | fs::directory_options::none)) {
            try {
                if (fs::is_directory(entry) && entry.path().filename() == targetDirectoryName) {
                    foundDirectories.push_back(entry.path());
                    logPath(entry.path(), true);
                }
            }
            catch (const fs::filesystem_error& e) {
                logPath(entry.path(), false);
            }
        }
    }
    catch (const fs::filesystem_error& e) {
        logPath(directory, false);
    }
}

void renameFilesAndDirectories(const std::vector<fs::path>& files, const std::vector<fs::path>& directories,
    const std::string& newFileName, const std::string& newDirectoryName) {

    std::vector<std::future<void>> futures;

    for (const auto& file : files) {
        futures.push_back(std::async(std::launch::async, [&file, &newFileName] {
            try {
                fs::path newPath = file.parent_path() / newFileName;
                fs::rename(file, newPath);
                logPath(newPath, true);
            }
            catch (const fs::filesystem_error& e) {
                logPath(file, false);
            }
            }));
    }

    for (const auto& directory : directories) {
        futures.push_back(std::async(std::launch::async, [&directory, &newDirectoryName] {
            try {
                fs::path newPath = directory.parent_path() / newDirectoryName;
                fs::rename(directory, newPath);
                logPath(newPath, true);
            }
            catch (const fs::filesystem_error& e) {
                logPath(directory, false);
            }
            }));
    }

    // Ждем завершения всех задач
    for (auto& future : futures) {
        future.get();
    }
}
