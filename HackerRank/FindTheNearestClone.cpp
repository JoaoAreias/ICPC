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
int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    map<int, vector<int>> graph;
    vector<int> matching_ids;
    int return_value = numeric_limits<int>::max();

    // Building graph
    for(int i=0; i<graph_nodes; i++){
        graph[graph_from[i]].push_back(graph_to[i]);
        graph[graph_to[i]].push_back(graph_from[i]);
        // If node has a matching id, add it to the vector
        if(ids[i-1] == val)
            matching_ids.push_back(i);
    }

    // Runs BFS for every node matching color
    queue<pair<int, int>> bfs_queue;
    vector<bool> visited(graph_nodes);
    int node, dist;
    pair<int, int> aux;

    for(const int &i: matching_ids){
        fill(visited.begin(), visited.end(), false);
        visited[i] = true;
        /* To find the shortest distance we must exclude the
        node itself so we add the nodes connected to it to the
        queue instead */
        for(const int &j: graph[i]){
            bfs_queue.push(make_pair(j, 1));
            visited[j] = true;
        }

        while(!bfs_queue.empty()){
            aux = bfs_queue.front();
            node = aux.first;
            dist = aux.second;
            bfs_queue.pop();
            /* Check if node color is the matching color
            and exit if condition is met*/
            if(ids[node-1] == val){
                if(dist < return_value)
                    return_value = dist;
                break;
            }
            // Continue search
            for(const int &j: graph[node]){
                if(!visited[j]){
                    visited[j] = true;
                    bfs_queue.push(make_pair(j, dist+1));
                }
            }
        }

        while(!bfs_queue.empty())
            bfs_queue.pop();
    }


    return (return_value == numeric_limits<int>::max() ? -1 : return_value);
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
