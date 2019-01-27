#include <bits/stdc++.h>

using namespace std;

int findRegion(vector<vector<int>> &grid, int i, int j){
    if((i < 0) || (j < 0) || i >= grid.size() || j >= grid[i].size() || grid[i][j] == 0)
        return 0;
    else{
        grid[i][j] = 0;
        return 1 + 
        findRegion(grid, i+1, j) + findRegion(grid, i, j+1) + 
        findRegion(grid, i-1, j) + findRegion(grid, i, j-1) + 
        findRegion(grid, i+1, j-1) + findRegion(grid, i-1, j+1) +
        findRegion(grid, i-1, j-1) + findRegion(grid, i+1, j+1); 
    }
}

// Complete the maxRegion function below.
int maxRegion(vector<vector<int>> grid) {
    int max_region = 0;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            if(grid[i][j] == 1)
                max_region = max(max_region, findRegion(grid, i, j));
        }
    }
    return max_region;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);

    fout << res << "\n";

    fout.close();

    return 0;
}
