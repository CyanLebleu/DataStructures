#ifndef CIRCULAR_LIST_CPP
#define CIRCULAR_LIST_CPP

#include "circular_list.hpp"

using namespace dataStructures;

template<typename T>
CircularList<T>::CircularList() {
    this->_head = new Node<T>(0, nullptr);
    this->_head->next(this->_head);
    this->_size = 0;
    _tail = this->_head;
}

template<typename T>
CircularList<T>::~CircularList() {
    this->clear();
}

template<typename T>
void CircularList<T>::push_front(const T& data) {
    Node<T>* newNode(new Node<T>(data, this->_head));
    this->_head = newNode;
    this->_size++;
    if (this->_size == 0)
        _tail = this->_head;
    else
        _tail->next(this->_head);
}

template<typename T>
T CircularList<T>::pop_front() {
    T data = LinkedList<T>::pop_front();
    _tail->next(this->_head);
    return data;
}

template<typename T>
T CircularList<T>::pop_back() {
    T data = LinkedList<T>::pop_back();
    _tail->next(this->_head);
    return data;
}


#endif // CIRCULAR_LIST_CPP
