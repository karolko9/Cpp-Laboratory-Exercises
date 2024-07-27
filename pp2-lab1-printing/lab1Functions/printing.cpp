#include <iostream>
#include <iterator> // ostream_iterator
#include <cstring>
#include <cctype>

using namespace std;

#include "printing.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Funkcje sa do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Funkcje sa do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

int print(int a){
    std::cout << a << std::endl;
}
int print(double a){
    std::cout << a << std::endl;
}
int print(Fraction a){
    std::cout << a.numerator_ << "/" << a.denominator_ << std::endl;
}
int print(const char *a){
    std::cout << a << std::endl;
}
void print(const NotCopyableType& a){
    std::cout << a.number_ << std::endl;
}
void print(const int *tab, const int size) {
    for (int i = 0; i < size - 1; i++) {
        std::cout << *(tab + i) << ", ";
    }
    std::cout << *(tab+size-1) << std::endl;
}
void print(){
    std::cout << std::endl;
}
