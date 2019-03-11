#include <bits/stdc++.h>

using namespace std;

int fibonacci(int n) {
	static vector<int> memo(31, -1);
	memo[0] = 0;
	memo[1] = 1;
	return (memo[n] == -1 ? memo[n] = fibonacci(n-1) + fibonacci(n-2) : memo[n]);
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}

