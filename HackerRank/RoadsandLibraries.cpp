#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the roadsAndLibraries function below.
unsigned long long roadsAndLibraries(long n, long c_lib, long c_road, vector<vector<long>> cities) {
    unordered_map<long, vector<long>> graph;
    vector<bool> visited(n+1, false);
    long connected_components;
    unsigned long long cost=0;

    if(c_lib <= c_road)
        return (unsigned long long)(n)*(unsigned long long)(c_lib);
    
    // Building graph
    for(vector<long> road: cities){
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }
    // Check connected components
    stack<long> dfs_stack;
    for(long node=1; node <= n; node++){
        if(visited[node])
            continue;

        cost += c_lib;
        visited[node] = true;
        connected_components++;
        dfs_stack.push(node);
        long current_node;
        while(!dfs_stack.empty()){
            current_node = dfs_stack.top();
            dfs_stack.pop();

            for(long i: graph[current_node]){
                if(!visited[i]){
                    cost += c_road;
                    visited[i] = true;
                    dfs_stack.push(i);
                }
            }
        }
    }
    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<long>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        unsigned long long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

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
