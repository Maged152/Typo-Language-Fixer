#include "language_fixer.hpp"
#include <gtest/gtest.h>
#include <tuple>
#include <iostream>

// Define a test fixture class for parameterized tests
class FixLanguageTest : public ::testing::TestWithParam<std::tuple<std::wstring, qlm::Language, std::wstring>> {};

// Parameterized test using TEST_P
TEST_P(FixLanguageTest, FixLanguage) {
    // Extract parameters
    auto [input_text, language, expected_output] = GetParam();

    // Call the function and check the result
    const std::wstring fixed_text = qlm::FixLanguage(input_text, language);
    EXPECT_EQ(fixed_text, expected_output);
}

// Define test cases as parameters
INSTANTIATE_TEST_SUITE_P(
    FixLanguageTests,
    FixLanguageTest,
    ::testing::Values(
        // Test Arabic to English transliteration
        std::make_tuple(L"اثممخ", qlm::Language::ARABIC, L"hello"), // Arabic "ضصث" -> English "qwe"
        std::make_tuple(L"ؤشف", qlm::Language::ARABIC, L"cat") // Arabic "قفغ" -> English "rty"

        // Test English to Arabic transliteration
        // std::make_tuple(L"qwe", qlm::Language::ENGLISH, L"ضصث"), // English "qwe" -> Arabic "ضصث"
        // std::make_tuple(L"rty", qlm::Language::ENGLISH, L"قفغ"), // English "rty" -> Arabic "قفغ"

        // // Test unmapped characters (should remain unchanged)
        // std::make_tuple(L"123", qlm::Language::ARABIC, L"123"), // Numbers remain unchanged
        // std::make_tuple(L"123", qlm::Language::ENGLISH, L"123") // Numbers remain unchanged
    )
);