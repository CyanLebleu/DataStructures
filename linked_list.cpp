#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include "linked_list.hpp"
#include "node.hpp"

using namespace dataStructures;

template <typename T>
LinkedList<T>::LinkedList()
{
    _head = nullptr;
    _size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <typename T>
void LinkedList<T>::clear()
{
    while(!empty())
    {
        pop_front();
    }
}

template<typename T>
void LinkedList<T>::push_back(const T& data)
{
    insert(data, _size);
}

template<typename T>
void LinkedList<T>::push_front(const T& data)
{
    Node<T> *newNode = new Node<T>(data, _head);
    _head = newNode;
    _size++;
}

template<typename T>
void LinkedList<T>::insert(const T& data, std::size_t index)
{
    if (empty())
        return push_front(data);
    if (index == 0)
        return push_front(data);
    checkInsertionPosition(index);
    Node<T> *newNode, *previousNode;
    previousNode = _head;

    auto i = 0u;
    while (i < index-1)
    {
            previousNode = previousNode->next();
            i++;
    }

    newNode = new Node<T>(data, previousNode->next());
    previousNode->next(newNode);
    _size++;

}

template<typename T>
void LinkedList<T>::insert_sorted(const T& data)
{
    if (empty())
        push_front(data);
    else
    {
        Node<T> *previousNode = _head;
        auto i = 0u;
        while (i < size()-1 && data > previousNode->data())
        {
            previousNode = previousNode->next();
            i++;
        }
        (data > previousNode->data()) ? insert(data, i+1) : insert(data, i);
    }
}

template<typename T>
T& LinkedList<T>::at(std::size_t index)
{
    checkIfEmpty();
    checkRetrievalPosition(index);
    Node<T> *currentNode = _head;
    auto i = 0u;
    while (i < index)
    {
        currentNode = currentNode->next();
        i++;
    }

    return currentNode->data();
}

template<typename T>
T LinkedList<T>::pop(std::size_t index)
{
    checkIfEmpty();
    checkRetrievalPosition(index);
    if (index == 0)
        return pop_front();

    T data;
    Node<T> *currentNode = _head;
    Node<T> *popNode;
    auto i = 0u;
    while (i < index-1)
    {
        currentNode = currentNode->next();
        i++;
    }
    popNode = currentNode->next();
    currentNode->next(popNode->next());
    data = popNode->data();
    delete popNode;
    _size--;
    return data;
}

template<typename T>
T LinkedList<T>::pop_back()
{
    return pop(_size-1);
}

template<typename T>
T LinkedList<T>::pop_front()
{
    checkIfEmpty();
    T data = _head->data();
    _head = _head->next();
    _size--;
    return data;
}

template<typename T>
void LinkedList<T>::remove(const T& data)
{
    checkIfEmpty();

    auto i = 0u;
    auto dataPosition = find(data);
    if (dataPosition == _size)
        throw std::out_of_range("Can't remove: data doesn't exist.");

    Node<T> *currentNode = _head;
    Node<T> *nodeToRemove;
    while(i < dataPosition - 1)
    {
        currentNode = currentNode->next();
        i++;
    }
    nodeToRemove = currentNode->next();
    currentNode->next(nodeToRemove->next());
    delete nodeToRemove;
    _size--;
}

template<typename T>
bool LinkedList<T>::empty() const
{
    return _size == 0;
}

template<typename T>
bool LinkedList<T>::contains(const T& data) const
{
    return find(data) != _size;
}

template<typename T>
std::size_t LinkedList<T>::find(const T& data) const
{
    checkIfEmpty();

    Node<T> *currentNode = _head;
    for(auto i = 0u; i < _size; i++)
    {
        if (currentNode->data() == data)
        {
            return i;
        } else currentNode = currentNode->next();
    }
    return _size;
}

template<typename T>
std::size_t LinkedList<T>::size() const
{
    return _size;
}

#endif // LINKED_LIST_CPP
