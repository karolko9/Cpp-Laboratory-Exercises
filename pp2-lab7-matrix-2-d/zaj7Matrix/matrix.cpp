#include <iostream>
#include <string>
#include <stdexcept> // std::out_of_range()
#include <iomanip>   // std::setw()

using namespace std;

#include "matrix.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix &matrix) {
    matrix_[0][0] = matrix.matrix_[0][0];
    matrix_[1][1] = matrix.matrix_[1][1];
    matrix_[0][1] = matrix.matrix_[0][1];
    matrix_[1][0] = matrix.matrix_[1][0];
}

TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement (*matrix)[2]) {
    for (int i = 0; i < size_; i++) {
        for (int j = 0; j < size_; j++) {
            matrix_[i][j] = matrix[i][j];
        }
    }
}

TwoDimensionMatrix::TwoDimensionMatrix() {
    matrix_[0][0] = 0;
    matrix_[1][1] = 0;
    matrix_[0][1] = 0;
    matrix_[1][0] = 0;
}

TwoDimensionMatrix& TwoDimensionMatrix::operator=(const TwoDimensionMatrix& other) {
    if (this != &other) {
        for (size_t i = 0; i < size_; ++i) {
            for (size_t j = 0; j < size_; ++j) {
                matrix_[i][j] = other.matrix_[i][j];
            }
        }
    }
    return *this;
}

TwoDimensionMatrix TwoDimensionMatrix::operator+(const TwoDimensionMatrix& other) const {
    TwoDimensionMatrix result;
    for (size_t i = 0; i < size_; ++i) {
        for (size_t j = 0; j < size_; ++j) {
            result.matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
        }
    }
    return result;
}

TwoDimensionMatrix& TwoDimensionMatrix::operator*=(MatrixElement number) {
    for (size_t i = 0; i < size_; ++i) {
        for (size_t j = 0; j < size_; ++j) {
            matrix_[i][j] *= number;
        }
    }
    return *this;
}



TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix &matrix) const {
    TwoDimensionMatrix result;
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            result.matrix_[i][j] = ((matrix.matrix_[i][j] + matrix_[i][j])==0)&&(matrix_[i][j]!=0);
        }
    }
    return result;
}

int &TwoDimensionMatrix::operator()(size_t row, size_t col) {
    return matrix_[row][col];
}

std::ostream &operator<<(ostream &os, const TwoDimensionMatrix &mat) {
    os << "[" << mat.matrix_[0][0] << " " << mat.matrix_[0][1] << "]" << std::endl;
    os << "[" << mat.matrix_[1][0] << " " << mat.matrix_[1][1] << "]" << std::endl;
    return os;
}

std::istream &operator>>(istream &is, TwoDimensionMatrix &mat) {
    is >> mat.matrix_[0][0] >> mat.matrix_[0][1] >> mat.matrix_[1][0] >> mat.matrix_[1][1];
    return is;
}
const MatrixElement* TwoDimensionMatrix::operator[](size_t i) const {
    return matrix_[i];
}
MatrixElement* TwoDimensionMatrix::operator[](size_t i)  {
    return matrix_[i];
}

TwoDimensionMatrix::operator size_t() const {
    return size();
}
