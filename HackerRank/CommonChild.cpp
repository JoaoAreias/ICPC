#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
	vector<vector<int>> M;
	int size_1 = s1.size();
	int size_2 = s2.size();
	
	M.resize(size_1 + 1);
	for(int i=0; i<=size_1; i++)
		M[i].resize(size_2 + 1);
	
	for(int i=0; i<=size_1; i++){
		for(int j=0; j<=size_2; j++){
			if(i == 0 || j == 0)
				M[i][j] = 0;
			else if(s1[i-1] == s2[j-1])
				M[i][j] = M[i-1][j-1] + 1;
			else
				M[i][j] = max(M[i-1][j], M[i][j-1]);
		}
	}
	return M[size_1][size_2];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
