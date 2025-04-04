#ifdef _WIN32
#include <windows.h>
#endif

#include "language_fixer.hpp"

std::wstring qlm::ReadClipboardText()
{
#ifdef _WIN32
    // Open the clipboard
    if (!OpenClipboard(nullptr)) 
    {
        return L""; // Return an empty string if the clipboard cannot be opened
    }

    // Get the clipboard data in Unicode text format
    HANDLE h_data = GetClipboardData(CF_UNICODETEXT);
    if (h_data == nullptr) 
    {
        CloseClipboard();
        return L""; // Return an empty string if no text is available
    }

    // Lock the clipboard data to get a pointer to the text
    wchar_t* p_text = static_cast<wchar_t*>(GlobalLock(h_data));
    if (p_text == nullptr) 
    {
        CloseClipboard();
        return L""; // Return an empty string if the text cannot be locked
    }

    // Copy the text into a std::wstring
    std::wstring clipboard_text(p_text);

    // Unlock and close the clipboard
    GlobalUnlock(h_data);
    CloseClipboard();

    return clipboard_text;
#else
    // TODO: Implement clipboard reading for non-Windows platforms
    return L""; // Return an empty string if not on Windows
#endif
}

void qlm::WriteClipboardText(const std::wstring& text)
{
#ifdef _WIN32
    if (!OpenClipboard(nullptr))
    {
        return; // Fail silently if the clipboard cannot be opened
    }

    EmptyClipboard();

    size_t size = (text.size() + 1) * sizeof(wchar_t);
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, size);
    if (hMem == nullptr)
    {
        CloseClipboard();
        return; // Fail silently if memory allocation fails
    }

    void* pMem = GlobalLock(hMem);
    memcpy(pMem, text.c_str(), size);
    GlobalUnlock(hMem);

    SetClipboardData(CF_UNICODETEXT, hMem);
    CloseClipboard();
#endif
}