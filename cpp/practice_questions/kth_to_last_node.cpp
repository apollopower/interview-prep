// Pseudo-Code Class
class Node
{
    public:
        int intValue_;
        Node* next_;

}

Node* kthToLastNode(size_t k, Node* head)
{
    if (k < 1) throw invalid_argument("K needs to within bounds of list!");

    Node* current = head;
    size_t listLength = 1;

    while (current->next_)
    {
        listLength++;
        current = current->next_;
    }

    if (k > listLength) throw invalid_argument("K must be smaller than size of list!");

    size_t target = listLength - k;

    current = head;

    for (size_t i = 0; i < target; i++)
    {
        current = current->next_;
    }

    return current;
}