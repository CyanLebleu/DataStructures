/* Copyright 2016 <Cyan Lebleu>
 * array_stack.hpp
 */
#ifndef ARRAY_STACK_HPP
#define ARRAY_STACK_HPP

#include <stdexcept> //! needed to treat exceptions
#include <cstdint> //! needed for the std::size_t

namespace dataStructures {

template<typename T>

/*! Array Stack
 *
 * Represents a stack, a data structure where data is added at the top of the structure,
 * and also retrieved from the top, thus making it a LIFO structure.
 * This stack has a fixed size, set by the user, since it's implemented using an array.
 *
 */
class ArrayStack {
 public:
		/*!
	     * Builds an empty stack with its default size.
	     *
	     * @see ArrayStack::DEFAULT_SIZE
	     */
	    ArrayStack();

	    /*!
	     * Builds an empty stack of given maximum size.
	     *
	     * @param max The given maximum size for the stack.
	     */
	    ArrayStack(std::size_t max);

    	/*!
    	 * Destroys the stack.
    	 */
	    ~ArrayStack();

	    /*!
	     * Pushes (or adds) data to the top of the stack, if the stack is not full.
	     *
	     * @param data The data to be stacked.
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

		/*!
		 * Clears the stack.
		 */
	    void clear();

	    /*!
	     * Returns te number of elements currently stacked.
	     */
	    std::size_t size();

	    /*!
	     * Returns the stack's maximum possible size.
	     */
	    std::size_t max_size();

	    /*!
	     * Returns whether the stack is empty or not.
	     */
	    bool empty();

		/*!
	     * Returns whether the stack is full or not.
	     */
	    bool full();
 private:
	    T* stack_; //!< The stack in which the elements shall be kept.
	    unsigned int top_; //!< The current size of the stack, or how high is its top.
	    std::size_t max_size_; //!< The maximum size of the given stack.

	    const static auto DEFAULT_SIZE = 10u; //!< The default maximum size of the stack, in case a size is not given at its construction.
	};
  } // namespace dataStructures



#include "array_stack.cpp"
  #endif // ARRA_STACK_HPP
