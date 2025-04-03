#include "language_fixer.hpp"
#include <gtest/gtest.h>
#include <tuple>

// Define a test fixture class for parameterized tests
class LanguageDetectionTest : public ::testing::TestWithParam<std::tuple<std::wstring, qlm::Language>> {};

// Parameterized test using TEST_P
TEST_P(LanguageDetectionTest, DetectLanguage) {
    // Extract parameters
    auto [text, expected] = GetParam();

    // Call the function and check the result
    const qlm::Language detected = qlm::DetectLanguage(text);
    EXPECT_EQ(detected, expected);
}

// Define test cases as parameters
INSTANTIATE_TEST_SUITE_P(
    LanguageDetectionTests,
    LanguageDetectionTest,
    ::testing::Values(
        std::make_tuple(L"Hello, how are you?", qlm::Language::ENGLISH),
        std::make_tuple(L"مرحبا كيف حالك؟", qlm::Language::ARABIC)
    )
);