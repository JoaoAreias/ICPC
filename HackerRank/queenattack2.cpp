#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void print_matrix(int **M, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf(" %d", M[i][j]);
        }
        printf("\n");
    }
}

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    // Build board with margin for search
    int **board = new int*[n+2];
    for(int i=0; i< n+2; i++){
        board[i] = new int[n+2];
        if((i == 0) || (i == n+1))
            // pos = 0 is an obstacle
            memset(board[i], 0x00, (n+2)*sizeof(int));
        else{
            // pos != 0 is a free space
            memset(board[i], 0x01, (n+2)*sizeof(int));
            board[i][0] = board[i][n+1] = 0;
        }
    }
    
    // Adding obstacles
    for(vector<int> v: obstacles)
        board[v[0]][v[1]] = 0;

    // Count available spaces
    int count = 0;
    int aux = 0;
    // Up
    while(board[r_q + (++aux)][c_q])
        count++;
    aux = 0
    // Down
    while(board[r_q + (--aux)][c_q])
        count++;
    aux = 0
    // Left
    while(board[r_q][c_q + (++aux)])
        count++;
    aux = 0
    // Right
    while(board[r_q][c_q + (--aux)])
        count++;

    // Delete board
    for(int i=0; i<n+2; i++)
        delete[] board[i];
    delete[] board;

    printf("%d\n", count);
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
