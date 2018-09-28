#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <deque>


unordered_map<string, vector<string> > network {
    { "Min",     { "William", "Jayden", "Omar" } },
    { "William", { "Min", "Noam" } },
    { "Jayden",  { "Min", "Amelia", "Ren", "Noam" } },
    { "Ren",     { "Jayden", "Omar" } },
    { "Amelia",  { "Jayden", "Adam", "Miguel" } },
    { "Adam",    { "Amelia", "Miguel", "Sofia", "Lucas" } },
    { "Miguel",  { "Amelia", "Adam", "Liam", "Nathan" } },
    { "Noam",    { "Nathan", "Jayden", "William" } },
    { "Omar",    { "Ren", "Min", "Scott" } },
};

void breadthFirstSearch(const unordered_map<string, vector<string>>& network, const string& startNode, const string& endNode)
{
    deque<string> nodesToVisit;
    nodesToVisit.push_back(startNode);

    // Keep track of nodes we already seen,
    // so we don't process them twice
    unordered_set<string> nodesAlreadySeen;
    nodesAlreadySeen.insert(startNode);

    while (!nodesToVisit.empty())
    {
        string currentNode = move(nodesToVisit.front());
        nodesToVisit.pop_front();

        if (currentNode == endNode)
        {
            // Found the endNode!
            nodesToVisit.push_back(currentNode);
            for (string node : nodesToVisit)
            {
                cout << node << endl;
            }
            break;
        }

        for (const auto& neighbor: network.find(currentNode)->second)
        {
            if (nodesAlreadySeen.count(neighbor) == 0)
            {
                nodesAlreadySeen.insert(neighbor);
                nodesToVisit.push_back(neighbor);
            }
        }


    }
}