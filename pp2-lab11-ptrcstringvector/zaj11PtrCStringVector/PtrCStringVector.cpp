#include <functional>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdexcept>
#include <utility> // std::exchange
#include "PtrCStringVector.h"
using namespace std;


PtrCStringVector::PtrCStringVector()
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    size_ = 0;
    capacity_ = 0;
    data_ = nullptr;
}

PtrCStringVector::PtrCStringVector(const PtrCStringVector &srcPtrCStringVector): PtrCStringVector()
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    for(int i=0; i<srcPtrCStringVector.size_; i++){
        push_back(srcPtrCStringVector.data_[i]);
    }
}

PtrCStringVector::~PtrCStringVector()
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    this->free();
}

PtrCStringVector &PtrCStringVector::operator=(const PtrCStringVector &source)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    this->free();
    for(int i=0; i<source.size_; i++){
        this->push_back(source.data_[i]);
    }
    return *this;
}

PtrCStringVector& PtrCStringVector::operator=(PtrCStringVector&& source)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    this->free();
    for(int i=0; i<source.size_; i++){
        this->push_back(source.data_[i]);
    }
    source.free();
    return *this;
}

void PtrCStringVector::push_back(const char *text2Add)
{
    if(size_>=capacity_){
        reserve(size_+6);/////////////////////////////////////////////////////////////////////////////////////////////////////
    }
    data_[size_] = new char[std::strlen(text2Add)+1];
    std::strcpy(data_[size_], text2Add);
    size_++;
}

PtrCStringVector PtrCStringVector::operator+(const PtrCStringVector &anotherVector) const
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    PtrCStringVector sum;
    for(int i=0; i < this->size_; i++){
        sum.push_back(this->data_[i]);
    }
    for(int i=0; i < anotherVector.size_; i++){
        sum.push_back(anotherVector.data_[i]);
    }
    return sum;
}
char *PtrCStringVector::operator[](size_t index)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    if(index>=size_){
        throw std::out_of_range("");
    }
    char *temp = data_[index];
    return temp;
    //return new char[1]{};
}
const char *PtrCStringVector::operator[](size_t index) const
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    if(index>=size_){
        throw std::out_of_range("");
    }
    const char *temp = data_[index];
    return temp;
    //return "";
}

PtrCStringVector PtrCStringVector::operator&(const PtrCStringVector &rhs) const
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    size_t l = max(rhs.size_, this->size_);
    PtrCStringVector result;
    for(int i=0; i<l; i++){
        char *str = new char[std::strlen(rhs.data_[i]) + std::strlen(this->data_[i]) + 1];
        if(i<this->size_)std::strcpy(str ,this->data_[i]);
        if(i<rhs.size_&&i<this->size_)std::strcat(str, rhs.data_[i]);
        else std::strcpy(str, rhs.data_[i]);
        result.push_back(str);
    }
    return result;
}

void PtrCStringVector::free()
{
    /// @todo sugeruje zaimplementowac, szczegoly w pliku naglowkowym
    for(int i=0; i<size_; i++){
        delete[] data_[i];
    }
    delete data_;
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

void PtrCStringVector::reserve(size_t new_capacity)
{
    if (new_capacity <= capacity_)                     ////////////////////////tutaj coś nie działa jak wyślę mniej niż 6 to nie działa
        return;

    char **temp = new char *[new_capacity];

    for (size_t i = 0; i < size_; ++i)
    {
        temp[i] = data_[i];
    }

    delete[] data_;
    data_ = temp;
    capacity_ = new_capacity;
}
