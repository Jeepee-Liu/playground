#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H 6262414230L

#ifndef _DEBUG
#define _DEBUG false
#endif // #ifndef _DEBUG


#include <iostream>
#include <initializer_list>

typedef int T;

// Def node
template<typename T>
class LinkedListNode {
public:
    T val = 0;
    LinkedListNode* next = nullptr;
    LinkedListNode(T v) : val(v), next(nullptr) {}
    LinkedListNode() = default;
};

template<typename T>
class LinkedList {
private:
    LinkedListNode<T>* head = nullptr;
    LinkedListNode<T>* ptrAt(int pos = -1);

public:
    LinkedList() = default;
    // Tested OK
    ~LinkedList();
    // Tested OK
    LinkedList(std::initializer_list<T> vals);
    // Tested OK
    void pushBack(T val = 0);
    // Tested OK
    void pushBack(std::initializer_list<T> vals);

    void pushFront(T val = 0);
    // Tested OK
    void print(std::ostream& os = std::cout);
};

template <typename T>
void LinkedList<T>::print(std::ostream& os) {
    auto cur = head;
    if(cur) os << cur->val;
    while( (cur = cur->next) != nullptr ) os << ' '  << cur->val;
    os << std::endl;
}

template <typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> vals) {
    head = nullptr;
    pushBack(vals);
}

template <typename T>
LinkedList<T>::~LinkedList() {
    // TODO
    auto l = head;
    auto r = l ? l->next : l;
    while(l) {
        #if _DEBUG
        std::cout << "Deleting node [" << l
        << "]: " << l->val << std::endl;
        #endif
        delete l;
        l = r;
        r = r ? r->next : nullptr;
    }
}


template <typename T>
LinkedListNode<T>* LinkedList<T>::ptrAt(int pos) {
    /* (pos = -1) -> last element */
    auto cur = head;
    for(int i = 0; i != pos; ++i) {
        if(!cur) return nullptr;
        if(!cur->next) return cur;
        cur = cur->next;
    }
    return cur;
}

template <typename T>
void LinkedList<T>::pushBack(T val) {
    LinkedListNode<T>* node = new LinkedListNode<T>(val);
    auto tail = ptrAt(-1);
    if(tail) {
        tail->next = node;
    } else {
        head = node;
    }
}

template <typename T>
void LinkedList<T>::pushBack(std::initializer_list<T> vals) {
    LinkedListNode<T> first;
    auto cur = &first;
    for(auto& v: vals) {
        LinkedListNode<T>* node = new LinkedListNode<T>(v);
        cur->next = node;
        cur = node;
    }
    auto tail = ptrAt(-1);
    if(tail) {
        tail->next = first.next;
    } else {
        head = first.next;
    }
}

template <typename T>
void LinkedList<T>::pushFront(T val) {
    LinkedListNode<T>* node = new LinkedListNode<T>(val);
    node->next = head;
    head = node;
}

#endif // #ifndef _LINKED_LIST_H
