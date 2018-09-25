#include <iostream>

#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

// Each node:
template<typename T>
class BinaryNode<T> {

public:

    BinaryNode<T>() = default;
    BinaryNode<T> *lChild = nullptr;
    BinaryNode<T> *rChild = nullptr;
    T data = NULL;
};

// The binary tree
template<typename T>
class BinaryTree<T> {

public:

    BinaryTree<T>() {
        root = new BinaryNode<T>;
    }

    ~BinaryNode<T>() {

    }

protected:
    BinaryNode<T> *root;
};

#endif
