#include <iostream>

using namespace std;


struct node {
    int key;
    node *left;
    node *right;
};

// Function prototypes
node* insert(node *p_tree, int key);

// Main function call
int main() {
    cout << "Binary Tree Simulator\n";

    node *p_tree= NULL;

    p_tree = insert(p_tree, 10);
    p_tree = insert(p_tree, 6);
    p_tree = insert(p_tree, 14);
    p_tree = insert(p_tree, 5);
    p_tree = insert(p_tree, 8);
    p_tree = insert(p_tree, 11);
    p_tree = insert(p_tree, 18);

    cout << p_tree->key << endl;
}

// Function definitions
node* insert(node *p_tree, int val) {
    if (p_tree == NULL) {
        node* p_new_tree = new node;
        p_new_tree->key = val;
        p_new_tree->left = NULL;
        p_new_tree->right = NULL;
        return p_new_tree;
    }
    else if (val < p_tree->key) {
        p_tree->left = insert(p_tree->left, val);
    }
    else {
        p_tree->right = insert(p_tree->right, val);
    }   
    return p_tree;
}
