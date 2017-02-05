/* Copytight 2016 <Cyan Lebleu>
 * doubly_circular_list.hpp
 */

#ifndef DOUBLY_CIRCULAR_LIST_HPP
#define DOUBLY_CIRCULAR_LIST_HPP

#include "doubly_linked_list.hpp"

namespace dataStructures {

template<typename T>
/*!
 * Doubly Circular List
 *
 * Represents a doubly linked circular list, a structure that has no beginning nor end.
 * Elements may be stored and removed in and from anywhere.
 * Elements on the list are doubly linked between each other.
 *
 */
class DoublyCircularList: public DoublyLinkedList<T> {
 public:
    /*!
    * Constructs an empty list.
    */
	DoublyCircularList();

	/*!
    * Destroys the list.
    */
	~DoublyCircularList();

    /*!
    * Inserts an element at the end of the list.
    */
	void push_back(const T& data);

	/*!
    * Inserts an element at the front of the list.
    */
	void push_front(const T& data);

    /*!
    * Removes the element at the top of the list.
    */
	T pop_back();

	/*!
    * Removes the element at the front of the list.
    */
	T pop_front();
};
}  // namespace dataStructures

#include "doubly_circular_list.cpp"

#endif // DOUBLY_CIRCULAR_LIST_HPP
