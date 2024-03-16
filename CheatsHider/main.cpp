#include "CheatsHider.h"
#include "FileUtils.h"
#include "ClipboardUtils.cpp"
#include "Everything.h"

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

using std::max;

namespace fs = boost::filesystem;

int main()
{
    SetConsoleTitle(L"CheatsHider - Скрой все свои читы");

    bool runEverything = false;

    auto hideConsoleWindow = []() {
        HWND consoleWindow = GetConsoleWindow();
        ShowWindow(consoleWindow, SW_HIDE);
        };

    auto showConsoleWindow = []() {
        HWND consoleWindow = GetConsoleWindow();
        ShowWindow(consoleWindow, SW_SHOW);
        };

    setlocale(LC_ALL, "Russian");

    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOW);


    while (true) {
        char key;

        std::cout << " ______     __  __     ______     ______     ______   ______        __  __     __     _____     ______     ______    \n"
            "/\\  ___\\   /\\ \\_\\ \\   /\\  ___\\   /\\  __ \\   /\\__  _\\ /\\  ___\\      /\\ \\_\\ \\   /\\ \\   /\\  __-.  /\\  ___\\   /\\  == \\   \n"
            "\\ \\ \\____  \\ \\  __ \\  \\ \\  __\\   \\ \\  __ \\  \\/_/\\ \\/ \\ \\___  \\     \\ \\  __ \\  \\ \\ \\  \\ \\ \\/\\ \\ \\  __\\   \\ \\  __<   \n"
            " \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\ \\_\\    \\ \\_\\  \\/\\_____\\     \\ \\_\\ \\_\\  \\ \\_\\  \\ \\____-  \\ \\_____\\  \\ \\_\\ \\_\\ \n"
            "  \\/_____/   \\/_/\\/_/   \\/_____/   \\/_/\\/_/     \\/_/   \\/_____/      \\/_/\\/_/   \\/_/   \\/____/   \\/_____/   \\/_/ /_/ \n";

        std::cout <<
            "\n"
            "Выбери действие\n"
            "1 - Скрыть все папки читов\n"
            "2 - Скрыть папки \"Майнкрафта\" которые находит читхантер\n"
            "3 - Вернуть все папки читов\n"
            "4 - Вернуть все папки \"Майнкрафта\" которые находит читхантер\n"
            "5 - Запустить защиту от Everything (Читхайдер скроется)\n"
            "6 - Выход\n"
            "Введите число 1-5\n"
            "Ваш выбор: "
            ;

        std::string userInput;
        std::cin >> userInput;
        

        CheatsHider cheatsHider("C:/CheatsHider");

        cheatsHider.addForbiddenWord("Inertia");
        cheatsHider.addForbiddenWord("Impact");
        cheatsHider.addForbiddenWord("Zamorozka");
        cheatsHider.addForbiddenWord("FreeCam");
        cheatsHider.addForbiddenWord("HitBox");
        cheatsHider.addForbiddenWord("AutoTotem");
        cheatsHider.addForbiddenWord("MiniMap");
        cheatsHider.addForbiddenWord("Xray");
        cheatsHider.addForbiddenWord("Esp");
        cheatsHider.addForbiddenWord("Wallhack");
        cheatsHider.addForbiddenWord("TutorialClient");
        cheatsHider.addForbiddenWord("SuperClient");
        cheatsHider.addForbiddenWord("Unsurpassed");
        cheatsHider.addForbiddenWord("ElytraSwap");
        cheatsHider.addForbiddenWord("Health");
        cheatsHider.addForbiddenWord("Wurst");
        cheatsHider.addForbiddenWord("Akrien");
        cheatsHider.addForbiddenWord("Via");
        cheatsHider.addForbiddenWord("AutoBuy");
        cheatsHider.addForbiddenWord("Excellent");
        cheatsHider.addForbiddenWord("FDP");
        cheatsHider.addForbiddenWord("Expensive");
        cheatsHider.addForbiddenWord("avtobuy");
        cheatsHider.addForbiddenWord("archware");
        cheatsHider.addForbiddenWord("loader");
        cheatsHider.addForbiddenWord(".jar");
        cheatsHider.addForbiddenWord(".exe");
        cheatsHider.addForbiddenWord("free");
        cheatsHider.addForbiddenWord("cley");
        cheatsHider.addForbiddenWord("mcp");
        cheatsHider.addForbiddenWord("minecraft");
        cheatsHider.addForbiddenWord("game");
        cheatsHider.addForbiddenWord("java");
        cheatsHider.addForbiddenWord("sirius");
        cheatsHider.addForbiddenWord("celka");
        cheatsHider.addForbiddenWord("celestial");

        char* username;
        size_t len;

        // Используем _dupenv_s для безопасного получения значения переменной окружения "USERNAME"
        if (_dupenv_s(&username, &len, "USERNAME") == 0 && username != nullptr) {
            // Преобразуем указатель в std::string
            std::string usernameStr(username);
            // Добавляем папки в список


            // Папки на диске
            cheatsHider.addFolder("C:/HeavlyAntiLeak");
            cheatsHider.addFolder("C:/Rockstar");
            cheatsHider.addFolder("C:/RockAntiLeak");
            cheatsHider.addFolder("C:/AkrienAntiLeak");
            cheatsHider.addFolder("C:/Celestial");
            cheatsHider.addFolder("C:/Nurik");
            cheatsHider.addFolder("C:/Nursultan");
            cheatsHider.addFolder("C:/Expensive");
            cheatsHider.addFolder("C:/Excellent");
            cheatsHider.addFolder("C:/Nova");
            cheatsHider.addFolder("C:/Wexside");
            cheatsHider.addFolder("C:/DeadCode");
            cheatsHider.addFolder("C:/Wild");
            cheatsHider.addFolder("C:/Arbuz");
            cheatsHider.addFolder("C:/Avalon");
            cheatsHider.addFolder("C:/Aurora");
            cheatsHider.addFolder("C:/Dark");
            cheatsHider.addFolder("C:/DarkProject");
            cheatsHider.addFolder("C:/Epfirium");
            cheatsHider.addFolder("C:/Wissend");
            cheatsHider.addFolder("C:/Vendex");
            cheatsHider.addFolder("C:/Verist");
            cheatsHider.addFolder("C:/Rich");
            cheatsHider.addFolder("C:/Carbonara");
            cheatsHider.addFolder("C:/Celka");

            // Все возможные папки майна
            std::vector<std::string> gamePaths = {
                "C:/Users/" + usernameStr + "/AppData/Roaming/.tlauncher/legacy/Minecraft/game/",
                "C:/Users/" + usernameStr + "/AppData/Roaming/.minecraft/",
                "C:/Games/Minecraft/"
            };

            cheatsHider.addModPath("C:/Users/" + usernameStr + "/Downloads");

            for (const auto& gamePath : gamePaths) {
                // Папки с модами
                cheatsHider.addModPath(gamePath + "mods");

                // Папки в папке майнкрафта
                cheatsHider.addFolder(gamePath + "WintWare");
                cheatsHider.addFolder(gamePath + "NeverHook");
                cheatsHider.addFolder(gamePath + "augustus");
                cheatsHider.addFolder(gamePath + "meta");
                cheatsHider.addFolder(gamePath + "wissend");
                cheatsHider.addFolder(gamePath + "Rockstar Free");
                cheatsHider.addFolder(gamePath + "FDPCLIENT\-1.8");
                cheatsHider.addFolder(gamePath + "Gothaj");
                cheatsHider.addFolder(gamePath + "wild");
                cheatsHider.addFolder(gamePath + "Inertia");
                cheatsHider.addFolder(gamePath + "Impact");
                cheatsHider.addFolder(gamePath + "StarLine");
                cheatsHider.addFolder(gamePath + "Rise");
                cheatsHider.addFolder(gamePath + "arbuz");
                cheatsHider.addFolder(gamePath + "Exclusive");
                cheatsHider.addFolder(gamePath + "Epfirium");
                cheatsHider.addFolder(gamePath + "Dark");
                cheatsHider.addFolder(gamePath + "WintWare");
                cheatsHider.addFolder(gamePath + "Celestial");
                cheatsHider.addFolder(gamePath + "versions/Sirius");
                cheatsHider.addFolder(gamePath + "versions/wild");
                cheatsHider.addFolder(gamePath + "versions/Avalon");
                cheatsHider.addFolder(gamePath + "versions/Augustus");
                cheatsHider.addFolder(gamePath + "versions/Celestial");
                cheatsHider.addFolder(gamePath + "versions/Avalon");
                cheatsHider.addFolder(gamePath + "versions/Expensive");
                cheatsHider.addFolder(gamePath + "versions/Aurora");
                cheatsHider.addFolder(gamePath + "versions/Rockstar");
                cheatsHider.addFolder(gamePath + "versions/Exclusive");
                cheatsHider.addFolder(gamePath + "versions/Vendex");
                cheatsHider.addFolder(gamePath + "versions/Verist");
                cheatsHider.addFolder(gamePath + "versions/Wissend");
                cheatsHider.addFolder(gamePath + "versions/Gothaj");
                cheatsHider.addFolder(gamePath + "versions/Spirit");
                cheatsHider.addFolder(gamePath + "versions/StarLine");

                // Утилиты
                cheatsHider.addFolder(gamePath + "baritone");
                cheatsHider.addFolder(gamePath + "ViaMCP");
                cheatsHider.addFolder(gamePath + "ViaLoader");
            }
        }

        std::vector<fs::path> foundFiles;
        std::vector<fs::path> foundDirectories;

        if (userInput == "1") {
            cheatsHider.cleanCheats();
            cheatsHider.checkAndMoveCheats();

            system("attrib +s +h C:/CheatsHider");
        }
        else if (userInput == "2") {
            std::string targetFileName = "servers.dat";
            std::string targetDirectoryName = "resourcepacks";
            std::string newFileName = "srv.dat";
            std::string newDirectoryName = "rsaldk1s";
            std::vector<std::thread> threads;

            for (char drive = 'C'; drive <= 'Z'; ++drive) {
                fs::path searchDirectoryPath = fs::path(std::string(1, drive) + ":/");

                //std::cout << "Поиск на диске: " << searchDirectoryPath << std::endl;

                // Создаем потоки и добавляем их в вектор
                threads.emplace_back(searchFile, searchDirectoryPath, targetFileName, std::ref(foundFiles));
                threads.emplace_back(searchDirectory, searchDirectoryPath, targetDirectoryName, std::ref(foundDirectories));
            }

            // Дожидаемся завершения всех потоков
            for (auto& thread : threads) {
                thread.join();
            }

            renameFilesAndDirectories(foundFiles, foundDirectories, newFileName, newDirectoryName);

        }
        else if (userInput == "3") {
            cheatsHider.uncleanCheats();
        }
        else if (userInput == "4") {
            std::string targetFileName = "srv.dat";
            std::string targetDirectoryName = "rsaldk1s";
            std::string newFileName = "servers.dat";
            std::string newDirectoryName = "resourcepacks";
            std::vector<std::thread> threads;

            for (char drive = 'C'; drive <= 'Z'; ++drive) {
                fs::path searchDirectoryPath = fs::path(std::string(1, drive) + ":/");

                //std::cout << "Поиск на диске: " << searchDirectoryPath << std::endl;

                // Создаем потоки и добавляем их в вектор
                threads.emplace_back(searchFile, searchDirectoryPath, targetFileName, std::ref(foundFiles));
                threads.emplace_back(searchDirectory, searchDirectoryPath, targetDirectoryName, std::ref(foundDirectories));
            }

            // Дожидаемся завершения всех потоков
            for (auto& thread : threads) {
                thread.join();
            }

            renameFilesAndDirectories(foundFiles, foundDirectories, newFileName, newDirectoryName);

        }
        else if (userInput == "5") {
            ShowWindow(hwnd, SW_HIDE);

            std::thread clipboardThread([hideConsoleWindow, showConsoleWindow, &runEverything]() {
                while (true) {
                    ReplaceClipboardText();
                    // Здесь вызовите функции для обработки буфера обмена
                    std::this_thread::sleep_for(std::chrono::seconds(1));

                    if (isEverythingRunning())
                        runEverything = true;

                    if (!isEverythingRunning() && runEverything) {
                        showConsoleWindow(); // Показываем консольное окно
                        break;
                    }
                }
                });

            // Дождитесь завершения потока
            clipboardThread.join();
        }
        else if (userInput == "6") {
            break;
        }



        std::cin.clear();

        system("pause");

        std::cin.clear();

        system("cls");
    }
}