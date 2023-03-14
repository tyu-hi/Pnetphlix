#ifndef TREEMULTIMAP_INCLUDED
#define TREEMULTIMAP_INCLUDED

#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

template <typename KeyType, typename ValueType>
class TreeMultimap
{
private:
    struct BSTNode //BST Node
    {
        KeyType key;
        std::vector<ValueType> value;   //since eacy key can have mutliple values
        BSTNode* left;
        BSTNode* right;
        BSTNode(const KeyType& k, const ValueType& v)
            :key(k), left(nullptr), right(nullptr)
        {
            value.push_back(v);
        }
      /*  BSTNode& operator=(const std::vector<ValueType>& rhs)
        {
            this->value = rhs;
            return *this;
        }*/
    };

    BSTNode* root;

    void deleteNode(BSTNode* curr)
    {
        if (curr == nullptr)
        {
            return;
        }
        deleteNode(curr->left); //delete nodes in left sub-tree
        deleteNode(curr->right);    //delete nodes in right sub-tree
        delete curr;    //free current node
    }

public:
    class Iterator
    {
    private:
        std::vector<ValueType>* vectorValues; //this is the values in the vector, which is a pointer to our node vector
        //a pointer to a vector of values of type ValueType
        typename std::vector<ValueType>::iterator vector_iterator;   //this is our iterator
    public:
        Iterator()
            :vector_iterator(vectorValues->end())
            //this creates invalid iterator
        {
            cerr << "balls" << endl;
            // Replace this line with correct code.
        }

        Iterator(std::vector<ValueType>* valuePtr)
        {
            vectorValues = valuePtr;
            vector_iterator = valuePtr->begin();
        }

        ValueType& get_value() const
        {
            //returns a reference to current value reffered to by iterator.
            //return m_node->value.back();
            //return curr_node->value;
            return (*vector_iterator);
            //.back() returns a referrence to the last element of vector
            //throw 1;  // Replace this line with correct code.
        }

        bool is_valid() const
        {
            ////return ture if iterator is valid
           /* if (curr_node != nullptr)
            {
                return true;
            }
            else
            {
                return false;
            }*/
            //return false;   // Replace this line with correct code.
            return (vector_iterator != vectorValues->end() && vector_iterator >= vectorValues->begin());
        }

        void advance()
        {
            if (is_valid())
            {
                vector_iterator++;
            }
            return;
            //increment iterator

          /*  if (curr_node != nullptr)
            {
                if (curr_node->right != nullptr)
                {
                    curr_node = curr_node->right;
                    while (curr_node->left != nullptr)
                    {
                        curr_node = curr_node->left;
                    }
                }
                else
                {
                    while (curr_node->right == nullptr)
                    {
                        curr_node = curr_node->parent;
                        if (curr_node == nullptr)
                        {
                            break;
                        }
                    }
                    if (curr_node != nullptr)
                    {
                        curr_node = curr_node->right;
                        while (curr_node->left != nullptr)
                        {
                            curr_node = curr_node->left;
                        }
                    }
                }
            }*/
            ////advances iterator to next value associated with the searched-for key
            //if (m_node != nullptr)  //if nullptr, iterator is invalid
            //{
            //    //if right vector is not empty
            //    if (m_node->right.empty() == false)
            //    {
            //        //set node pointer to front node of this vector
            //        //this is because on the right, every node has keys greater than the current node's key
            //        //we want to move to the next smallest key on the right
            //        m_node = m_node->right.front();
            //        while (m_node->left.empty() == false)
            //        {
            //            //this loop moves node pointer to left-most node in subtree
            //            //the root is the new node pointer
            //            m_node = m_node->left.front();
            //        }
            //    }
            //    //if right is empty
            //    else
            //    {
            //        //find node that has not been visited
            //        //check if current node is the right child of its parent
            //        while (m_node->parent.empty() == false && m_node == m_node->parent.back()->right.front())
            //        {
            //            //if yes, move up the parent node
            //            //keep moving until we find node that is not the right child of parent, or we are at the roto
            //            m_node = m_node->parent.back();
            //        }
            //        if (m_node->parent.empty() == true)
            //        {
            //            //if node pointer is invalid, make it nullptr
            //            //we hvae iterated through all values associated with the key
            //            m_node = nullptr;
            //        }
            //        else
            //        {
            //            m_node = m_node->parent.back();
            //        }
            //    }
            //}
            // Replace this line with correct code.
        }
    };

    //TreeMultimap Class beigns here:
    TreeMultimap()
        :root(nullptr)
    {
        // Replace this line with correct code.
    }

    ~TreeMultimap()
    {
        deleteNode(root);
        //delete root;
        //root.reset();
        // Replace this line with correct code.

        ////using a stack to perform postorder traversal of tree for deleting
        //std::stack<BSTNode*> stack;
        //stack.push(root);

        //while (!stack.empty())
        //{
        //    BSTNode* node = stack.top();
        //    stack.pop();
        //    if (node)
        //    {
        //        //push left and right children to stack
        //        stack.push(node->left);
        //        stack.push(node > right);
        //        //delete the current node
        //        delete node;
        //    }
        //}
        //using stack to traverse inorder traversal
        
        //std::stack<BSTNode*> node;
        //BSTNode* curr = root;
        //while (curr != nullptr || !node.empty())
        //{
        //    while(curr->left != nullptr)
        //    {
        //        node.push(curr);
        //        curr = curr->left;
        //        curr = node.top();
        //        node.pop();

        //        //delete current node's value vector using built-in .clear()
        //        curr->value.clear();
        //        delete curr;
        //        curr = curr->left;
        //    }
        //    while (curr->right != nullptr)
        //    {
        //        node.push(curr);
        //        curr = curr->left;
        //        curr = node.top();
        //        node.pop();

        //        //delete current node's value vector using built-in .clear()
        //        curr->value.clear();
        //        delete curr;
        //        curr = curr->right;
        //    }
        //}
    }

