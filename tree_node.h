/* Copyright 2017 <Cyan Lebleu>
 * tree_node.h
 */

 #ifndef TREE_NODE_H
 #define TREE_NODE_H

namespace dataStructures
{
template<typename T>
/*! Tree Node
 * Represents a Tree node, a container for a data structure
 * that is a data structure itself. I has two pointers, for it's
 * child nodes.
 */
class TreeNode
{
 public:
     /*!
      * Creates an empty node
      */
     TreeNode();

     /*!
      * Creates a node with the given data
      */
     explicit TreeNode(const T& data):
         _data{data}
         {}
      /*!
       * Destroys a node
       */
     ~TreeNode()
     {
         delete _left;
         delete _right;
     }

     /*!
      * Changes the node data to the next given data.
      */
     void data(const T& data)
     {
         _data = data;
     }

     /*!
      * Changes the left node to the given node.
      */
     void left(TreeNode* node)
     {
         _left = node;
     }

     /*!
      * Changes the right node to the given node
      */
     void right(TreeNode* node)
     {
         _right = node;
     }

     /*!
      * Returns the data stored on the node
      */
     T& data()
     {
         return _data;
     }

     /*!
      * Returns the left child of the node
      */
     TreeNode* left()
     {
         return _left;
     }

     /*!
      * Returns the right child of the node
      */
     TreeNode* right()
     {
         return _right;
     }

     /*!
      * Returns the data stored on the node
      * in a constant.
      */
     const T& data() const
     {
         return _data;
     }

     /*!
      * Returns the left child of the node
      * in a constant.
      */
     const TreeNode* left() const
     {
         return _left;
     }

     /*!
      * Returns the right child of the node
      * in a constant.
      */
     const TreeNode* right() const
     {
         return _right;
     }

     /*!
      * Returns the in-order successor or predecessor
      * of the node, to replace the node in deletion
      * operations
      */
     T& getSub(TreeNode* node)
     {

         while(node->left() != nullptr)
         {
             node = node->left();
         }
         return node->data();
     }

     bool insertNode(const T& data)
     {
        if (data < _data)
        {
            if (_left == nullptr)
            {
                _left = new TreeNode<T>(data);
                return true;
            }
            else
                _left->insertNode(data);
        } else if (data > _data)
        {
                if (_right == nullptr)
                {
                    _right = new TreeNode<T>(data);
                    return true;
                }
                else
                    _right->insertNode(data);
        }
        else
            return false;
     }

     bool deleteNode(const T& data, TreeNode parent)
     {
         if (data > _data)
            if (_right != nullptr)
                return _right->deleteNode(data, this);
            else
                std::cout << "Can't remove: No such data.\n";
        else if (data < _data)
                if (_left != nullptr)
                    return _left->deleteNode(data, this);
                else
                    std::cout << "Can't remove: No such data.\n";
        else
             {
                if (hasntChildren())
                {
                    delete this;
                    return true;
                }
                else if (parent->left() == this)
                    {
                        parent->left() = (_left != nullptr) ? _left : _right;
                        return true;
                    }
                else if ((parent->right() == this)
                    {
                        parent->right() = (_left != nullptr) ? _left : _right;
                        return true;
                    }
                else
                {
                    _data = getSub(_right);
                    return _right->deleteNode(_data, this);
                }
             }
             return false;
     }

     bool searchData(const T& data)
     {
         if (data > _data)
            {
                if (_right != nullptr)
                    _right->searchData(data);
                else return false;
            }
            else if (data < _data)
            {
                if (_left != nullptr)
                    _left->searchData(data);
                else return false;
            }
         else
            return true;
     }

    void pre_order(ArrayList<T>& contents) const {
        contents.push_back(_data);

        if (_left != nullptr)
            _left->pre_order(contents);

        if (_right != nullptr)
            _right->pre_order(contents);
    }

    void in_order(ArrayList<T>& contents) const {
        if (_left != nullptr)
            _left->in_order(contents);

        contents.push_back(_data);

        if (_right != nullptr)
            _right->in_order(contents);
    }

    void post_order(ArrayList<T>& contents) const {
        if (_left != nullptr)
            _left->post_order(contents);

        if (_right != nullptr)
            _right->post_order(contents);

        contents.push_back(_data);
    }



 private:
    T _data; //! The data to be stored
    TreeNode<T>* _left{nullptr}; //! The left child of the node
    TreeNode<T>* _right{nullptr}; //! The right child of the node

    bool hasntChildren()
    {
        return _left == nullptr && _right == nullptr;
    }

};
}
 #endif // TREE_NODE_H

