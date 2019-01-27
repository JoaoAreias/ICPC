#include <unordered_map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph {
    private:
        unordered_map<int, vector<int>> graph;
        int size;
    public:
        Graph(int n) {
            graph.reserve(n);
            size = n;
        }
    
        void add_edge(int u, int v) {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            vector<int> distances(size, -1);
            vector<bool> visited(size, false);
            queue<pair<int, int>> bfs_queue;

            bfs_queue.push(make_pair(start, 0));
            pair<int, int> aux;
            int node, dist;
            while(!bfs_queue.empty()){
                aux = bfs_queue.front();
                bfs_queue.pop();

                node = aux.first;
                dist = aux.second;

                distances[node] = dist;
                for(const int &i: graph[node]){
                    if(!visited[i]){
                        visited[i] = true;
                        bfs_queue.push(make_pair(i, dist+6));
                    }
                }
            }
            return distances;
        }
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
        int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
        int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}

