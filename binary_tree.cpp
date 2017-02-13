#ifndef BINARY_TREE_CPP
#define BINARY_TREE_CPP

#include "binary_tree.hpp"

using namespace dataStructures;

template<typename T>
BinaryTree<T>::~BinaryTree()
{
    delete _root;
    _size = 0;
}

template<typename T>
void BinaryTree<T>::insert(const T& data)
{
    if(empty())
    {
        _root = new TreeNode<T>(data);
        _size++;
    }
    else
        if(_root->insertNode(data))
            _size++;
        else
            std::cout << "Duplicates aren't allowed\n";
}

template<typename T>
void BinaryTree<T>::remove(const T& data)
{
    if (!empty())
    {
        if (_root->deleteNode(data, nullptr))
        {
            _size--;
        }
        else
            std::cout << "Can't remove: no such data.\n";
    }
}

template<typename T>
bool BinaryTree<T>::contains(const T& data) const
{
    return _root->searchData(data);
}

template<typename T>
bool BinaryTree<T>::empty() const
{
    return _size == 0;
}

template<typename T>
std::size_t BinaryTree<T>::size() const
{
    return _size;
}

template<typename T>
ArrayList<T> BinaryTree<T>::pre_order() const
{
    ArrayList<T> contents {_size};
    if (!empty())
        _root->pre_order(contents);
    return contents;
}

template<typename T>
ArrayList<T> BinaryTree<T>::in_order() const
{
     ArrayList<T> contents {_size};
    if (!empty())
        _root->in_order(contents);
    return contents;
}

template<typename T>
ArrayList<T> BinaryTree<T>::post_order() const
{
     ArrayList<T> contents {_size};
    if (!empty())
        _root->post_order(contents);
    return contents;
}

#endif // BINARY_TREE_CPP
