// Going over different traversal methods for a binary tree:

// First, create the struct for our binary tree:

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    // Initializer
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Second, method for inserting inside the binary tree:

TreeNode* buildTree(TreeNode* head, int x)
{
    if (head == NULL)
    {
        TreeNode* newHead = new TreeNode(x);
        return newHead;
    }
    else if (x < head->val)
    {
        head->left = buildTree(head->left, x);
    }
    else
    {
        head->right = buildTree(head->right, x);
    }

    return head;
}

// 1) INORDER TRAVERSAL; Left child, parent, right child
void inOrderTraversal(head)
{
    if (head == NULL) return;

    inOrderTraversal(head->left);

    std::cout << head->val << std::endl;

    inOrderTraversal(head->right);
}

// 2) POSTORDER TRAVERSAL; Children, then parent
void preOrderTraversal(head)
{
    if (head == NULL) return;

    preOrderTraversal(head->left);

    preOrderTraversal(head->right);

    std::cout <<head->val << std::endl;
}

// 3) PREORDER TRAVERSAL; Parent, then children
void postOrderTraversal(head)
{
    if (head == NULL) return;

    std::cout << head->val << endl;

    postOrderTraversal(head->left);

    postOrderTraversal(head->right);
}

int main()
{
    return 0;
}