/* Copyright 2016 <Cyan Lebleu>
 * circular_list.hpp
 */

 #ifndef CIRCULAR_LIST_HPP
 #define CIRCULAR_LIST_HPP

 #include "linked_list.hpp"

namespace dataStructures
{
template<typename T>
/*!
 * Circular List
 *
 * Represents a circular list, a structure that has no beginning nor an end.
 * Elements may be stored and removed in and from anywhere.
 * Elements on the list are linked between each other.
 *
 */
class CircularList : public LinkedList<T> {
 public:
    /*!
     * Constructs an empty list.
     */
    CircularList();

    /*!
     * Destroys the list.
     */
    ~CircularList();

    /*!
     * Inserts an element at the front of the list.
     */
    void push_front(const T& data);


    /*!
     * Removes the element at the front of the list.
     */
    T pop_front();

    /*!
     * Removes the element at the back of the list.
     */
    T pop_back();

 private:
    Node<T> *_tail;
};

}   // namespace dataStructures

#include "circular_list.cpp"
#endif // CIRCULAR_LIST_HPP
