/* Copyright 2016 <Cyan Lebleu>
 * linked_queue.hpp
 */

#ifndef LINKED_QUEUE_HPP
#define LINKED_QUEUE_HPP

#include "linked_list.hpp"  //! list where the linked queue inherits from //! a container to store the data

namespace dataStructures
{
    template<typename T>
    /*!
     * Linked Queue
     *
     * Represents a queue, a structure in which every element may only be added at the end
     * and removed from the beginning.
     *
     */
    class LinkedQueue : public LinkedList<T>
    {
     public:
        /*!
        * Builds an empty queue.
        */
        LinkedQueue();

        /*!
        * Destroys the queue.
        */
        ~LinkedQueue();

        /*!
        * Clears the queue.
        */

        void enqueue(const T& data);

        /*!
        * Removes the element at the beginning of the queue.
        */
        T dequeue();

        /*!
        * Returns the element at the beginning of the queue.
        */
        T& front();

        /*!
        * Returns the element at the end of the queue.
        */
        T& back();


     private:
        Node<T>* tail;  //! The node at the end of the queue.
    };  // namespace structures

}

#include "linked_queue.cpp"

#endif // LINKED_QUEUE_HPP
