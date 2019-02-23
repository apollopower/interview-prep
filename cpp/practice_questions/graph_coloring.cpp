#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>


using namespace std;

class GraphNode
{
private:
    string label_;
    unordered_set<GraphNode*> neighbors_;
    string color_;

public:
    GraphNode(const string& label) :
        label_(label),
        neighbors_(),
        color_()
    {
    }

    const string& getLabel() const
    {
        return label_;
    }

    const unordered_set<GraphNode*> getNeighbors() const
    {
        return neighbors_;
    }

    void addNeighbor(GraphNode& neighbor)
    {
        neighbors_.insert(&neighbor);
    }

    bool hasColor() const
    {
        return !color_.empty();
    }

    const string& getColor() const
    {
        if (hasColor()) {
            return color_;
        }
        else {
            throw logic_error("GraphNode is not marked with color");
        }
    }

    void setColor(const string& color)
    {
        color_ = color;
    }
};

void colorGraph(const vector<GraphNode*>& graph, const vector<string>& colors)
{
    // create a valid coloring for the graph
    queue<GraphNode* > bfsQueue;
    bfsQueue.push(graph[0]);
    while (!bfsQueue.empty())
    {
        GraphNode* currentNode = bfsQueue.front();
        
        // Step 1: Set neighbors, create empty set for
        // colors to check.
        auto neighbors = currentNode->getNeighbors();
        unordered_set<string> neighborColors;
        
        for (auto neighbor : neighbors)
        {
            if (neighbor->hasColor())
            {
                // insert neighbor color into unordered set
                neighborColors.insert(neighbor->getColor());
            }
            // add neighbor to the queue
            bfsQueue.push(neighbor);
        }
        
        
        for (auto color : colors)
        {
            
            if (neighborColors.find(color) == neighborColors.end())
            {
                // Didn't find it, set the color
                currentNode->setColor(color);
                break;
            }
        }
        
        
        
        // Step 3: Remove node from Queue
        
        // Pop the currentnode
        bfsQueue.pop();
    }
    
    return;

}



// OTHER SOLUTION : ITERATING OVER VECTOR OF NODES

void colorGraph(const vector<GraphNode*>& graph, const vector<string>& colors)
{
    for (auto node : graph)
    {
        // Keeping track of all node's neighbors
        auto neighbors = node->getNeighbors();

        // Set for illegalColors that will belong to neighbors.
        // if we have a color in here for a specific iteration
        // we will not be able to use it
        unordered_set<string> illegalColors;

        for (auto neighbor : neighbors)
        {
            // Edge case: node has a loop, which makes it impossible
            // to solve the problem. Throw an exception
            if (neighbor == node)
            {
                throw invalid_argument("Can't color node that has a loop!");
            }

            // For the neighbor, check if it has a color. If so,
            // add it to our set:
            if (neighbor->hasColor())
            {
                illegalColors.insert(neighbor->getColor());
            }

        }

        // Now to color in our current node. We iterate through our color
        // options: if its not in the set, we color in our node with that
        // given color
        for (const auto& color : colors)
        {
            if (illegalColors.find(color) == illegalColors.end())
            {
                // Didn't find this color!
                node->setColor(color);

                // Now we set the color, break the loop since we 
                // dont need to check other colors
                break;
            }
        }
    }

    return;
}










// tests

vector<string> getColors()
{
    return vector<string> {"red", "green", "blue", "orange", "yellow", "white"};
}

bool validateGraphColoring(const vector<GraphNode*>& graph);

