#include "Everything.h"
#include <windows.h>
#include <tlhelp32.h>

bool isEverythingRunning() {
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (Process32First(snapshot, &entry)) {
        do {
            if (_wcsicmp(entry.szExeFile, L"Everything.exe") == 0) {
                CloseHandle(snapshot);
                return true; // Процесс "Everything" запущен
            }
        } while (Process32Next(snapshot, &entry));
    }

    CloseHandle(snapshot);
    return false; // Процесс "Everything" не запущен
}
