#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility> // std::exchange
using namespace std;

#include "simpleString.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

















void SimpleString::append(const SimpleString& string){
    size_t new_size = size_ + string.size_;
    char* temp = new char[new_size + 1];
    std::strcpy(temp, data_);
    std::strcat(temp, string.data_);
    delete[] data_;
    data_ = temp;
    size_ = new_size;
}
void SimpleString::assign(const char* new_text){
    size_=0;
    while(new_text[size_]!='\0'){
        size_++;
    }
    delete data_;
    data_ = new char[size_ + 1];
    for(int i=0; i<size_; i++){
        data_[i]=new_text[i];
    }
    data_[size_]='\0';
    capacity_=size_;
}
int SimpleString::compare(const SimpleString& string1, bool case_sensitive) const {
    int result = 0;
    if (case_sensitive) {
        result = std::strcmp(data_, string1.data_);
    }
    else {
        char* temp1 = new char[size_ + 1];
        char* temp2 = new char[string1.size_ + 1];
        for(int i = 0; i < size_; i++) {
            temp1[i] = std::tolower(data_[i]);
        }
        for(int i = 0; i < string1.size_; i++){
            temp2[i] = std::tolower(string1.data_[i]);
        }
        temp1[size_]='\0';
        temp2[string1.size_]='\0';
        result = std::strcmp(temp1, temp2);
        delete[] temp1;
        delete[] temp2;
    }
    if (result == 0) {
        return 0;
    }
    else if (result < 0) {
        return -1;
    }
    else {
        return 1;
    }
}
SimpleString SimpleString::substr(size_t pos, size_t count) const {
    SimpleString* string = new SimpleString;
    string->data_= new char[size_-pos];
    for(int i=pos; i<size_; i++){
        string->data_[i-pos]=data_[i];
    }
    string->size_=size_-pos;
    string->data_[size_-pos]='\0';
    return *string;
}
SimpleString::~SimpleString() {
    delete[] data_;
    instances_--;
}
char *const SimpleString::c_str() const {
        data_[size_]='\0';
        if(size_==0){
            //return NULL;
        }
        return data_;
}

size_t SimpleString::size() const {
    return size_;
}
size_t SimpleString::capacity() const {
    return capacity_;
}
char* SimpleString::data() const {
    return data_;
}
