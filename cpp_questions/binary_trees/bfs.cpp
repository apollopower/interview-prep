#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

struct graphNode {
  int val;

  set<graphNode* > neighbors;
  graphNode(int x) : val(x) {}
};


void bfs(graphNode* root)
{
  queue<graphNode* > graphQueue;
  graphQueue.push(root);
  while (!graphQueue.empty())
  {
    graphNode* currentNode = graphQueue.front();

    cout << "processing Node: " << currentNode->val << endl;

    for (auto node : currentNode->neighbors)
    {
      graphQueue.push(node);
    }

    graphQueue.pop();

  }
}



int main() {
  
  graphNode* test = new graphNode(1);

  for (int i = 1; i < 5; i++)
  {
    test->neighbors.insert(new graphNode(i));
  }

  for (auto node : test->neighbors)
  {
    for (int i = 1; i < 5; i++)
    {
      node->neighbors.insert(new graphNode(i));
    }
  }

  bfs(test);

  return 0;

}