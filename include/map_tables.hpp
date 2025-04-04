#pragma once

#include <unordered_map>
#include <string>

namespace qlm
{
    // Map table for Arabic to English transliteration based on keyboard layout
    const std::unordered_map<wchar_t, wchar_t> ArabicToEnglishCharMap = {
        {L'ض', L'q'}, 
        {L'ص', L'w'}, 
        {L'ث', L'e'}, 
        {L'ق', L'r'}, 
        {L'ف', L't'}, 
        {L'غ', L'y'}, 
        {L'ع', L'u'}, 
        {L'ه', L'i'}, 
        {L'خ', L'o'}, 
        {L'ح', L'p'},
        {L'ج', L'['}, 
        {L'د', L']'},
        
        {L'ش', L'a'}, 
        {L'س', L's'}, 
        {L'ي', L'd'}, 
        {L'ب', L'f'}, 
        {L'ل', L'g'}, 
        {L'ا', L'h'}, 
        {L'ت', L'j'}, 
        {L'ن', L'k'}, 
        {L'م', L'l'},
        {L'ك', L';'}, 
        {L'ط', L'\''},
         
        {L'ئ', L'z'}, 
        {L'ء', L'x'}, 
        {L'ؤ', L'c'}, 
        {L'ر', L'v'}, 
        {L'لا', L'b'}, 
        {L'ى', L'n'},
        {L'ة', L'm'}, 
        {L'و', L','}, 
        {L'ز', L'.'}, 
        {L'ظ', L'/'},

        {L'ذ', L'`'}
    };

    const std::unordered_map<wchar_t, wchar_t> EnglishToArabicCharMap = {};
}