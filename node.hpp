/* Copytight 2016 <Cyan Lebleu>
 * node.hpp
 */

#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
/*! Node
 *
 * Represents a linked node a container for the data of each list element, with
 * a pointer (link) to the next element of the list.
 *
 */
class Node
{
  public:
    /*!
     * Constructs a new Node with given data.
     *
     */
    explicit Node(const T& data):
        data_{data}
    {}

    /*!
     * Constructs a new Node with given data and next element.
     *
     */
    Node(const T& data, Node* next):
        data_{data},
        next_{next}
    {}

    /*!
     * Changes the node's data to the new given data
     */
     void data(const T& data)
     {
         data_ = data;
     }

    /*!
     * Returns the element's data stored in the node.
     */
    T& data()
    {
        return data_;
    }

    /*!
     * Returns the constant element's data stored in the node.
     */
    const T& data() const
    {
        return data_;
    }

    /*!
     * Returns the next linked element.
     */
    Node* next()
    {
        return next_;
    }

    /*!
     * Returns the constant next linked element.
     */
    const Node* next() const
    {
        return next_;
    }

    /*!
     * Sets the next linked element.
     */
    void next(Node* node)
    {
        next_ = node;
    }

 private:
    T data_;  //! The element's data stored within the node
    Node* next_{nullptr};  //! The next linked element.
};

#endif  // NODE_HPP