    void insert(const KeyType& key, const ValueType& value)
    {
        // Replace this line with correct code.

        //insert searches the BST to find the node for the given key
        //then, it either adds a new value to the node's vector
        //or, it creates a new child node with the given key, if mapping mapping key to multiple values

        //create a new node with key, value
        if (root == nullptr)
        {
            BSTNode* newNode = new BSTNode(key, value);
            //if tree is empty, set new node as root
            root = newNode;
            return;
        }
        BSTNode* current = root;
        while (true)
        {
            if (key < current->key) //go left
            {
                if (current->left == nullptr)
                {
                    BSTNode* newNode = new BSTNode(key, value);
                    //if there is no left child, set new node as left child
                    current->left = newNode;
                    // newNode->parent = current;
                    break;
                }
                //else, continue serachig left
                current = current->left;
            }
            else if (key == current->key)
            {
                //check if value is in vector?
                current->value.push_back(value);
                break;
            }
            else  //go right
            {
                if (current->right == nullptr)
                {
                    BSTNode* newNode = new BSTNode(key, value);
                    current->right = newNode;
                    // newNode->parent = current;
                    break;
                }
                //continue searching right
                current = current->right;
            }
        }    
        //BSTNode* node = root.get();
        //.get() returns a raw pointer to the root node
        //BSTNode* parent = nullptr;
        //while (node != nullptr)
        //{
        //    parent = node;  //keeps track of parent node 
        //    if (key < node->key)    //if key being inserted is less than current node's key, move left
        //    {
        //        if (node->left.empty())
        //        {
        //            node = nullptr;
        //        }
        //        else
        //        {
        //            node = node->left.front();
        //        }
        //    }
        //    else //move right
        //    {
        //        if (node->right.empty())
        //        {
        //            node = nullptr;
        //        }
        //        else
        //        {
        //            node = node->right.front();
        //        }
        //    }
        //}
        //if (parent == nullptr)
        //{
        //    root.reset(new BSTNode(key, value, parent));
        //}
        //else if (key == parent->key)
        //{
        //    parent->value.push_back(value);
        //}
        //else if (key < parent->key)
        //{
        //    //adds a new pointer to a new BSTNode to end of vector with key, value, and parent.
        //    parent->left.emplace_back(new BSTNode(key, value, parent));
        //}
        //else
        //{
        //    parent->right.emplace_back(new BSTNode(key, value, parent));
        //}
        //BSTNode* newNode = new BSTNode(key, value);
        //if (root == nullptr)
        //{
        //    root = newNode;
        //}
        //else
        //{
        //    BSTNode* parent = root;
        //    BSTNode* current = root;
        //    while (current != nullptr)
        //    {
        //        /* parent = current;
        //         if (key < current->key)
        //         {
        //             current = current->left;
        //         }
        //         else
        //         {
        //             current = current->right;
        //         }
        //     }
        //     if (key < parent->key)
        //     {
        //         parent->left = newNode;
        //     }
        //     else
        //     {
        //         parent->right = newNode;
        //     }
        //     newNode->parent = parent;*/
        //        parent = current;
        //        if (key == current->key)
        //        {
        //            current->value.push_back(value);
        //            return;
        //        }
        //        else if (key < current->key)
        //        {
        //            current = current->left;
        //        }
        //        else
        //        {
        //            current = current->right;
        //        }
        //    }
        //    if (key < parent->key)
        //    {
        //        parent->left = newNode;
        //    }
        //    else
        //    {
        //        parent->right = newNode;
        //    }
        //    newNode->parent = parent;
    }

    Iterator find(const KeyType& key) const
    {
        //find() allows you to serach multimap for specified key
        BSTNode* curr = root;
        while (curr != nullptr)
        {
            if (key == curr->key)
            {
                return Iterator(&(curr->value));
            }
            else if (key < curr->key)
            {
                curr = curr->left;
                return Iterator(&(curr->value));
            }
            else
            {
                curr = curr->right;
                return Iterator(&(curr->value));
            }
        }

        if (curr == nullptr)
        {
            return Iterator(nullptr);
        }
        return Iterator(nullptr);

        //return Iterator(&(curr->value));
        //returns reference to the curr's node's vector of values
        //each node has a vector of values

        //BSTNode* node = root.get();
        //while (node != nullptr && key != node->key)
        //{
        //    if (key < node->key)
        //    {
        //        if (node->left.empty())
        //        {
        //            node = nullptr;
        //        }
        //        else
        //        {
        //            node = node->left.front();
        //            //.front() returns reference to first element of vector
        //        }
        //    }
        //    else
        //    {
        //        if (node->right.empty())
        //        {
        //            node = nullptr;
        //        }
        //        else
        //        {
        //            node = node->right.front();
        //        }
        //    }
        //}
        //if (node == nullptr)
        //{
        //    //if no matching node to the key is found, return invalid iterator
        //    return Iterator();
        //}
        //else
        //{
        //    //if found the matching node, return iterator to that node
        //    return Iterator(node);
        //}    
        //return Iterator();  // Replace this line with correct code.
        /*BSTNode* current = root;
        while (current != nullptr && current->key != key)
        {
            if (key < current->key)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return Iterator(current);*/
    }

};

#endif // TREEMULTIMAP_INCLUDED
