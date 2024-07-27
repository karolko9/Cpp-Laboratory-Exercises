#include <stdexcept> // std::out_of_range
#include <utility>   // std::exchange
#include <array>
#include <limits>
#include <algorithm>
#include <string>
#include "SortedUniqueVectoredList.h"
using namespace std;


/** class SortedUniqueVectoredList::Bucket
 * @param size ilosc elementow w kubelku, tworzac pusty ma byc 0
 * @param values elementy kubelka, jako tablica statyczna
 * @param BUCKET_SIZE ilosc elementow w statycznej tablicy
 * @param bucketCount_ ilosc kubelkow
 * @param next wskaznik na nastepny @ref Bucket, a jesli takiego nie ma na nullptr
 * @param previous wskaznik na poprzedni @ref Bucket, a jesli takiego nie ma na nullptr
 * @note jest to klasa zrobiona przy pomocy [idiomu PIMPL](https://en.cppreference.com/w/cpp/language/pimpl),
 *       ktory polega na tym, ze w klasie zewnetrznej jest jedynie deklaracja klasy wewnetrznej, ktora jest zaimplementowana w pliku zrodlowym **/
struct SortedUniqueVectoredList::Bucket
{
    constexpr static size_t BUCKET_SIZE = 10;

    std::array<std::string, BUCKET_SIZE> values;
    size_t size{};

    Bucket* next = nullptr;
    Bucket* previous = nullptr;
    Bucket() : values(), size(0), next(nullptr), previous(nullptr) {}
};


SortedUniqueVectoredList::SortedUniqueVectoredList(const SortedUniqueVectoredList &source)
{
    copy(source);
}

SortedUniqueVectoredList::SortedUniqueVectoredList(SortedUniqueVectoredList &&another)
{
    this->move(std::move(another));
}

SortedUniqueVectoredList::~SortedUniqueVectoredList()
{
    free();
}

SortedUniqueVectoredList &SortedUniqueVectoredList::operator=(SortedUniqueVectoredList &&another)
{
    if (this != &another)
    {
        this->move(std::move(another));
    }
    return *this;
}

void SortedUniqueVectoredList::insert(const string &value)
{
    if(contains(value))
        return;
    if(tail == nullptr || tail->size == SortedUniqueVectoredList::Bucket::BUCKET_SIZE){
        allocate_new_bucket();
        bucketCount_++;
    }
    size_++;
    tail->size++;
    std::string tmp1 = value, tmp2;
    for(auto i = head; i != nullptr; i = i->next) {
        for(int j = 0; j < i->size; j++) {
            if(tmp1 < i->values[j]) {
                tmp2 = i->values[j];
                i->values[j] = tmp1;
                tmp1 = tmp2;
            }
        }
    }
    tail->values[tail->size-1] = tmp1;
}


SortedUniqueVectoredList::operator std::string() const
{
    std::string result;
    for (auto i = head; i != nullptr; i = i->next) {
        for (int j = 0; j < i->size; j++) {
            result += i->values[j];
        }
    }
    return result;
}


void SortedUniqueVectoredList::allocate_new_bucket()
{
    Bucket *temp = new Bucket();
    //bucketCount_++;
    capacity_ += Bucket::BUCKET_SIZE;

    if(bucketCount_>0){
        temp->previous = tail;
        tail->next = temp;
    }
    else if(bucketCount_==0){
        head = temp;
    }
    tail = temp;
}

void SortedUniqueVectoredList::free()
{
    Bucket* curr_ = head;
    while (curr_ != nullptr) {
        Bucket* nextBucket = curr_->next;
        delete curr_;
        curr_ = nextBucket;
    }
}

void SortedUniqueVectoredList::move(SortedUniqueVectoredList &&another)
{
    free();

    head = another.head;
    size_ = another.size_;
    capacity_ = another.capacity_;
    tail = another.tail;
    bucketCount_ = another.bucketCount_;

    another.head = nullptr;
    another.tail = nullptr;
    another.bucketCount_ = 0;
    another.size_ = 0;
    another.capacity_ = 0;
}

void SortedUniqueVectoredList::copy(const SortedUniqueVectoredList &other)
{
    for(auto i = 0; i<other.size_; i++){
        insert(other[i]);
    }
}
bool SortedUniqueVectoredList::contains(const string &value) const
{
    for(auto i = head; i != nullptr; i = i->next)
        for(auto j = 0; j < i->size; j++)
            if(i->values[j] == value) return true;
    return false;
}
SortedUniqueVectoredList SortedUniqueVectoredList::operator-(const SortedUniqueVectoredList &another) const
{
    SortedUniqueVectoredList ret;
    for (auto i = head; i != nullptr; i = i->next) {
        for (int j = 0; j < i->size; j++) {
            if (!another.contains(i->values[j])) {
                ret.insert(i->values[j]);
            }
        }
    }
    return ret;
}
SortedUniqueVectoredList &SortedUniqueVectoredList::operator*=(const size_t howManyTimesMultiply)
{
    for (auto i = head; i != nullptr; i = i->next) {
        for (int j = 0; j < i->size; j++) {
            std::string& value = i->values[j];
            std::string temp = value;
            value.clear();
            for (size_t m = 0; m < howManyTimesMultiply; m++) {
                value += temp;
            }
        }
    }
    return *this;
}
string &SortedUniqueVectoredList::operator[](size_t index)
{
    if (index >= size_) {
        throw std::out_of_range("");
    }
    Bucket* curr_ = head;
    for(int i=0; i<index/10; i++){
        curr_ = curr_->next;
    }
    size_t pom_idx = index%10;
    return curr_->values[pom_idx];
}
const string& SortedUniqueVectoredList::operator[](size_t index) const
{
    if (index >= size_) {
        throw std::out_of_range("");
    }
    const Bucket* curr_ = head;
    for (int i = 0; i < index / Bucket::BUCKET_SIZE; i++) {
        curr_ = curr_->next;
    }
    size_t pom_idx = index % Bucket::BUCKET_SIZE;
    return curr_->values[pom_idx];
}
SortedUniqueVectoredList &SortedUniqueVectoredList::operator=(const SortedUniqueVectoredList &another)
{
    if (this == &another) {
        return *this;
    }
    this->copy(another);
    return *this;
}
SortedUniqueVectoredList::SortedUniqueVectoredList() {
    head = nullptr;
    tail = nullptr;
    bucketCount_ = 0;
    size_ = 0;
    capacity_ = 0;
}
