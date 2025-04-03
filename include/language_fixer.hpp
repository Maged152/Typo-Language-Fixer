#pragma once

#include "types.hpp"
#include <string>

namespace qlm
{
    // language detector
    Language DetectLanguage(const std::wstring& text);
}