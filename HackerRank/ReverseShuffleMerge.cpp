#include <bits/stdc++.h>

using namespace std;

// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(string s) {
	string out;
	map<char, int> freq_count;

	/* Output string must have half the frequency 
	 for each character as the original one */
	for(const char &c: s)
		freq_count[c]++;
	
	// Transversing string in reverse
	for(auto it=s.crbegin(); it != s.crend(); it++){
		
	}

	return out;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
