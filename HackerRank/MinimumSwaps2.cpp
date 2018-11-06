#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int count=0, size=arr.size();
    map<int, int> graph;
    // Get sorted version of the array
    vector<int> sorted;
    sorted.resize(size);
    copy(arr.begin(), arr.end(), sorted.begin());
    sort(sorted.begin(), sorted.end());
    // Sorted index
    map<int, int> index;
    for(int i=0; i<size; i++)
        index[sorted[i]] = i;
    // Build graph
    for(int i=0; i<size; i++)
        if(arr[i] != sorted[i])
            graph[i] = index[arr[i]];
    // Find cycle sizes
    vector<bool> visited(size, false);
    for(pair<int, int> p: graph){
        if(visited[p.first])
            continue;
        int curr=p.first, next=p.second;
        int cycle_size=0;
        while(!visited[curr]){
            cycle_size++;
            visited[curr] = true;
            curr = next;
            next = graph[next];
        }
        count += cycle_size - 1;
    }
    printf("%d\n", count);
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

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
