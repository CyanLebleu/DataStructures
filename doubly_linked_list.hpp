/* Copyright 2016 <Cyan Lebleu>
 * doubly_linked_list.hpp
 */

#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <cstdint>  //! std::size_t included
#include <stdexcept>  //! C++ exceptions included
#include "double_node.hpp"

namespace dataStructures
{

template<typename T>
/*!
 * Doubly Linked List
 *
 * Represents a list, a structure in which elements may be added at the beginning, top or middle
 * of the structure. Elements are linked to both previous and next elements, thus, doubly linked list.
 *
 */
class DoublyLinkedList
{
public:
    /*!
     * Constructs an empty list.
     */
    DoublyLinkedList();

    /*!
     * Destroys an empty list.
     */
    virtual ~DoublyLinkedList();

    /*!
     * Clears the list.
     */
    void clear();

    /*!
     * Inserts an element at the front of the list.
     */
    virtual void push_front(const T& data);

    /*!
     * Inserts an element at the back of the list.
     */
    virtual void push_back(const T& data);

    /*!
     * Inserts an element at the given index.
     */
    void insert(const T& data, std::size_t index);

    /*!
     * Inserts an element, sorting it into ascending order.
     */
    void insert_sorted(const T& data);

    /*!
     * Removes an element at the given index.
     */
    T pop(std::size_t index);

    /*!
     * Removes the element at the front of the list.
     */
    virtual T pop_front();

    /*!
     * Removes the element at the top of the list.
     */
    virtual T pop_back();

    /*!
     * Removes a given element.
     */
    void remove(const T& data);

    /*!
     * Returns whether the list is empty or not.
     */
    bool empty() const;

    /*!
     * Returns whether the list contains an element or not.
     */
    bool contains(const T& data) const;

    /*!
     * Returns the element at a given index.
     */
    T& at(std::size_t index);

    /*!
     * Returns the constant element at a given index.
     */
    const T& at(std::size_t index) const;

    /*!
     * Returns the position of a given element.
     */
    std::size_t find(const T& data) const;

    /*!
     * Returns the size of the list.
     */
    std::size_t size() const;

protected:
    /*!
     * The head of the list, also first element.
     */
    DoubleNode<T>* _head{nullptr};

    /*!
     * The tail of the list, also last element.
     */
     DoubleNode<T>* _tail{nullptr};
    /*!
     * The size of the list, or how many items are stored in the list.
     */
    std::size_t _size{0u};

    /*!
     * Verifies whether an index is fit to be used for insertion. Throws an exception if negative.
     */
    void checkIfEmpty()
    {
        if (this->empty())
            throw std::out_of_range("The list is empty.");
    }

    /*!
     * Verifies whether an index is fit to be used for retrieving an element. Throws an exception if negative.
     */
    void checkRetrieval(std::size_t index)
    {
        if (index < 0 || index >= this->_size)
            throw std::out_of_range("Invalid retrieval position.");
    }

    /*!
    * Verifies whether an index is fit to be used for insertion. Throws an exception if negative.
    */
    void checkInsertion(std::size_t index)
    {
        if (index < 0 || index > this->_size)
            throw std::out_of_range("Invalid insertion position.");
    }
};

}  // namespace dataStructures

#include "doubly_linked_list.cpp"
#endif // DOUBLY_LINKED_LIST.HPP

