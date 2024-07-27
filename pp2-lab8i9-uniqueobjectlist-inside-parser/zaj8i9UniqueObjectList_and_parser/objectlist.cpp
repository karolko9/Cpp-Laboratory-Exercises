#include <memory>
#include <stdexcept>
#include <utility>  // std::exchange()
#include "objectlist.h"
#include "object.h"


struct ObjectList::Node
{
    Object* data;
    Node* next;
    Node(Object* newdata_): data(newdata_), next(nullptr) {}
};

ObjectList::ObjectList() : head(nullptr), count(0) {}
ObjectList::~ObjectList() = default;

size_t ObjectList::size() const {
    return count;
}


bool ObjectList::empty() const {
    return count==0;
}

//ObjectList::iterator ObjectList::begin() const {
//    return iterator (head);
//}
//
//ObjectList::iterator ObjectList::end() const {
//    return iterator (nullptr);
//}

void ObjectList::push_front(ObjectList::value_type *newObject) {
    bool jest = false;
    Node* n = head;
    for(size_t i=0; i<count; i++){
        if(*n->data==*newObject){
            jest = true;
        }
        n=n->next;
    }
    if(!jest){
        Node *temp = new Node(nullptr);
        //temp->data = new ObjectList::value_type;
        temp->data = newObject;
        temp->next = head;
        head = temp;
        count++;
    }
}

void ObjectList::pop_front() {
    Node* temp = head->next;
    delete head;
    head = temp;
    count--;
}

void ObjectList::erase_after(ObjectList::iterator position) {
    if(position.node->next != nullptr){
        count--;
        position.node->next=position.node->next->next;
    }
}

void ObjectList::erase(ObjectList::iterator position) {
    Node *temp=head;
    while(temp->next != nullptr){
        temp=temp->next;
    }
    temp->next=position.node->next;
    count--;
}

ObjectList::value_type &ObjectList::front() {
    return *head->data;
}

void ObjectList::clear() {
    while(count != 0){
        ObjectList::pop_front();
    }
}

void ObjectList::reverse() noexcept {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

ObjectList &ObjectList::operator=(const ObjectList &other) {
    clear();
    if(other.empty()) return  *this;
    head = new Node(other.head->data->clone());
    Node* curr = head;
    Node* curr_other = other.head->next;
    count = other.count;
    while (curr_other != nullptr){
        curr->next = new Node(curr_other->data->clone());
        curr = curr->next;
        curr_other = curr_other->next;
    }
    return *this;
}

ObjectList &ObjectList::operator=(ObjectList &&other) noexcept {
    if (this == &other) return *this;
    clear();
    count = other.count;
    other.count = 0;
    head = other.head;
    other.head = nullptr;
    return *this;
}

ObjectList::iterator ObjectList::iterator::operator++() {
    return {
        //node->next
        iterator(node->next)
    };
}

ObjectList::value_type &ObjectList::iterator::operator*() const {
    return {
        *node->data
    };
}

bool ObjectList::iterator::operator==(const ObjectList::iterator &other) const {
    return node==other.node;
}

ObjectList::iterator::operator bool() const {
    return node;
}
