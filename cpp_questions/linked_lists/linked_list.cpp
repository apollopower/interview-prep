#include <iostream>

// Our Node struct, specifing an int value and pointer to the
// next node:
struct Node
{
    int value_;
    Node* next_;
};

// Our linked list class, which will contain all the functions.
// We specify two important pointers for the head and tail of
// the list, and we initialize them to null to avoid garbage
// values
class List
{
    private:

        Node* head;
        Node* tail;
    
    public:

        List()
        {
            head = nullptr;
            tail = nullptr;
        }

        // Function prototypes
        void createNode(int value);
        void display();
        void insertStart(int value);
        void insertPosition(int pos, int value);

};

// Create a new node:
void List::createNode(int value)
{
    // Creating our new node. Setting it as temp, as we
    // we will delete it after proper allocation:

    Node* temp = new Node; // IMPORTANT, allocator memory for temp node.
    temp->value_ = value;
    temp->next_ = nullptr;

    // If head is null, list is empty! 
    if (head == nullptr)
    {
        head = temp;
        tail = temp;
        delete temp;
    }
    // We already have a list (And tail is already defined if 
    // there is one, see conditional above), so we set
    // tail->next_ equal to temp, then get rid of it.
    else
    {
        tail->next_ = temp;
        delete temp;
    }
}

void List::display()
{
    Node* temp = new Node;
    temp = head;

    while (temp != nullptr)
    {
        cout << temp->value_ << endl;
        temp = temp->next_;
    }
    delete temp;
}

void List::insertStart(int value)
{
    // Allocate space for new node
    Node* newNode = new Node;
    // Set value of new node
    newNode->value_ = value;
    // Point it to the current head node
    newNode->next_ = head;
    // set newNode as the head (note this still
    // keeps newNode pointed to the old head, it
    // doesn't rewrite the old value of head above)
    head = newNode;
}

void List::insertPosition(int position, int value)
{
    Node* current = new Node;
    current = head;

    // 
}