#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, a[1000], count=0;

		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", &a[i]);

		for(int i=1; i<n; i++){
			for(int j=0; j<i; j++){
				if(a[i] >= a[j])
					count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}