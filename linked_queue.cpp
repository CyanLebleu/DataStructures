#ifndef STRUCTURES_LINKED_QUEUE_IPP
#define STRUCTURES_LINKED_QUEUE_IPP

#include "linked_queue.hpp"

using namespace dataStructures;

template<typename T>
LinkedQueue<T>::LinkedQueue()
{
    tail = nullptr;
}

template<typename T>
LinkedQueue<T>::~LinkedQueue()
{
    LinkedList<T>::clear();
}

template<typename T>
void LinkedQueue<T>::enqueue(const T& data)
{
    LinkedList<T>::push_back(data);
}

template<typename T>
T LinkedQueue<T>::dequeue()
{
    return LinkedList<T>::pop_front();
}

template<typename T>
T& LinkedQueue<T>::front()
{
    return LinkedList<T>::at(0);
}

template<typename T>
T& LinkedQueue<T>::back()
{
    return LinkedList<T>::at(LinkedList<T>::size()-1);
}

#endif
