#include "linked_stack.hpp"

#ifndef STRUCTURES_LINKED_STACK_IPP
#define STRUCTURES_LINKED_STACK_IPP

    using namespace dataStructures;

    template<typename T>
    LinkedStack<T>::LinkedStack() {
        _stack = nullptr;
    }

    template<typename T>
    LinkedStack<T>::~LinkedStack() {
        LinkedList<T>::clear();
    }

    template<typename T>
    void LinkedStack<T>::push(const T& data) {
        LinkedList<T>::push_front(data);
    }

    template<typename T>
    T LinkedStack<T>::pop() {
        LinkedList<T>::pop_front();
    }

    template<typename T>
    T& LinkedStack<T>::top() {
       LinkedList<T>::at(0);
    }


#endif
