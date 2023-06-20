#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>

typedef std::pair<int, int> Edge;

bool conflict(Edge &e1, Edge &e2){
    return ((e1.first < e2.first && e2.first < e1.second && e1.second < e2.second) ||
            (e2.first < e1.first && e1.first < e2.second && e2.second < e1.second));
}

void insert_edges(std::unordered_map<int, std::vector<int>> &store_nodes, std::vector<Edge> &edges){
    for(auto it: store_nodes){
        std::vector<int> &v = it.second;
        for(int i = 0; i < v.size(); i++){
            for(int j = i+1; j < v.size(); j++){
                edges.push_back({v[i], v[j]});
            }
        }
    }
}

void build_conflict_graph(std::vector<Edge> &edges, std::unordered_map<int, std::vector<int>> &conflict_graph){
    for(int i = 0; i < edges.size(); i++){
        for(int j = i+1; j < edges.size(); j++){
            if(conflict(edges[i], edges[j])){
                conflict_graph[i].push_back(j);
                conflict_graph[j].push_back(i);
            }
        }
    }
}


bool is_bipartide(std::unordered_map<int, std::vector<int>> &conflict_graph){
    if(conflict_graph.size() == 0)
        return true;
    
    std::vector<int> color(conflict_graph.size(), -1);
    std::queue<int> q;
    int src = 0;
    q.push(src);
    color[src] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v: conflict_graph[u]){
            if(color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if(color[v] == color[u])
                return false;
        }
    }

    return true;
}


void print_edges(std::vector<Edge> &edges){
    for(auto it: edges){
        std::cout << it.first << " " << it.second << std::endl;
    }
}

int main() {
    int N;
    std::vector<Edge> edges;
    std::unordered_map<int, std::vector<int>> store_nodes;
    std::unordered_map<int, std::vector<int>> conflict_graph;
    
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
    // print_edges(edges);
    
    build_conflict_graph(edges, conflict_graph);
    std::cout << (is_bipartide(conflict_graph) ? "S" : "N") << std::endl;
    return 0;
}