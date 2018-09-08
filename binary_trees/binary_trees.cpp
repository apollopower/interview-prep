class BinaryTreeNode
{
    public:

        int value_;
        BinaryTreeNode* left_;
        BinaryTreeNode* right_;

        // Constructor
        BinaryTreeNode(int value) :
            value_(value);
            left_(nullptr);
            right_(nullptr);
        {}

        // Destructor
        ~BinaryTreeNode()
        {
            delete left_;
            delete right_;
        }
}