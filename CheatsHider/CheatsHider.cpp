#include "CheatsHider.h"
#include "FileUtils.h"
#include <algorithm> 
#include <cctype>


CheatsHider::CheatsHider(const std::string& storagePath)
        : storagePath_(storagePath) {}

    // �������� �������� ���� � ������
    void CheatsHider::addForbiddenWord(const std::string& forbiddenWord) {
        forbiddenWords_.push_back(forbiddenWord);
    }

    // �������� �������� ���� � ������
    void CheatsHider::addModPath(const std::string& modsPath) {
        modsPaths_.push_back(modsPath);
    }

    void CheatsHider::checkAndMoveCheats() {
        for (const auto& modsPath : modsPaths_) {
            try {
                if (fs::exists(modsPath) && fs::is_directory(modsPath)) {
                    for (const auto& entry : fs::directory_iterator(modsPath)) {
                        if (fs::is_regular_file(entry)) {
                            for (const auto& word : forbiddenWords_) {
                                // ��������� ��� ����� ��������
                                if (std::equal(word.begin(), word.end(), entry.path().filename().string().begin(),
                                    [](char a, char b) {
                                        return std::toupper(a) == std::toupper(b);
                                    })) {
                                    // �������� ���������� �����
                                    std::string extension = entry.path().extension().string();
                                    if (!extension.empty() && extension != ".") {
                                        moveCheats(entry.path().string());
                                        break;  // Move to the next file after the first match
                                    }
                                }
                            }
                        }
                    }
                }
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }

    // �������� �������� ����� � ������
    void CheatsHider::addFolder(const std::string& folderName) {
        folders_.push_back(folderName);
    }


    // ����������� ����� � ��������� ����� � �������� ���� � ����
    void CheatsHider::cleanCheats() {
        fs::create_directory(storagePath_);

        for (size_t i = 0; i < folders_.size(); ++i) {
            const std::string& folder = folders_[i];
            std::string sourcePath = folder;
            std::string destinationPath = storagePath_ + "/" + std::to_string(i + 1);

            try {
                if (fs::exists(sourcePath) && fs::is_directory(sourcePath)) {
                    fs::rename(sourcePath, destinationPath);
                    recordPath(destinationPath, sourcePath);
                    logPath(sourcePath, true);
                }
            }
            catch (const std::exception& e) {
                std::cerr << "\x1B[31m" << e.what() << "\x1B[0m" << std::endl; // ������� ���� ��� ������
            }
        }
    }

    // ������������ ������������ ����� � ������� ���� �������
    void CheatsHider::uncleanCheats() {
        std::ifstream recordFile(storagePath_ + "/paths.txt");
        if (recordFile.is_open()) {
            std::string line;
            while (std::getline(recordFile, line)) {
                std::size_t pos = line.find(';');
                if (pos != std::string::npos) {
                    std::string destinationPath = line.substr(0, pos);
                    std::string sourcePath = line.substr(pos + 1);

                    try {
                        fs::rename(destinationPath, sourcePath);
                        logPath(sourcePath, true);
                    }
                    catch (const std::exception& e) {
                        std::cerr << "\x1B[31m" << e.what() << "\x1B[0m" << std::endl; // ������� ���� ��� ������
                    }
                }
            }
            recordFile.close();

            fs::remove(storagePath_ + "/paths.txt");
        }
        else {
            std::cerr << "\x1B[31m" << "������: �� ������� ������� ���� �������." << "\x1B[0m" << std::endl; // ������� ���� ��� ������
        }
    }

    // ������� ��� �������������� ����� � ��������� ��� � ����� �����������
    void CheatsHider::moveCheats(const std::string& sourcePath) {
        fs::create_directory(storagePath_);

        // ��������� ���������� ����� �����
        std::string randomFileName = std::to_string(getRandomNumber(1000, 9999)) + "_mod";

        // ����� ���������� �����
        std::string newFileExtension = ".aba";

        // �������� ������ ���� � ��������� ������ � ����� �����������
        std::string destinationPath = storagePath_ + "/" + randomFileName + newFileExtension;

        try {
            fs::rename(sourcePath, destinationPath);
            recordPath(destinationPath, sourcePath);
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    // �������� ���� � ����
    void CheatsHider::recordPath(const std::string& destinationPath, const std::string& sourcePath) {
        std::ofstream recordFile(storagePath_ + "/paths.txt", std::ios::app);
        if (recordFile.is_open()) {
            recordFile << destinationPath << ';' << sourcePath << '\n';
            recordFile.close();
        }
        else {
            std::cerr << "������: �� ������� ������� ���� �������." << std::endl;
        }
    }

