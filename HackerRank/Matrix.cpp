#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

class UnionFind{
/* 
Modified based on the code on the book 
competitive programming 3 
by Steven Halim & Felix Halim
*/
private:
    vector<int> p, rank;
    vector<bool> machine;
public:
    UnionFind(int n){ 
        rank.assign(n, 0);
        p.assign(n, 0);
        machine.assign(n, false);
        for(int i=0; i<n; i++)
            p[i] = i;
    }
    int findSet(int i){
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        int x = findSet(i), y = findSet(j);
        if(rank[x] > rank[y]){
            p[y] = x;
            machine[p[x]] = machine[x] || machine[y] ;
        }
        else{
            p[x] = y;
            machine[p[y]] = machine[x] || machine[y];
            if(rank[x] == rank[y])
                rank[y]++;
        } 
    }
    bool hasMachine(int n){
        // Asks if there is a machine in same set as n
        return machine[findSet(n)];
    }
    void isMachine(int n){
        // Tells that node n is a machine
        machine[findSet(n)] = true;
    }
};

// Complete the minTime function below.
int minTime(vector<vector<int>> roads, vector<int> machines) {
    UnionFind uf(roads.size() + 1); // There are n-1 roads with n being the number of cities
    int cost = 0;
    // Sorting roads by time cost
    sort(roads.begin(), roads.end(), [](vector<int> a, vector<int> b){ return a[2] > b[2];});
    // Informs which cities have machines to set
    for(const int &i: machines)
        uf.isMachine(i);
    // Modified Kruskall algorithm
    for(const vector<int> &road: roads){
        if(uf.hasMachine(road[0]) && uf.hasMachine(road[1]))
            cost += road[2];
        else
            uf.unionSet(road[0], road[1]);
    }
    cout << cost << endl;
    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> roads(n - 1);
    for (int i = 0; i < n - 1; i++) {
        roads[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> roads[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> machines(k);

    for (int i = 0; i < k; i++) {
        int machines_item;
        cin >> machines_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        machines[i] = machines_item;
    }

    int result = minTime(roads, machines);

    fout << result << "\n";

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
