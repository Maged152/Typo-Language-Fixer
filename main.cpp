#include "language_fixer.hpp"

int main(int argc, char **argv) 
{
    const std::wstring text = qlm::ReadClipboardText();

    const qlm::Language lang = qlm::DetectLanguage(text);

    const std::wstring fixed_text = qlm::FixLanguage(text, lang);

    qlm::WriteClipboardText(fixed_text);

    return 0;
}