#include <bits/stdc++.h>

using namespace std;

int main(){
	double vf[10], vr[10];
	int f, r;
	double ratios[100];

	while(scanf("%d", &f) && f){
		// Input
		scanf("%d", &r);
		for(int i=0; i<f; i++)
			scanf("%lf", &vf[i]);
		for(int i=0; i<r; i++)
			scanf("%lf", &vr[i]);

		// Drive ratios
		int back = 0;
		for(int i=0; i<f; i++){
			for(int j=0; j<r; j++){
				ratios[back++] = vr[j]/vf[i];
			}
		}
		sort(ratios, ratios + f*r);

		// Search
		double max_spread = -1;
		for(int i=0; i < r*f - 1; i++){
			max_spread = max(max_spread, ratios[i+1]/ratios[i]);
		}

		printf("%.2lf\n", max_spread);
	}
}