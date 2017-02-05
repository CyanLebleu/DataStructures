/*Copyright 2016 <CyanLebleu>
 *array_queue.hpp
 */

#ifndef ARRAY_QUEUE_HPP
#define ARRAY_QUEUE_HPP

#include <cstdint> //! needed for the std::size_t
#include <stdexcept> //! needed to treat exceptions
#include "linked_list.hpp"

namespace dataStructures
{

template <typename T>
/*! Array Queue
 *
 * Represents a queue, a data structure where every element is added at the end
 * and is taken out of the front, representing a FIFO structure.
 * This queue has a fixed size, set by the user, since it's implemented using an array.
 *
 */
class ArrayQueue : public LinkedList<T>
{
 public:

    /*!
     * Builds an empty queue with its default maximum size.
     *
     * @see ArrayQueue::DEFAULT_SIZE
     */
    ArrayQueue();

    /*!
     * Builds an empty queue with a given maximum size.
     *
     * @param max The given maximum size for the queue.
     */
    ArrayQueue(std::size_t max);

    /*!
     * Destroys the queue
     */
    ~ArrayQueue();

    /*!
     * Inserts data in the queue. Data can only be added at the end.
     *
     * @param data The given data to be inserted.
     */
    void enqueue(const T& data);

    /*!
     * Removes the first element of the queue, if the queue is not empty.
     */
    T dequeue();

    /*!
     * Returns the last element of the queue.
     */
    T& back();

    /*!
     * Returns the first element of the queue.
     */
    T& front();

    /*!
     * Clears the queue.
     */
    void clear();

    /*!
     * Returns how many elements are stored in the queue.
     */
    std::size_t size();

    /*!
     * Returns the maximum possible size of the queue.
     */
    std::size_t max_size();

    /*!
     * Returns whether the queue is empty or not.
     */
    bool empty();

    /*!
     * Returns whether the queue is full or not.
     */
    bool full();

 private:
    T* queue_; //!< The queue in which the elements shall be kept.
    std::size_t size_; //!< The current size of the stack, or how high is its top.
    std::size_t max_size_; //!< The maximum size of the given stack.

    const static auto DEFAULT_SIZE = 10u; //!< The default maximum size of the stack, in case a size is not given at its construction.

};
} // namespace dataStructures


#include "array_queue.cpp"
#endif // ARRAY_QUEUE_HPP
