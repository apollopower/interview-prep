#include <iostream>

using namespace std;

struct Node 
{
  int val;
  Node* prev;
  Node* next;
};

Node* buildNode(Node* p_list, int num)
{
  Node* new_node = new Node;
  new_node->val = num;
  new_node->prev = nullptr;
  new_node->next = p_list;
  return new_node;
}



int main()
{
  Node* p_list = nullptr;

  for (int i = 0; i < 10; i++)
  {
    p_list = buildNode(p_list, i);
  }

  // cout << p_list->val << endl;
  
  Node* current_node = p_list;

  while (current_node != nullptr)
  {
    cout << current_node->val << endl;
    current_node = current_node->next;
  }

}