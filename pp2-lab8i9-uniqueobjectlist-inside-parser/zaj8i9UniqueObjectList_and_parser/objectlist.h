#pragma once

#include <cinttypes>  // std::size_t
#include <memory>  // std::unique_ptr (dla chętnych)
#include <set>


//#define UNIMPLEMENTED_OBJECT_LIST_CONSTRUCTOR_SIZE_EMPTY_METHODS
//#define UNIMPLEMENTED_PUSH_FRONT
//#define UNIMPLEMENTED_POP_FRONT
//#define UNIMPLEMENTED_FRONT
//#define UNIMPLEMENTED_CLEAR
//#define UNIMPLEMENTED_REVERSE // rozmowa kwalifikacyjna
//#define UNIMPLEMENTED_ITERATOR_METHODS_AT_LEAST_EMPTY
//#define UNIMPLEMENTED_ITERATORS
//#define UNIMPLEMENTED_ERASE_AFTER
//#define UNIMPLEMENTED_ERASE


class Object;


class ObjectList
{
    struct Node;
    Node* head;
    size_t count;

public:
    using value_type = Object;
    ObjectList();
    ObjectList(ObjectList&& other): head(std::exchange(other.head, nullptr)), count(std::exchange(other.count, 0)) {}
    ObjectList(const ObjectList& other): ObjectList() {
        *this = other;
    }
    ~ObjectList();

    void clear();

    void reverse() noexcept;

    value_type& front();


    struct iterator
    {
        // TODO:
        Node *node;
        explicit iterator(Node *node1) : node(node1){};
        iterator operator++();
        value_type& operator*() const;
        bool operator==(const iterator& other) const;
        operator bool() const;
    };
    size_t size() const;
    bool empty() const;
    iterator begin() const{
        return iterator (head);
    }
    iterator end() const{
        return iterator (head);
    }

    /**
     * @brief push_front
     * @param newObject
     * Wpierw sprawdzamy czy obiekt już jest w liście
     */
    void push_front(value_type* newObject);

    void pop_front();

    void erase_after(iterator position);

    /// tego std::forward_list nie ma
    void erase(iterator position);




//
//    Zaimplementuj konstruktor kopiujący "głęboko"
//    Zaimplementuj konstruktor przenoszący
//            Zaimplementuj kopiujący operator przypisania
//    Zaimplementuj przenoszący operator przypisania
//    ObjectList(ObjectList &list);
//
    ObjectList& operator=(const ObjectList& other);
    ObjectList& operator=(ObjectList&& other) noexcept;







protected:
    // TODO:
};
