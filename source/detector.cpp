#include "language_fixer.hpp"

qlm::Language qlm::DetectLanguage(const std::wstring &text)
{
    // Simple heuristic: check for Arabic characters
    for (auto c : text)
    {
        if (c >= 0x0600 && c <= 0x06FF)
        {
            return Language::ARABIC;
        }
    }
    
    return Language::ENGLISH;
}