const lest::test tests[] = {
    CASE("line graph") {
        const auto nodeA = unique_ptr<GraphNode>(new GraphNode("A")); 
        const auto nodeB = unique_ptr<GraphNode>(new GraphNode("B")); 
        const auto nodeC = unique_ptr<GraphNode>(new GraphNode("C")); 
        const auto nodeD = unique_ptr<GraphNode>(new GraphNode("D"));
        nodeA->addNeighbor(*nodeB);
        nodeB->addNeighbor(*nodeA);
        nodeB->addNeighbor(*nodeC);
        nodeC->addNeighbor(*nodeB);
        nodeC->addNeighbor(*nodeD);
        nodeD->addNeighbor(*nodeC);
        const vector<GraphNode*> graph { nodeA.get(), nodeB.get(), nodeC.get(), nodeD.get() };
        colorGraph(graph, getColors());
        const auto result = validateGraphColoring(graph);
        EXPECT(result == true); 
    },
    CASE("separate graph") {
        const auto nodeA = unique_ptr<GraphNode>(new GraphNode("A")); 
        const auto nodeB = unique_ptr<GraphNode>(new GraphNode("B")); 
        const auto nodeC = unique_ptr<GraphNode>(new GraphNode("C")); 
        const auto nodeD = unique_ptr<GraphNode>(new GraphNode("D"));
        nodeA->addNeighbor(*nodeB);
        nodeB->addNeighbor(*nodeA);
        nodeC->addNeighbor(*nodeD);
        nodeD->addNeighbor(*nodeC);
        const vector<GraphNode*> graph { nodeA.get(), nodeB.get(), nodeC.get(), nodeD.get() };
        colorGraph(graph, getColors());
        const auto result = validateGraphColoring(graph);
        EXPECT(result == true); 
    },
    CASE("triangle graph") {
        const auto nodeA = unique_ptr<GraphNode>(new GraphNode("A")); 
        const auto nodeB = unique_ptr<GraphNode>(new GraphNode("B")); 
        const auto nodeC = unique_ptr<GraphNode>(new GraphNode("C")); 
        nodeA->addNeighbor(*nodeB);
        nodeA->addNeighbor(*nodeC);
        nodeB->addNeighbor(*nodeA);
        nodeB->addNeighbor(*nodeC);
        nodeC->addNeighbor(*nodeA);
        nodeC->addNeighbor(*nodeB);
        const vector<GraphNode*> graph { nodeA.get(), nodeB.get(), nodeC.get() };
        colorGraph(graph, getColors());
        const auto result = validateGraphColoring(graph);
        EXPECT(result == true); 
    },
    CASE("envelope graph") {
        const auto nodeA = unique_ptr<GraphNode>(new GraphNode("A")); 
        const auto nodeB = unique_ptr<GraphNode>(new GraphNode("B")); 
        const auto nodeC = unique_ptr<GraphNode>(new GraphNode("C")); 
        const auto nodeD = unique_ptr<GraphNode>(new GraphNode("D")); 
        const auto nodeE = unique_ptr<GraphNode>(new GraphNode("E")); 
        nodeA->addNeighbor(*nodeB);
        nodeA->addNeighbor(*nodeC);
        nodeB->addNeighbor(*nodeA);
        nodeB->addNeighbor(*nodeC);
        nodeB->addNeighbor(*nodeD);
        nodeB->addNeighbor(*nodeE);
        nodeC->addNeighbor(*nodeA);
        nodeC->addNeighbor(*nodeB);
        nodeC->addNeighbor(*nodeD);
        nodeC->addNeighbor(*nodeE);
        nodeD->addNeighbor(*nodeB);
        nodeD->addNeighbor(*nodeC);
        nodeD->addNeighbor(*nodeE);
        nodeE->addNeighbor(*nodeB);
        nodeE->addNeighbor(*nodeC);
        nodeE->addNeighbor(*nodeD);
        const vector<GraphNode*> graph { 
            nodeA.get(), nodeB.get(), nodeC.get(), nodeD.get(), nodeE.get()
        };
        colorGraph(graph, getColors());
        const auto result = validateGraphColoring(graph);
        EXPECT(result == true); 
    },
    CASE("loop graph") {
        const auto nodeA = unique_ptr<GraphNode>(new GraphNode("A")); 
        nodeA->addNeighbor(*nodeA);
        const vector<GraphNode*> graph { nodeA.get() };
        EXPECT_THROWS(colorGraph(graph, getColors()));
    }
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}

bool validateGraphColoring(const vector<GraphNode*>& graph)
{
    if (!all_of(graph.cbegin(), graph.cend(),
        [](const GraphNode* node) { return node->hasColor(); })) {
        // non-colored node found
        return false;
    }

    size_t maxDegree = 0;
    unordered_set<string> usedColors;

    for (const auto node : graph) {
        const auto& neighbors = node->getNeighbors();
        maxDegree = max(maxDegree, neighbors.size());
        usedColors.insert(node->getColor());
    }

    size_t allowedColorCount = maxDegree + 1;

    if (usedColors.size() > allowedColorCount) {
        // too many colors used
        return false;
    }

    for (const auto node : graph) {
        const auto& neighbors = node->getNeighbors();
        for (const auto neighbor: neighbors) {
            if (neighbor->getColor() == node->getColor()) {
                // node with same color as neighbor found
                return false;
            }
        }
    }

    return true;
}

vector<GraphNode*> makeGraphVector(const vector<unique_ptr<GraphNode>>& nodes)
{
    vector<GraphNode*> graph;
    for (const auto& node: nodes) {
        graph.push_back(node.get());
    }
    return graph;
}