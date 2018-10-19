#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

struct treeNode
{
  int val;
  unordered_set<treeNode* > neighbors;

  treeNode(int x) : val(x) {}
};

void addNode(treeNode* originalNode, int val)
{
  treeNode* newNode = new treeNode(val);

  newNode->neighbors.insert(originalNode);
  originalNode->neighbors.insert(newNode);

  return;
}

void bfs(treeNode* node)
{
  unordered_set<treeNode* > processedNodes;
  queue<treeNode* > nodeQueue;

  nodeQueue.push(node);

  while (!nodeQueue.empty())
  {
    // Establish current node
    treeNode* currentNode = nodeQueue.front();

    // Process the Node
    cout << currentNode->val << endl;

    // Add it to processedNodes
    processedNodes.insert(currentNode);

    // Add neighbors to queue (that are not in processedNodes)
    for (auto neighbor : currentNode->neighbors)
    {
      if (processedNodes.find(neighbor) == processedNodes.end())
      {
        // Neighbor not in our set, so add to queue;
        nodeQueue.push(neighbor);
      }
    }

    // Pop currentNode from Queue
    nodeQueue.pop();

  }

  return;
}

int main()
{
  treeNode* firstNode = new treeNode(15);

  for (int i = 0; i < 5; i++)
  {
    addNode(firstNode, i);
  }

  for (auto node : firstNode->neighbors)
  {
    int i = 9;
    while (i < 14)
    {
      addNode(node, i);
      i++;
    }
  }

  bfs(firstNode);

  return 0;
}