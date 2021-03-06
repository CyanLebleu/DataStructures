/* Copyright 2016 <Cyan Lebleu>
 * linked_list.hpp
 */

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <cstdint>
#include <stdexcept>
#include "node.hpp"

namespace dataStructures
{

template <typename T>

/*! Linked List
 *
 * Represents a linked list, a data structure where elements can be added
 * retrieved or removed at any index,
 * and whose elements are linked between each other.
 *
 */
class LinkedList
{
 public:
    /*!
     * Constructs an empty list.
     */
    LinkedList();

    /*!
     * Destroys the list and ts elements.
     */
    virtual ~LinkedList();

    /*!
     * Clears the list.
     */
    virtual void clear();

    /*!
     * Inserts an element at the back of the list.
     */
    virtual void push_back(const T& data);

    /*!
     * Inserts an element at the front of the list.
     */
    virtual void push_front(const T& data);

    /*!
     * Inserts an element at the given index.
     */
    virtual void insert(const T& data, std::size_t index);

    /*!
     * Inserts an element according to its sorting settings.
     */
    virtual void insert_sorted(const T& data);

    /*!
     * Returns the element at a given index.
     */
    virtual T& at(std::size_t index);

    /*!
     * Removes an element at the given index.
     */
    virtual T pop(std::size_t index);

    /*!
     * Removes the element at the top of the list.
     */
    virtual T pop_back();

    /*!
     * Removes the element at the front of the list.
     */
    virtual T pop_front();

    /*!
     * Removes a given element.
     */
    virtual void remove(const T& data);

    /*!
     * Returns whether the list is full or not.
     */
    virtual bool empty() const;

    /*!
     * Returns whether the list contains an element or not.
     */
    virtual bool contains(const T& data) const;

    /*!
     * Returns the position of a given element.
     */
    virtual std::size_t find(const T& data) const;

    /*!
     * Returns the size of the list.
     */
    virtual std::size_t size() const;

 protected:
    /*!
     * Verifies whether the list is not empty. Throws an exception otherwise.
     */
    void checkIfEmpty() const {
        if (empty())
            throw std::out_of_range("The list is empty.");
    }

    /*!
     * Verifies whether an index is fit to be used for retrieving an element. Throws an exception if negative.
     */
    void checkRetrievalPosition(std::size_t index) {
        if (index < 0 || index >= _size)
            throw std::out_of_range("Invalid retrieval position.");
    }

    /*!
     * Verifies whether an index is fit to be used for insertion. Throws an exception if negative.
     */
    void checkInsertionPosition(std::size_t index) {
        if (index < 0 || index > _size)
            throw std::out_of_range("Invalid insertion position.");
    }

    /*!
    * Returns the last linked element.
    */
    Node<T>* end() {
        auto node = _head;
        for (auto i = 1u; i < size(); ++i) {
            node = node->next();
        }
        return node;
    }

    /*!
    * The head of the list, also first element.
    */
    Node<T>* _head{nullptr};

    /*!
    * The head of the list, also first element.
    */
    std::size_t _size{0u};
};
}  // namespace datastructures

#include "linked_list.cpp"
#endif // LINKED_LIST_HPP
