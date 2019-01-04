#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
	map<char, int> count_a, count_b;
	int count = 0;

	for(char c: a)
		count_a[c]++;
	for(char c: b)
		count_b[c]++;
	for(char c: "abcdefghijklmnopqrstuvwxyz")
		count += abs(count_a[c] - count_b[c]);
	return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
