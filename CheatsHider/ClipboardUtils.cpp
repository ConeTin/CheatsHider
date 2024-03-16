#include "ClipboardUtils.h"

#include <windows.h>
#include <iostream>


void ReplaceClipboardText() {
    if (OpenClipboard(nullptr)) {
        // �������� ����� �� ������ ������
        HANDLE hData = GetClipboardData(CF_UNICODETEXT);
        if (hData != nullptr) {
            wchar_t* clipboardText = static_cast<wchar_t*>(GlobalLock(hData));
            if (clipboardText != nullptr) {
                // �������� ������� � ������
                std::wstring newText(clipboardText);
                size_t length = newText.length();
                for (size_t i = 0; i < length; ++i) {
                    switch (newText[i]) {
                    case L'a': newText[i] = L'�'; break;
                    case L'o': newText[i] = L'�'; break;
                    case L'c': newText[i] = L'�'; break;
                    case L'e': newText[i] = L'�'; break;
                    case L'p': newText[i] = L'�'; break;
                    case L'x': newText[i] = L'�'; break;
                        // �������� ������ ������ �� �������������
                    }
                }

                // ������� ���������� ������ ������
                EmptyClipboard();

                // �������� ����� � ������ ������
                HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, (newText.length() + 1) * sizeof(wchar_t));
                if (hMem != nullptr) {
                    wcscpy_s(reinterpret_cast<wchar_t*>(GlobalLock(hMem)), newText.length() + 1, newText.c_str());
                    GlobalUnlock(hMem);
                    SetClipboardData(CF_UNICODETEXT, hMem);
                }
            }

            // ����������� ������, ���������� ��� ������ �� ������
            GlobalUnlock(hData);
        }

        // ��������� ����� ������
        CloseClipboard();
    }
    else {
        std::cerr << "�� ������� ������� ����� ������" << std::endl;
    }
}