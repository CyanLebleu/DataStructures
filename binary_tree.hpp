/* Copyright 2016 <Cyan Lebleu>
 * binary_tree.hpp
 */

 #ifndef BINARY_TREE_HPP
 #define BINARY_TREE_HPP

 #include "array_list.hpp"
 #include "tree_node.hpp"

namespace dataStructures
{
template<typename T>
/*!
 * Represents a binary tree, whose nodes may only have two children.
 */
class BinaryTree
{
 public:
    /*!
     * Creates an empty binary tree
     */
    BinaryTree():
        _root{nullptr},
        _size{0}
    {}

    /*!
     * Destroys the tree
     */
    ~BinaryTree();

    /*!
     * Creates a new node on the tree with the given data.
     */
    void insert(const T& data);

    /*!
     * Removes from the three the node which contains given data, if such node exists.
     */
    void remove(const T& data);

    /*!
     * Returns whether or not the tree contains a node with given data.
     */
    bool contains(const T& data) const;

    /*!
     * Returns whether or not the list is empty.
     */
    bool empty() const;

    /*!
     * Returns the size of the tree.
     */
    std::size_t size() const;


    /*!
     * Returns the values in the tree in "pre order":
     * Root first, then the leftmost descendant,
     * and then the rightmost descendant.
     */
    ArrayList<T> pre_order() const;

    /*!
     * Returns the values in the tree "in order":
     * The leftmost descendants first, then the root,
     * then the rightmost descendant
     */
    ArrayList<T> in_order() const;

    /*!
     * Returns the values in the tree in "post order":
     * First the leftmost descendant, then the rightmost
     * descendant, and then the root.
     */
    ArrayList<T> post_order() const;

 private:
    TreeNode<T>* _root;
    std::size_t _size;
};

}

#include "binary_tree.cpp"
 #endif // BINARY_TREE_HPP



