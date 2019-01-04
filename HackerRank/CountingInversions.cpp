#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long _merge(vector<int> &v, int left, int middle, int right){
    int range = right - left + 1;
    vector<int> temp(range);
    long inversions = 0;
    int vi = left, vj= middle;

    for(int i=0; i < range; i++){
        if(vj > right)
            temp[i] = v[vi++];

        else if(vi >= middle)
            temp[i] = v[vj++];
        
        else if(v[vj] < v[vi]){
            inversions += middle - vi;
            temp[i] = v[vj++];
        }

        else
            temp[i] = v[vi++];
    }
    copy(temp.begin(), temp.end(), v.begin() + left);
    
    return inversions;
}

long _merge_sort(vector<int> &v, int left, int right){
    // Sort vector and return number of inversions
    if(left == right)
        return 0;

    long inv_count;
    int middle = (left + right)/2;
    inv_count =  _merge_sort(v, left, middle);
    inv_count += _merge_sort(v, middle+1, right);
    return inv_count + _merge(v, left, middle+1, right);
}

long merge_sort(vector<int> &v){
    return _merge_sort(v, 0, v.size()-1);
}

// Complete the countInversions function below.
long countInversions(vector<int> arr) {
    long inversions = merge_sort(arr);
    return inversions;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
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

        long result = countInversions(arr);

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
