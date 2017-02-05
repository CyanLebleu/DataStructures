#ifndef ARRAY_QUEUE_CPP
#define ARRAY_QUEUE_CPP

#include "array_queue.hpp"

    using namespace dataStructures;

    template<typename T>
    ArrayQueue<T>::ArrayQueue() {
        queue_ = new T[DEFAULT_SIZE];
        size_ = 0;
        max_size_ = DEFAULT_SIZE;
    }

    template<typename T>
    ArrayQueue<T>::ArrayQueue(std::size_t max) : max_size_{max} {
        queue_ = new T[max];
        size_ = 0;
        max_size_ = max;
    }

    template<typename T>
    ArrayQueue<T>::~ArrayQueue() {
        size_ = 0;
        delete[] queue_;
    }

    template<typename T>
    void ArrayQueue<T>::enqueue(const T& data) {
        if (!(full())) {
            queue_[size_] = data;
            size_++;
        } else {
                throw std::out_of_range("The queue is full. Can't enqueue.");
            }
    }

    template<typename T>
    T ArrayQueue<T>::dequeue() {
        T value;
        if (!(empty())) {
            value = queue_[0];
            for (unsigned int i = 0; i < (size_ -1 ); i++) {
                queue_[i] = queue_[i+1];
            }
             size_--;
            return value;
        } else {
            throw std::out_of_range("The queue is empty: can't dequeue.");
            }
    }

    template<typename T>
    T& ArrayQueue<T>::back() {
        if (!(empty())) {
            return queue_[size_ - 1];

        } else {
            throw std::out_of_range("The queue is empty. Can't return back value.");
            }
    }

    template<typename T>
    T& ArrayQueue<T>::front() {
        return queue_[0];
    }

    template<typename T>
    void ArrayQueue<T>::clear() {
        size_ = 0;
    }

    template<typename T>
    std::size_t ArrayQueue<T>::size() {
        return size_;
    }

    template<typename T>
    std::size_t ArrayQueue<T>::max_size() {
        return max_size_;
    }

    template<typename T>
    bool ArrayQueue<T>::empty() {
        return size_ == 0;
    }

    template<typename T>
    bool ArrayQueue<T>::full() {
        return size_ == max_size_;
    }

#endif // ARRAY_QUEUE_CPP

