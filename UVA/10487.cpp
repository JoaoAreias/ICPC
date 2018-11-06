#include <bits/stdc++.h>

using namespace std;

int main(){
	int v[1000];
	int n, m, count = 1;

	while(scanf("%d", &n) && n){
		printf("Case %d:\n", count++);

		for(int i=0; i<n; i++)
			scanf("%d", &v[i]);

		scanf("%d", &m);
		for(int querry_n=0; querry_n<m; querry_n++){
			int sum, querry;
			scanf("%d", &querry);

			sum = v[0] + v[1];
			for(int i=0; i<n; i++){
				for (int j=0; j<n; j++){
					if(i == j)
						continue;
					if(abs(v[i] + v[j] - querry) < abs(sum - querry))
						sum = v[i] + v[j];
				}
			}
			printf("Closest sum to %d is %d.\n", querry, sum);
		}
	}
	return 0;
}