/*
 NOT WORKING
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
long findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    unordered_map<int, vector<int>> graph;
    unordered_map<long, vector<int>> node_colors;
    // Find nodes with each color
    for(int i=0; i<ids.size(); i++)
        node_colors[ids[i]].push_back(i+1);
    // Can't find path with less than 2 nodes
    if(node_colors[val].size() < 2)
        return -1;
    // Build Graph
    for(int i=0; i<graph_nodes; i++){
        graph[graph_from[i]].push_back(graph_to[i]);
        graph[graph_to[i]].push_back(graph_from[i]);
    }
    // Find minimum distance
    queue<pair<int, int>> bfs_queue;
    long min_dist = (long)1e8;
    int curr_node, dist;
    for(int node:node_colors[val]){
        vector<bool> visited(graph_nodes, false);
        visited[node] = true;
        for(int n:graph[node]){
            visited[n] = true;
            bfs_queue.push(make_pair(n, 1));
        }
        while(true){
            curr_node = bfs_queue.front().first;
            dist = bfs_queue.front().second;
            visited[curr_node] = true;
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
