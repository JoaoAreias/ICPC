#include <bits/stdc++.h>

typedef std::pair<int, int> Edge;
typedef std::unordered_map<int, std::vector<int>> Graph;

bool conflict(Edge &e1, Edge &e2){
    return ((e1.first < e2.first && e2.first < e1.second && e1.second < e2.second) ||
            (e2.first < e1.first && e1.first < e2.second && e2.second < e1.second));
}

void insert_edges(Graph &store_nodes, std::vector<Edge> &edges){
    for(auto it: store_nodes){
        std::vector<int> &v = it.second;
        for(int i = 0; i < v.size(); i++){
            for(int j = i+1; j < v.size(); j++){
                edges.push_back({v[i], v[j]});
            }
        }
    }
}

void build_conflict_graph(std::vector<Edge> &edges, Graph &conflict_graph){
    for(int i = 0; i < edges.size(); i++){
        for(int j = i+1; j < edges.size(); j++){
            if(conflict(edges[i], edges[j])){
                conflict_graph[i].push_back(j);
                conflict_graph[j].push_back(i);
            }
        }
    }
}


bool is_bipartide(Graph &conflict_graph){
    int n = conflict_graph.size();
    if(n == 0)
        return true;
    
    std::vector<int> color(n, -1);
    std::queue<int> q;

    for(auto it: conflict_graph){
        int i = it.first;
        if(color[i] != -1)
            continue;

            
        color[i] = 0;
        q.push(i);

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v: conflict_graph[u]){
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if(color[v] == color[u]){
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    int N;
    std::vector<Edge> edges;
    Graph store_nodes;
    Graph conflict_graph;
    
    // Otimiza a entrada e saida
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;
    
    int max_size = 0;
    for(int i=0; i < N; i++){
        int aux;
        std::cin >> aux;
        store_nodes[aux].push_back(i);
        if (store_nodes[aux].size() > max_size)
            max_size = store_nodes[aux].size();
    }
    
    // Grafo é homomorfo a K5
    if(max_size >= 5){
        std::cout << "N" << std::endl;
        return 0;
    }

    insert_edges(store_nodes, edges);
    store_nodes.clear(); // Libera memoria
    build_conflict_graph(edges, conflict_graph);
    edges.clear(); // Libera memoria
    std::cout << (is_bipartide(conflict_graph) ? "S" : "N") << std::endl;
    return 0;
}