#ifndef TREEMULTIMAP_INCLUDED
#define TREEMULTIMAP_INCLUDED

#include <vector>
#include <list>
#include <iostream>
#include <string>

template <typename KeyType, typename ValueType>
class TreeMultimap
{
private:
    struct BSTNode //BST Node
    {
        //public:
            //each node contains a key, vector values associated with the key, and a vector of pointers
            //to its left and right child nodes, and its parent node 
            //binary tree: every node has left and right children node
            //KeyType key;
            //std::vector<ValueType> value;
            //std::vector<std::unique_ptr<BSTNode>> left;
            //std::vector<std::unique_ptr<BSTNode>> right;
            ////unique_ptr autoamically deltes nodes when node is no longer needed, and prevents ownership problems
            //std::vector<BSTNode*> parent;
            //BSTNode(const KeyType& k, const ValueType& v, BSTNode* parent = nullptr)
            //    :key(k), value(v), left(nullptr), right(nullptr), parent(parent)
            //{

            //}

        KeyType key;
        std::vector<ValueType> value;
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
public:
    class Iterator
    {
    private:
        std::list<BSTNode*> duplicates;
        typename std::list<BSTNode*>::const_iterator list_it;
        //BSTNode* current;
    public:
        Iterator()
            :duplicates(), list_it(duplicates.end())
            //curr_node(nullptr)
            //this creates invalid iterator
        {
            // Replace this line with correct code.
        }

        Iterator(BSTNode* node)
            /*:curr_node(node)*/
        {
            duplicates = node->duplicates;
            list_it = duplicates.begin();
        }

        ValueType& get_value() const
        {
            //returns a reference to current value reffered to by iterator.
            //return m_node->value.back();
            //return curr_node->value;
            return (*list_it)->value;
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
            return list_it != duplicates.end();
        }

        void advance()
        {
            ++list_it;
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
    //private:
    //    //BSTNode* m_node;
    //    BSTNode* curr_node;
    };

    //Tree Class beigns here:
    TreeMultimap()
        :root(nullptr)
    {
        // Replace this line with correct code.
    }

    ~TreeMultimap()
    {
     //   delete root;
        //root.reset();
        // Replace this line with correct code.
    }

    void insert(const KeyType& key, const ValueType& value)
    {
        // Replace this line with correct code.

        
        //insert searches the BST to find the node for the given key
        //then, it either adds a new value to the node's vector
        //or, it creates a new child node with the given key, if mapping mapping key to multiple values
        
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

        //}

        //create a new node with key, value
        if (root == nullptr)
        {
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
    }

    Iterator find(const KeyType& key) const
    {
        //find() allows you to serach multimap for specified key
        
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
        BSTNode* curr = root;
        while (curr != nullptr)
        {
            if (key == curr->key)
            {
                return curr;
            }
            else if (key < curr->key)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        if (curr == nullptr)
        {
            return Iterator();
        }
        return Iterator(curr);
    }

};

#endif // TREEMULTIMAP_INCLUDED
