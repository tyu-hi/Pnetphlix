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
            :vectorValues(nullptr), vector_iterator()
            //this creates invalid iterator
        {
            //vector_iterator();  //calls default consturctor for vector iterator
            
            //cerr << "balls" << endl;
            // Replace this line with correct code.
        }

        Iterator(std::vector<ValueType>* valuePtr)
            //passes in address of the vector of values associaed with current node curr
        {
            vectorValues = valuePtr;
            vector_iterator = valuePtr->begin();
        }

        ValueType& get_value() const
        {
            return (*vector_iterator);
            //.back() returns a referrence to the last element of vector
            //throw 1;  // Replace this line with correct code.
        }

        bool is_valid() const
        {

            if (vectorValues == nullptr)
            {
                return false;
            }
            return (vector_iterator != vectorValues->end());
        }

        void advance()
        {
            if (is_valid())
            {
                vector_iterator++;
            }
            return;
            //increment iterator
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
        // Replace this line with correct code.
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

        BSTNode* parent = nullptr;
        BSTNode* current = root;

        while (true)
        {
            parent = current;
            if (key < current->key) //go left
            {
                if (current->left == nullptr)
                {
                    BSTNode* newNode = new BSTNode(key, value);
                    //if there is no left child, set new node as left child
                    current->left = newNode;
                    parent = current;
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
                    parent = current;
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
        BSTNode* curr = root;
        while (curr != nullptr)
        {
            //cerr << " i am in while loop " << endl;
            if (key == curr->key)
            {

                //cerr << " i am in while loop if " << endl;
                return Iterator(&(curr->value));
            }
            else if (key < curr->key && key != curr->key)
            {

                //cerr << " i am in while loop else if " << endl;
                curr = curr->left;
                //return Iterator(&(curr->value));
            }
            else if (key > curr->key && key != curr->key)
            {

                //cerr << " i am in while loop else " << endl;
                curr = curr->right;
                //return Iterator(&curr->value);
            }

            //cerr << " i am in while loop end " << endl;
        }

        if (curr == nullptr)
        {
            //cerr << "i am curr == nullptr" << endl;
            return Iterator();
        }
        return Iterator();

        //return Iterator(&(curr->value));
        //returns referensce to the curr's node's vector of values
        //each node has a vector of values

    }

};

#endif // TREEMULTIMAP_INCLUDED
