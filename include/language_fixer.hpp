#pragma once

#include "types.hpp"
#include "map_tables.hpp"

namespace qlm
{
    // language detector
    Language DetectLanguage(const std::wstring& text);

    // language fixer
    std::wstring FixLanguage(const std::wstring& text, const Language lang);

    // Clipboard functions
    std::wstring ReadClipboardText();
    void WriteClipboardText(const std::wstring& text);
}