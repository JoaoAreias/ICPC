#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
	unordered_map<char, int> freq;
	bool valid = true;
	int freq_num;

	for(char c: s)
		freq[c]++;

	freq_num = freq[s[0]];
	for(pair<char, int> p: freq){
		if(p.second != freq_num){
			if(valid && min(p.second, abs(p.second - freq_num)) == 1)
				valid = false;
			else{
				return "NO";
			}
		}
	}

	return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
