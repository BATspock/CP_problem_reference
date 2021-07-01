#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;

    list<int> *adj;

    public:
        Graph(int V){
            this->V = V;
            adj = new list<int>[V];

        }

        void addEdge(int v, int w){
            adj[v].push_back(w);
        }

        void BFS(int s){

            vector<bool> visited(V, false);
            queue<int> bfsq;

            visited[s] = true;
            bfsq.push(s);

            while(!bfsq.empty()){
                s = bfsq.front();
                cout<<"visited node: " << s <<endl;
                bfsq.pop();

                for (auto v: adj[s]){
                    if (!visited[v]){
                        visited[v] = true;
                        bfsq.push(v);
                    }
                }
            }
        }

        bool CheckCycle(int s){

            vector<bool> visited(V, false);
            queue<int> bfsq;

            visited[s] = true;
            bfsq.push(s);

            while(!bfsq.empty()){
                s = bfsq.front();
                cout<<"visited node: " << s <<endl;
                bfsq.pop();

                for (auto v: adj[s]){
                    if (visited[v]) return true;
                }

                for (auto v: adj[s]){
                    if (!visited[v]){
                        visited[v] = true;
                        bfsq.push(v);
                    }
                }
            }

            return false;
            
        }

};





int main(){

    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);

    if (g.CheckCycle(2)) {
        cout<<"Contains Cycle"<<endl;
    }

    else cout<<"No cycle"<<endl;

    return 0;
}