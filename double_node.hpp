/* Copytight 2016 <Cyan Lebleu>
 * double_node.hpp
 */

#ifndef DOUBLE_NODE_HPP
#define DOUBLE_NODE_HPP

template <typename T>
/*! Double Node
 *
 * Represents a linked node, a container for the data in each list element, with
 * a pointer (link) to the next element of the list and another to the previous
 * node of the list
 *
 */
class DoubleNode
{
  public:
    /*!
     * Constructs a new double node with given data.
     *
     */
    explicit DoubleNode(const T& data):
        _data{data}
    {}

    /*!
     * Constructs a new double node with the given data and the previous and next elements.
     *
     */
    explicit DoubleNode(const T& data, DoubleNode* prev, DoubleNode* next):
        _data{data},
        _prev{prev},
        _next{next}
    {}

    /*!
     * Returns the previous linked element.
     */
    DoubleNode* prev() {
        return _prev;
    }

    /*!
     * Returns the constant previous linked element.
     */
    const DoubleNode* prev() const {
        return _prev;
    }

    /*!
     * Sets the previous linked element.
     */
    void prev(DoubleNode* node) {
        _prev = node;
    }

    /*!
     * Returns the next linked element.
     */
    DoubleNode* next() {
        return _next;
    }

    /*!
     * Returns the constant next linked element.
     */
    const DoubleNode* next() const {
        return _next;
    }

    /*!
     * Sets the next linked element.
     */
    void next(DoubleNode* node) {
        _next = node;
    }

    /*!
     * Returns the constant element's data stored in the node.
     */
    const T& data() const {
        return _data;
    }

    /*!
     * Returns the element's data stored in the node.
     */
    T& data() {
        return _data;
    }

 private:
    T _data;  //! The element's data stored within the node
    DoubleNode* _prev{nullptr};  //! The previous linked element.
    DoubleNode* _next{nullptr};  //! The next linked element.
};

#endif  // DOUBLE_NODE_HPP

