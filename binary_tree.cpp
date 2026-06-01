//binary_tree.cpp

//simple binary tree capable of storing numbers, identifying their presence in the tree, and inserting new nodes in c++
#include <iostream>
#include <queue>
using namespace std;

//template class for the nodes of the binary tree
template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    //constructor initializes node w val
    Node(T value) : data(value), left(nullptr), right(nullptr) {}

};

template <typename T>
class BinaryTree {
    Node<T>* root; //points to root of tree

public:
    BinaryTree() : root(nullptr) {}

    //preorder traversal (internal)
    void preorder(Node<T>* node){
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    //search for a value starting at node `c`
    Node<T>* search(Node<T>* c, T value){
        if (c == nullptr) return nullptr;
        if (c->data == value){
            cout << "Value found in tree." << endl;
            return c;
        }
        Node<T>* left = search(c->left, value);
        if (left) return left;
        return search(c->right, value);
    }

    //insert node into tree (level-order)
    Node<T>* insert(T value){
        Node<T>* new_node = new Node<T>(value);
        if(root == nullptr)
        {
            root = new_node;
            return root;
        }

        queue<Node<T>*> q;
        q.push(root);

        while(!q.empty())
        {
            Node<T>* c = q.front();
            q.pop();

            if(c->left == nullptr)
            {
                c->left = new_node;
                return c->left;
            }
            else
            {
                q.push(c->left);
            }

            if(c->right == nullptr)
            {
                c->right = new_node;
                return c->right;
            }
            else
            {
                q.push(c->right);
            }
        }
        return nullptr;
    }

    //helper to expose root for callers
    Node<T>* getRoot() { return root; }

    //print full tree in preorder
    void printPreorder(){
        if(root == nullptr){
            cout << "Tree is empty." << endl;
            return;
        }
        preorder(root);
        cout << endl;
    }
}; //END CLASS TEMPLATE


int main() 
{
    cout << "This is a simple binary tree capable of storing numbers and identifying their presence in the tree." << endl;
  
    //create tree
    BinaryTree<int> tree;

    //how many nodes
    int n;
    cout << "How many nodes do you want to insert into the tree? ";
    if(!(cin >> n)) return 0;
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter number " << i + 1 << ": ";
        cin >> value;
        tree.insert(value);
    }

    //is present?
    int val;
    cout << "Enter a number that you would like to check for in the tree: ";
    cin >> val;
    if(tree.search(tree.getRoot(), val) == nullptr)
        cout << "Value not found in tree." << endl;

    //newnode
    cout << "What value would you like inserted into a new node: ";
    cin >> val;
    tree.insert(val);

    cout << "Preorder traversal: ";
    tree.printPreorder();
    
  
  return 0;

}
