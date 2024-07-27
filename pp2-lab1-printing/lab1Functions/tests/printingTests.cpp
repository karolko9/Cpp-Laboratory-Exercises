#include <iostream>
#include <type_traits>
#include <gtest/gtest.h>

#if __has_include("../printing.h")
    #include "../printing.h"
#endif


namespace
{
using namespace std;
using namespace ::testing;

struct CoutBufferSentinel
{
    std::streambuf *oldCoutBuffer = nullptr;
    std::ostringstream newBuffer;

    CoutBufferSentinel()
    {
        oldCoutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(newBuffer.rdbuf());
    }

    ~CoutBufferSentinel()
    {
        std::cout.rdbuf(oldCoutBuffer);
    }

    auto getText() const
    {
        return newBuffer.str();
    }
};
} // namespace

struct PrintingTester : public ::testing::Test
{
};

TEST_F(PrintingTester, singleInteger)
{
    #ifdef UNIMPLEMENTED_printWithSingleInteger
        ADD_FAILURE() << "Function not implemented";
    #else
        CoutBufferSentinel coutSentinel; // to catch std::cout

        int i = 44;
        auto expectedOutput = std::to_string(i) + '\n';

        print(i);

        ASSERT_EQ(expectedOutput, coutSentinel.getText());
    #endif
}

TEST_F(PrintingTester, singleDouble)
{
    #ifdef UNIMPLEMENTED_printWithSingleDouble
        ADD_FAILURE() << "Function not implemented";
    #else
        CoutBufferSentinel coutSentinel; // to catch std::cout

        double d = 128.75;
        auto expectedOutput = "128.75\n";

        print(d);

        ASSERT_EQ(expectedOutput, coutSentinel.getText());
    #endif
}

TEST_F(PrintingTester, printFraction)
{
    #ifdef UNIMPLEMENTED_printWithSingleFraction
        ADD_FAILURE() << "Function not implemented";
    #else
        CoutBufferSentinel coutSentinel; // to catch std::cout

        constexpr int numerator = 3, denominator = 4;
        Fraction fraction{numerator, denominator};
        auto expectedOutput = std::to_string(numerator) + '/' + std::to_string(denominator) + "\n";

        print(fraction);

        ASSERT_EQ(expectedOutput, coutSentinel.getText());
    #endif
}

TEST_F(PrintingTester, printCstring)
{
    #ifdef UNIMPLEMENTED_printWithSingleCString
        ADD_FAILURE() << "Function not implemented";
    #else
        CoutBufferSentinel coutSentinel; // to catch std::cout

        constexpr const char* text = "Musicie od siebie wymagac, nawet gdyby inni od Was nie wymagali";

        auto expectedOutput = std::string(text) + "\n";

        print(text);

        ASSERT_EQ(expectedOutput, coutSentinel.getText());
    #endif
}

TEST_F(PrintingTester, printNotCopyableObject)
{
    #ifdef UNIMPLEMENTED_printWithSingleNotCopyableObject
        ADD_FAILURE() << "Function not implemented";
    #else
        CoutBufferSentinel coutSentinel; // to catch std::cout

        constexpr int value = 2005;
        const NotCopyableType nct{value};

        auto expectedOutput = std::to_string(value) + "\n";

        print(nct);

        ASSERT_EQ(expectedOutput, coutSentinel.getText());
    #endif
}

TEST_F(PrintingTester, printArrayOfNumbers)
{
    const int arrayOfNumbers[] = {967, 972, 979, 981, 985, 992, 995};
    constexpr size_t numbersCount [[maybe_unused]] = sizeof(arrayOfNumbers) / sizeof(arrayOfNumbers[0]);
    const string expectedOutput = "967, 972, 979, 981, 985, 992, 995\n";
    const string expectedOutputAlternative = "967, 972, 979, 981, 985, 992, 995, \n";

    #if defined(UNIMPLEMENTED_printWithArrayOfNumbersAndSize) && defined(UNIMPLEMENTED_printWithArrayOfNumbersWithoutSize)
        ADD_FAILURE() << "Function not implemented";
    #elif !defined(UNIMPLEMENTED_printWithArrayOfNumbersAndSize)
        CoutBufferSentinel coutSentinel; // to catch std::cout

        print(arrayOfNumbers, numbersCount);

        ASSERT_TRUE(expectedOutput == coutSentinel.getText() || expectedOutputAlternative == coutSentinel.getText())
                << "Expected '" << coutSentinel.getText() << "' to be: '" << expectedOutput
                << "', or '" << expectedOutputAlternative << "'";
    #elif !defined(UNIMPLEMENTED_printWithArrayOfNumbersWithoutSize)
        CoutBufferSentinel coutSentinel; // to catch std::cout

        print(arrayOfNumbers);

        ASSERT_TRUE(expectedOutput == coutSentinel.getText() || expectedOutputAlternative == coutSentinel.getText())
                << "Expected '" << coutSentinel.getText() << "' to be: '" << expectedOutput
                << "', or '" << expectedOutputAlternative << "'";
    #endif
}

TEST_F(PrintingTester, printWithoutArgument)
{
    #ifdef UNIMPLEMENTED_printWithoutArguments
        ADD_FAILURE() << "Function not implemented";
    #else
        CoutBufferSentinel coutSentinel; // to catch std::cout

        auto expectedOutput = "\n";

        print();

        ASSERT_EQ(expectedOutput, coutSentinel.getText());
    #endif
}

#ifndef UNIMPLEMENTED_printWithAnyArgumentsCStyle
TEST_F(PrintingTester, printAnyNumberOfIntsWithMacros)
{
    CoutBufferSentinel coutSentinel; // to catch std::cout

    constexpr const int argumentsCount = 3;

    const int i = 44, j = 222, k = 0;

    auto expectedOutput = "44 222 0 \n";

    print2(argumentsCount, i, j, k);

    ASSERT_EQ(expectedOutput, coutSentinel.getText());
}
#endif

#ifndef UNIMPLEMENTED_printWithAnyArgumentsTemplates
TEST_F(PrintingTester, printAnyArgumentsWithFoldExpressions)
{
    CoutBufferSentinel coutSentinel; // to catch std::cout

    const int i = 44;
    const double d = 222.125;
    const std::string text = "przykladowy_tekst";

    auto expectedOutput = "222.125 przykladowy_tekst 44\n";

    print(d, text, i);

    ASSERT_EQ(expectedOutput, coutSentinel.getText());
}
#endif
