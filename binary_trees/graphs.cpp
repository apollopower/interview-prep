// Representation of a graph:

// ADJECENCY LIST

// A list where the index represents the node and the value at that index
// is a list of the node's neighbors

vector<vector<int>> graph = {
    {1},
    {0,2,3},
    {1,3},
    {1,2}
};

// We can also use an unordered_map where the key represents the node
// and the values are the list of its neighbors:

unordered_map<int, vector<int>> mapGraph {
    {0, {1}},
    {1, {0,2,3}},
    {2, {1,3}},
    {3, {1,2}}
};

// ADJECENCY MATRIX

// A matrix of 0s and 1s indicating whether node x connects to node y
// (0 means no, 1 means yes).

vector<vector<int>> matrixGraph {
    {0, 1, 0, 0},
    {1, 0, 1, 1},
    {0, 1, 0, 1},
    {0, 1, 1, 0}
};


// ____


// ALGORITHMS

// BFS and DFS (Breadth-First-Search & Depth-First-Search)

// Lots of graph problems can be solved using these traversals:


// Is there a path between these two nodes in this undirected graph?
// Run DFS or BFS from one node and see if you can reach the desired node


// What's the shortest path between two nodes in this undirected, unweighted graph? 
// Run BFS from one node to another and backtrack.
// Note: BFS always finds the shortest path, assuming the graph is undirected and
// unweighted. DFS does not always find the shortest path.


// Can this undirected graph be colored with two colors?
// Run BFS, keeping track of the number of times we're visiting each node. If we ever
÷visit a node twice, then we have a cycle.