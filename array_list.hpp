/* Copyright 2016 <Cyan Lebleu>]
 * array_list.hpp
 */

#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include <cstdint> //! needed for the std::size_t
#include <stdexcept> //! needed to treat exceptions

namespace dataStructures {

template<typename T>
 /*! Array List
  *
  * Represents a list,a data structure where elements can be added at the top,
  * end, or middle of the structure.
  * This list has a fixed size set by the user, as it is implemented using an array.
  *
  */
class ArrayList {
 public:
   /*!
    * Builds an empty list with its default maximum size.
    *
    * @see ArrayList::DEFAULT_MAX
    */
    ArrayList();

   /*!
    * Builds an empty list with given size.
    */
    ArrayList(std::size_t max_size);

   /*!
    * Destroys the list and ts elements.
    */
    ~ArrayList();

   /*!
    * Clears the list.
    */
    void clear();

   /*!
    * Inserts an element at the back of the list.
    */
    void push_back(T data);

   /*!
    * Inserts an element at the front of the list.
    */
    void push_front(T data);

   /*!
    * Inserts an element at a given index.
    */
    void insert(T data, std::size_t index);

   /*!
    * Inserts an element according to its sorting settings.
    */
    void insert_sorted(T data);

   /*!
    * Removes an element at the given index and return its value.
    */
    T pop(std::size_t index);

   /*!
    * Removes the element at the top of the list and return its value.
    */
    T pop_back();

   /*!
    * Removes the element at the front of the list and return its value.
    */
    T pop_front();

   /*!
    * Removes a given element.
    */
    void remove(T data);

   /*!
    * Returns whether the list is full or not.
    */
    bool full() const;

   /*!
    * Returns whether the list is empty or not.
    */
    bool empty() const;

   /*!
    * Returns whether the list contains an element or not.
    */
    bool contains(const T& data) const;

   /*!
    * Returns the position of a given element.
    */
    std::size_t find(const T& data) const;

   /*!
    * Returns the size of the list.
    */
    std::size_t size() const;

   /*!
    * Returns the maximum size of the list.
    */
    std::size_t max_size() const;

   /*!
    * Returns the element stored at the given index, verifying the index boundaries.
    */
    T& at(std::size_t index);

   /*!
    * Returns the constant element stored at the given index, verifying the index boundaries.
    */
    const T& at(std::size_t index) const;

 private:
    T* list_;  //!< The array containing the elements.
    std::size_t size_;  //!< The current size of the list.
    std::size_t max_size_;  //!< The maximum possible size of the list.

    static const auto DEFAULT_SIZE = 10u;  //!< The default maximum size.

  };
}

  #include "array_list.cpp"

  #endif // ARRAY_LIST_HPP
