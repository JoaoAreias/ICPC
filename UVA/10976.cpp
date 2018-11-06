#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	vector<pair<int, int> >solutions;
	int k;

	while(cin >> k){
		solutions.clear();
		for(int y = k+1; y <= 2*k; y++)
			if((k*y) % (y - k) == 0)
				solutions.push_back(make_pair((k*y)/(y - k), y));

		cout << solutions.size() << endl;
		for(auto sol: solutions){
			cout << "1/" << k
				 << " = 1/" << sol.first
				 << " + 1/" << sol.second
				 << endl;
		}
	}
}