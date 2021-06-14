#include<bits/stdc++.h>

using namespace std;

class Graph
{
    int V;    // No. of vertices
 
    // Pointer to an array containing adjacency
    // lists
    list<int> *adj;  
public:
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    } // Constructor
 
    // function to add an edge to graph
    void addEdge(int v, int w){
        adj[v].push_back(w);
    }
 
    // prints BFS traversal from a given source s
    void BFS(int s){
        vector<bool> visited(V,false);
        queue<int> bfsq;

        visited[s] = true;
        bfsq.push(s);

        while(!bfsq.empty()){
            cout<< "visited node: "<<bfsq.front()<<endl;
            s = bfsq.front();
            bfsq.pop();

            for (auto v: adj[s]){
                if (!visited[v]){
                    visited[v] = true;
                    bfsq.push(v);
                }
            }
        }
    } 
};

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}