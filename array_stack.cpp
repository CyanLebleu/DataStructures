#ifndef ARRAY_STACK_CPP
#define ARRAY_STACK_CPP

#include "array_stack.hpp"

    using namespace dataStructures;

    template<typename T>
    ArrayStack<T>::ArrayStack() {
        stack_ = new T[DEFAULT_SIZE];
        top_ = 0u;
        max_size_ = DEFAULT_SIZE;
    }

    template<typename T>
    ArrayStack<T>::ArrayStack(std::size_t max) : max_size_{max} {
        stack_ = new T[max];
        top_ = 0;
    }

    template<typename T>
    ArrayStack<T>::~ArrayStack() {
        top_ = 0;
        delete[] stack_;
    }

    template<typename T>
    void ArrayStack<T>::push(const T& data) {
        if (!(full())) {
            stack_[top_] = data;
            top_++;
        } else throw std::out_of_range("Can't push: stack is full.");
    }

    template<typename T>
    T ArrayStack<T>::pop() {
        T value;
        if (!(empty())) {
            value = stack_[top_-1];
            top_--;
        } else throw std::out_of_range("Can't pop: stack is empty.");
        return value;
    }

    template<typename T>
    T& ArrayStack<T>::top() {
        if (!(empty())) {
            return stack_[top_-1];
        } else throw std::out_of_range("There's no top.");
    }

    template<typename T>
    void ArrayStack<T>::clear() {
        top_ = 0;
    }

    template<typename T>
    std::size_t ArrayStack<T>::size() {
        return top_;
    }

    template<typename T>
    std::size_t ArrayStack<T>::max_size() {
        return max_size_;
    }

    template<typename T>
    bool ArrayStack<T>::empty() {
        return top_ == 0;
    }

    template<typename T>
    bool ArrayStack<T>::full() {
        return top_ == max_size_;
    }

#endif //ARRAY_STACK_CPP
