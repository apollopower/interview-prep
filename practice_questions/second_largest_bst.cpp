#include <iostream>
#include <memory>

using namespace std;

class BinaryTreeNode
{
public:
    int value_;
    BinaryTreeNode* left_;
    BinaryTreeNode* right_;

    BinaryTreeNode(int value) :
        value_(value),
        left_(nullptr),
        right_(nullptr)
    {
    }

    ~BinaryTreeNode()
    {
        delete left_;
        delete right_;
    }

    BinaryTreeNode* insertLeft(int value)
    {
        this->left_ = new BinaryTreeNode(value);
        return this->left_;
    }

    BinaryTreeNode* insertRight(int value)
    {
        this->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
};

int findLargest(const BinaryTreeNode* rootNode)
{
    if (rootNode->right_)
    {
        return findLargest(rootNode->right_);
    }
    
    return rootNode->value_;
}

int findSecondLargest(const BinaryTreeNode* rootNode)
{
    // find the second largest item in the binary search tree
    
    // Test case: no children node or node itself
    if (!rootNode || (!rootNode->left_ && !rootNode->right_))
    {
        throw invalid_argument("Tree must have at least 2 nodes");
    }
    
    // Case: We are on the largest, and largest has a left subtree,
    // so 2nd largest is in the leftsubtree
    if (rootNode->left_ && !rootNode->right_)
    {
        return findLargest(rootNode->left_);
    }
    
    // Case we're at parent of largest, and largest has no left subtree,
    // so 2nd largest must be the current node (AKA, the parent)
    if (rootNode->right_ &&
            !rootNode->right_->left_ &&
            !rootNode->right_->right_)
    {
        return rootNode->value_;
    }
    
    
    // If none of the conditions above are met, move to the next right
    // element
    return findSecondLargest(rootNode->right_);
    

    return false;
}