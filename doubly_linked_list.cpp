#ifndef DOUBLY_LINKED_LIST_CPP
#define DOUBLY_LINKED_LIST_CPP

#include "double_node.hpp"
#include "doubly_linked_list.hpp"

using namespace dataStructures;

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
    delete _head;
}

template<typename T>
void DoublyLinkedList<T>::clear()
{
    while(!empty())
    {
        pop_front();
    }
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T& data)
{
    DoubleNode<T> *newNode(new DoubleNode<T>(data));
    newNode->next(_head);
    _head->prev(newNode);
    _head = newNode;
    if (_size == 0)
        _tail = _head;
    _size++;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& data)
{
    DoubleNode<T> *newNode(new DoubleNode<T>(data));
    if (_size == 0)
    {
        _tail = newNode;
        _head = _tail;
        _size++;
    } else
    {
        _tail->next(newNode);
        newNode->prev(_tail);
        _tail = newNode;
        _size++;
    }

}

template<typename T>
void DoublyLinkedList<T>::insert(const T& data, std::size_t index)
{
    checkInsertion(index);
    if (index == 0)
        push_front(data);
    else if (index == _size)
        push_back(data);
    else if (index < (_size/2))
    {
        DoubleNode<T> *newNode(new DoubleNode<T>(data));
        DoubleNode<T> *prevNode = _head;
        for (auto i = 0u; i < index -1; i++)
        {
            prevNode = prevNode->next();
        }

        prevNode->next()->prev(newNode);
        newNode->prev(prevNode);
        newNode->next(prevNode->next());
        prevNode->next(newNode);
        _size++;
    } else
    {
        DoubleNode<T> *newNode(new DoubleNode<T>(data));
        DoubleNode<T> *pastNode = _tail;
        for (auto i = _size; i > index+1; i--)
        {
            pastNode = pastNode->prev();
        }

        pastNode->prev()->next(newNode);
        newNode->prev(pastNode->prev());
        newNode->next(pastNode);
        pastNode->prev(newNode);
        _size++;
    }
}

template<typename T>
void DoublyLinkedList<T>::insert_sorted(const T& data)
{
    if (empty())
        push_front(data);
    else
    {
        DoubleNode<T> *previousNode = _head;
        auto i  = 0u;
        while (i < size() -1 && data > previousNode->data())
        {
            previousNode = previousNode->next();
            i++;
        }
        (data > previousNode->data()) ? insert(data, i+1) : insert(data, i);
    }
}

template<typename T>
T DoublyLinkedList<T>::pop(std::size_t index)
{
    T data;
    checkRetrieval(index);
    if (index == 1)
        pop_front();
    if (index == _size)
        pop_back();
    if (index < (_size/2))
    {
        DoubleNode<T> *previousNode = _head;
        DoubleNode<T> *popNode;
        auto i = 0u;
        while (i != index)
        {
            previousNode = previousNode->next();
            i++;
        }

        popNode = previousNode->next();
        data = popNode->data();
        previousNode->next(popNode->next());
        previousNode->next()->prev(previousNode);
    } else
    {
        DoubleNode<T> *pastNode = _tail;
        DoubleNode<T> *popNode;
        auto i = _size-1;
        while (i > index+1)
        {
            pastNode = pastNode->prev();
            i--;
        }

        popNode = pastNode->prev();
        data = popNode->data();
        delete popNode;
        pastNode->prev(popNode->prev());
        pastNode->prev()->next(pastNode);
    }
    _size--;
    return data;
}

template<typename T>
T DoublyLinkedList<T>::pop_front()
{
    checkIfEmpty();
    T data = _head->data();
    if (_head->next() == nullptr)
    {
        delete _head;
    } else
    {
        _head = _head->next();
        _head->prev(nullptr);
    }

    _size--;
    return data;
}

template<typename T>
T DoublyLinkedList<T>::pop_back()
{
    checkIfEmpty();
    T data = _tail->data();
    if (_tail->prev() == nullptr)
    {
        delete _tail;
    } else
    {
        _tail = _tail->prev();
        _tail->next(nullptr);
    }

    _size--;
    return data;
}

template<typename T>
void DoublyLinkedList<T>::remove(const T& data)
{
    DoubleNode<T> *removeNode = _head;
    DoubleNode<T> *handleNode;
    while (data != removeNode->data())
    {
        removeNode = removeNode->next();
    }

    if (removeNode->next() != nullptr)
        removeNode->prev()->next(removeNode->next());
    if (removeNode->prev() != nullptr)
        removeNode->next()->prev(removeNode->prev());
    delete removeNode;
    _size--;
}

template<typename T>
bool DoublyLinkedList<T>::empty() const
{
    return _size == 0;
}

template<typename T>
bool DoublyLinkedList<T>::contains(const T& data) const
{
    return find(data) != _size;
}

template<typename T>
T& DoublyLinkedList<T>::at(std::size_t index)
{
    checkRetrieval(index);
    DoubleNode<T> *currentNode = _head;
    for (auto i = 0u; i < index; i++)
    {
        currentNode = currentNode->next();
    }
    return currentNode->data();
}

template<typename T>
const T& DoublyLinkedList<T>::at(std::size_t index) const
{
    checkRetrieval(index);
    DoubleNode<T> *currentNode = _head;
    for (auto i = 0u; i < index; i++)
    {
        currentNode = currentNode->next();
    }
    return currentNode->data();
}

template<typename T>
std::size_t DoublyLinkedList<T>::find(const T& data) const
{
    DoubleNode<T> *currentNode = _head;
    auto i = 0u;
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
std::size_t DoublyLinkedList<T>::size() const
{
    return _size;
}

#endif // DOUBLY_LINKED_LIST_CPP
