#include <bits/stdc++.h>

using namespace std;

// Complete the stepPerms function below.
int stepPerms(int n) {
    // f(n) = f(n-1) + f(n-2) + f(n-3)
    static vector<int> memo(37, -1); 
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;
    return (memo[n] == -1 ? 
        memo[n] = stepPerms(n-1) + stepPerms(n-2) + stepPerms(n-3) :
        memo[n]
    );
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
