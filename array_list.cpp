#ifndef ARRAY_LIST_CPP
#define ARRAY_LIST_CPP

#include <iostream>
#include "array_list.hpp"

    using namespace dataStructures;

    template<typename T>
    ArrayList<T>::ArrayList() {
        list_ = new T[DEFAULT_SIZE];
        size_ = 0;
        max_size_ = DEFAULT_SIZE;
    }

    template<typename T>
    ArrayList<T>::ArrayList(std::size_t max_size) : max_size_{max_size} {
        list_ = new T[max_size];
        size_ = 0;
    }

    template<typename T>
    ArrayList<T>::~ArrayList() {
        size_ = 0;
        delete[] list_;
    }

    template<typename T>
    void ArrayList<T>::clear() {
        size_ = 0;
    }

    template<typename T>
    void ArrayList<T>::push_back(T data) {
            insert(data, size_);
    }

    template<typename T>
    void ArrayList<T>::push_front(T data) {
        insert(data, 0);
    }

    template<typename T>
    void ArrayList<T>::insert(T data, std::size_t index) {
        if (!(full())) {
            for (auto i = size_; i > index; i--) {
                list_[i] = list_[i-1];
            }
            list_[index] = data;
            size_++;
        } else throw std::out_of_range("Can't insert: list is full.\n");
    }

    template<typename T>
    void ArrayList<T>::insert_sorted(T data) {
        auto i = 0u;
        while (i < size_ && data > list_[i]) {
            i++;
        }

        insert(data, i);
    }

    template<typename T>
    T ArrayList<T>::pop(std::size_t index) {
        T value;
        if (!(empty())) {
            value = list_[index];
            for (auto i = index; i < size_; i++) {
                list_[i] = list_[i+1];
            }
            size_--;
        }
        return value;
    }

    template<typename T>
    T ArrayList<T>::pop_back() {
        return pop(size_-1);
    }

    template<typename T>
    T ArrayList<T>::pop_front() {
        return pop(0);
    }

    template<typename T>
    void ArrayList<T>::remove(T data) {
        if(contains(data)) {
            auto index = find(data);
            for (auto i = index; i < size_; i++) {
                list_[i] = list_[i+1];
            }
            size_--;
        } else std::cout << "Can't remove: data not found.\n";
    }

    template<typename T>
    bool ArrayList<T>::full() const {
        return size_ == max_size_;
    }

    template<typename T>
    bool ArrayList<T>::empty() const {
        return size_ == 0;
    }

    template<typename T>
    bool ArrayList<T>::contains(const T& data) const {
        if (empty()) {
            return false;
        } else {
            for(auto i = 0u; i <= size_; i++) {
                if (list_[i] == data)
                    return true;
            }

            return false;
        }
    }

    template<typename T>
    std::size_t ArrayList<T>::find(const T& data) const {
        if (!(empty())) {
            for (auto i = 0u; i < size_; i++) {
                if (list_[i] == data)
                    return i;
            }
            std::cout << "No such value.";

        } else {
            std::cout << "Can't find: the list is empty.\n";
        }
    }

    template<typename T>
    std::size_t ArrayList<T>::size() const {
        return size_;
    }

    template<typename T>
    std::size_t ArrayList<T>::max_size() const {
        return max_size_;
    }

    template<typename T>
    T& ArrayList<T>::at(std::size_t index) {
        return list_[index];
    }

    template<typename T>
    const T& ArrayList<T>::at(std::size_t index) const {
        return list_[index];
    }


#endif //ARRAY_LIST_CPP
