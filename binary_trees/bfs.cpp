// Program to print BFS traversal from a given source
// vertex. BFS(int s) traverses vertices reachable from s.

#include <iostream>
#include <list>

using namespace std;

// Graph class using adjacency lists
class Graph
{
    int V; // Num. of vertices

    // Pointer to an array containing adjacency lists
    list<int>* adj;

    public:

        Graph(int V); // contructor

        // Functions to add an edge to graph
        void addEdge(int v, int w);

        // Prints BSF traversa; from a given source
        void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited:
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
}