#ifndef DOUBLY_CIRCULAR_LIST_CPP
#define DOUBLY_CIRCULAR_LIST_CPP

#include "doubly_circular_list.hpp"

using namespace dataStructures;

template<typename T>
DoublyCircularList<T>::DoublyCircularList() {
	this->_head = nullptr;
	this->_tail = nullptr;
	this->_size = 0u;
}

template<typename T>
DoublyCircularList<T>::~DoublyCircularList() {
	this->clear();
}

template<typename T>
void DoublyCircularList<T>::push_front(const T& data)
{
    DoubleNode<T> *newNode(new DoubleNode<T>(data));
    if (this->empty())
    {
        this->_head = newNode;
        this->_tail = this->_head;
        this->_head->next(this->_tail);
        this->_tail->prev(this->_head);

    } else
    {
        newNode->next(this->_head);
        this->_head->prev(newNode);
        this->_head = newNode;
        if (this->_size == 0)
            this->_tail = this->_head;
        else
            this->_tail->next(this->_head);
        this->_head->prev(this->_tail);
    }
    this->_size++;
}

template<typename T>
void DoublyCircularList<T>::push_back(const T& data)
{
    DoubleNode<T> *newNode(new DoubleNode<T>(data));
    if (this->empty())
    {
        this->_tail = newNode;
        this->_head = this->_tail;
        this->_tail->prev(this->_head);
        this->_head->next(this->_tail);
    } else
    {
        newNode->prev(this->_tail);
        this->_tail->next(newNode);
        this->_tail = newNode;
        if (this->_size == 0)
            this->_tail = this->_head;
        else
            this->_head->prev(this->_tail);
        this->_tail->next(this->_head);
    }
    this->_size++;
}

template<typename T>
T DoublyCircularList<T>::pop_front()
{
    T data = DoublyLinkedList<T>::pop_front();
    this->_tail->next(this->_head);
    this->_head->prev(this->_tail);
    return data;
}

template<typename T>
T DoublyCircularList<T>::pop_back()
{
    T data = DoublyLinkedList<T>::pop_back();
    this->_tail->next(this->_head);
    this->_head->prev(this->_tail);
    return data;
}

#endif // DOUBLY_CIRCULAR_LIST_CPP
