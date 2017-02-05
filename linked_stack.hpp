/* Copyright 2016 <Cyan Lebleu>
 *linked_stack.hpp
 */

 #ifndef LINKED_STACK_HPP
 #define LINKED_STACK_HPP


#include "linked_list.hpp"  //! List from where we inherit the methods of the stack

namespace dataStructures
{

template<typename T>
/*!
 * Array Stack
 *
 * Represents a stack, a structure in which every element may only be added on the top,
 * and only retrieved from the top.
 *
 */
class LinkedStack : public LinkedList<T>
{
 public:
    /*!
     * Builds an empty stack.
     */
    LinkedStack();

    /*!
    * Destroys the stack.
    */
    ~LinkedStack();

    /*!
    * Pushes (or adds) data to the top of the stack, if the stack is not full.
    *
    */
    void push(const T& data);

    /*!
    * Removes data from the top of the stack, if the stack is not empty.
    */
    T pop();

    /*!
    * Retrieves the data at the top of the list without removing it.
    */
    T& top();

 private:
    Node<T> *_stack;  //!the stack itself
};

}  // namespace structures

#include "linked_stack.cpp"

#endif // LINKED_STACK_HPP
