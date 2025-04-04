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

wchar_t FixChar(const wchar_t input_char, const std::unordered_map<wchar_t, wchar_t> &char_map)
{
    auto it = char_map.find(input_char);
    if (it != char_map.end())
    {
        return it->second; // Return the mapped character
    }

    return input_char; // Return the original character if not found in the map
}

std::wstring qlm::FixLanguage(const std::wstring &text, const qlm::Language lang)
{
    std::wstring output_text(text.size(), L' ');

    if (lang == qlm::Language::ARABIC)
    {
        for (size_t i = 0; i < text.size(); i++)
        {
            output_text[i] = FixChar(text[i], qlm::ArabicToEnglishCharMap);
        }
    }
    else if (lang == qlm::Language::ENGLISH)
    {
        for (size_t i = 0; i < text.size(); i++)
        {
            output_text[i] = FixChar(text[i], qlm::EnglishToArabicCharMap);
        }
    }

    return output_text;
}


