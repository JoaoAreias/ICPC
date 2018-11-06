#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull polynomial(const vector<int> &coeff, int n){
	ull val = 0;
	int size = coeff.size();
	for(int c=0; c < size; c++){
		val += coeff[c]*pow(n, c);
	}
	return val;
}

ull k_th(const vector<int> &coeff, int d, int k){
	for(int n=1; n < 1e6; n++){
		if((k > d*n*(n-1)/2) && (k <= d*n*(n+1)/2))
			return polynomial(coeff, n);
	}
}

int main(){
	int C;
	scanf("%d", &C);
	while(C--){
		vector<int> coeff;
		int k, d, n;

		scanf("%d", &n);
		coeff.resize(n+1);
		for(int i=0; i <= n; i++)
			scanf("%d", &coeff[i]);

		scanf("%d", &d);
		scanf("%d", &k);
		
		printf("%llu\n", k_th(coeff, d, k));
	}
	return 0;
}