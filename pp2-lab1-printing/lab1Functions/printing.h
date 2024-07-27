#ifndef PRINTING_H
#define PRINTING_H

#include <iosfwd>
#include <cstdarg>  // va_list
#include <utility>  // std::forward

/**
 * W zadaniu chodzi o to, aby płynnie przejść z C -> C++,
 * dlatego dzisiejsze zadania sprowadzają się do użycia w C++ tego,
 * co w C było znacznie trudniejsze i bardziej podatne na błędy.
 * C++ umożliwia tworzenie wielu funkcji o tej samej nazwie, różniących się argumentami.
 *
 * Osoby zaawansowane mogą użyć zaawansowanych mechanizmów - szablonów, fold expressions itp
 **/

/**
 * 1. Zdefiniuj funkcję `print`, która przyjmie liczbę całkowitą, wyświetli ją oraz pustą linię.
 * Po zdefiniowaniu jej usuń poniższe makro:
 */
int print(int a);
/**
 * 2. Zdefiniuj funkcję `print`, która przyjmie liczbę rzeczywistą, wyświetli ją oraz pustą linię.
 * Po zdefiniowaniu jej usuń poniższe makro:
 */
int print(double a);
/**
 * 3. Zdefiniuj funkcję `print`, która przyjmie poniższą strukturę Fraction, wyświetli ją (format licznik/mianownik) oraz pustą linię.
 *    - Osoby zaawansowane mogą przeciążyć operator strumienia
 * Po zdefiniowaniu jej usuń poniższe makro:
 */
struct Fraction
{
    int numerator_, denominator_;
};
int print(struct Fraction a);

/**
 * 4. Zdefiniuj funkcję `print`, która przyjmie wskaźnik do tekstu, wyświetli go oraz pustą linię.
 * Po zdefiniowaniu jej usuń poniższe makro:
 */
int print(const char *a);
/**
 * 5. Zdefiniuj funkcję `print`, która przyjmie obiekt niekopiowalnego typu `NotCopyableType`, oraz wyświetli go (tylko jego liczbę) oraz pustą linię.
 *    - Osoby zaawansowane mogą przeciążyć operator strumienia
 * Po zdefiniowaniu jej usuń poniższe makro:
 */
struct NotCopyableType
{
    NotCopyableType(const NotCopyableType&) = delete;
public:
    const int number_; /// public on purpose
};
void print(const NotCopyableType& a);
/**
 * 6. Zdefiniuj funkcję `print`, która przyjmie tablicę liczb (jeden argument to tablica, drugi to rozmiar tablicy).
 *    najlepiej aby liczby byly oddzielone przecinkami i spacjami (", "), ale aby na końcu linii nie było ", "
 *    - osoby zaawansowane mogą spróbować nie używać pętli jawnie
 *    - osoby zaawansowane mogą spróbować nie podawać rozmiaru (zakładamy, że argumentem jest tablica o rozmiarze znanym w trakcie kompilacji)
 * Po zdefiniowaniu jej usuń jedno z makr (zależnie od tego czy podajemy rozmiar tablicy jako drugi argument, czy nie)
 **/
#define UNIMPLEMENTED_printWithArrayOfNumbersWithoutSize
void print(const int *tab, int size);
/**
 * 7. Zdefiniuj funkcję `print`, która nie przyjmuje żadnych argumentów, a wyświetla jedynie nową linię.
 * Po zdefiniowaniu jej usuń makro:
 **/
 void print();

/** 8. [dla zaawansowanych] Zdefiniuj funckje `print`, która przyjmie dowolną ilość dowolnych argumentów dowolnego typu i je wyświetli oddzielając spacją.
 *     Funkcja powinna być zrobiona na jeden z dwóch sposobów:
 *  - korzystając z makr języka C (wtedy nazwijmy ja `print2`), dla uproszczenia niech to bedzie dowolna ilosc intow
 *  - korzystając z fold expressions
 *  Zależnie od wyboru usuń jedno z makr:
 **/
#define UNIMPLEMENTED_printWithAnyArgumentsCStyle
#define UNIMPLEMENTED_printWithAnyArgumentsTemplates


#endif // PRINTING_H
