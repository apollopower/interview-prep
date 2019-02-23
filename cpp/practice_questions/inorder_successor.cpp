// Given a root node and another node value, p, return the next node that
// would appear an in-order traversal.

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
    if (root == NULL) return NULL;
        
    TreeNode* next = NULL;
    
    while (root != NULL)
    {
        if (root->val <= p->val)
        {
            root = root->right;
        }
        else
        {
            next = root;
            root = root->left;
        }
    }
        
    return next;
        
}