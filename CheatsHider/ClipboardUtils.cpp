#include "ClipboardUtils.h"

#include <windows.h>
#include <iostream>


void ReplaceClipboardText() {
    if (OpenClipboard(nullptr)) {
        // Получаем текст из буфера обмена
        HANDLE hData = GetClipboardData(CF_UNICODETEXT);
        if (hData != nullptr) {
            wchar_t* clipboardText = static_cast<wchar_t*>(GlobalLock(hData));
            if (clipboardText != nullptr) {
                // Заменяем символы в тексте
                std::wstring newText(clipboardText);
                size_t length = newText.length();
                for (size_t i = 0; i < length; ++i) {
                    switch (newText[i]) {
                    case L'a': newText[i] = L'а'; break;
                    case L'o': newText[i] = L'о'; break;
                    case L'c': newText[i] = L'с'; break;
                    case L'e': newText[i] = L'е'; break;
                    case L'p': newText[i] = L'р'; break;
                    case L'x': newText[i] = L'х'; break;
                        // Добавьте другие замены по необходимости
                    }
                }

                // Очищаем содержимое буфера обмена
                EmptyClipboard();

                // Заменяем текст в буфере обмена
                HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, (newText.length() + 1) * sizeof(wchar_t));
                if (hMem != nullptr) {
                    wcscpy_s(reinterpret_cast<wchar_t*>(GlobalLock(hMem)), newText.length() + 1, newText.c_str());
                    GlobalUnlock(hMem);
                    SetClipboardData(CF_UNICODETEXT, hMem);
                }
            }

            // Освобождаем память, выделенную для текста из буфера
            GlobalUnlock(hData);
        }

        // Закрываем буфер обмена
        CloseClipboard();
    }
    else {
        std::cerr << "Не удалось открыть буфер обмена" << std::endl;
    }
}