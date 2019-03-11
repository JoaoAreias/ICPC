#include <bits/stdc++.h>

using namespace std;
typedef unordered_map<int, vector<int>> Graph;


void dfs(Graph &graph, vector<bool> &visited, int node){
	/* Visit connected nodes and mark
	them as visited */
	visited[node] = true;
	for(int i: graph[node]){
		if(!visited[i]){
			visited[i] = true;
			dfs(graph, visited, i);
		}
	}
}

int connectedComponents(Graph &graph){
	/* Counts number of connected components */
	vector<bool> visited(false, graph.size());
	int c_components = 0;

	for(auto &node: graph){
		if(!visited[node.first]){
			dfs(graph, visited, node.first);
			c_components++;
		}
	}

	return c_components;
}

int main(){
	Graph graph;
	string str1, str2, str3;
	int M, N;
	
	unordered_map<string, int> index; // Index name to node value
	int max_index = 0; // Maximum index so far
	
	cin >> M >> N;

	graph.reserve(M);
	while(N--){
		cin >> str1 >> str2 >> str3;
		cout << str1 << " " << str3 << endl;
		// Indexes names
		if(index.find(str1) == index.end())
			index[str1] = max_index++;
		
		if(index.find(str3) == index.end())
			index[str3] = max_index++;

		// Building graph
		graph[index[str1]].push_back(index[str3]);
		graph[index[str3]].push_back(index[str1]);
	}

	cout << connectedComponents(graph) << endl;
	
	return 0;
}