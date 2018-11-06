#include <bits/stdc++.h>
#define INF (1<<30) - 1
using namespace std;

int manhattan_distance(int pos, int y, int x){
	int a = pos%5;
	int b = pos/5;
	return abs(a-y) + abs(b - x);
}

int main(){
	int grid[5][5];
	int solutions[5];
	int t;
	scanf("%d", &t);
	while(t--){
		int min_score = INF; // Sum of distance*n_people
		memset(grid, 0x00, sizeof(grid));
		// Input for test case
		int n, x, y, val;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d %d %d", &x, &y, &val);
			grid[y][x] = val;
		}

		// Generating all solutions
		for(int sol1=0; sol1<21; sol1++){
			for(int sol2=sol1+1; sol2<22; sol2++){
				for(int sol3=sol2+1; sol3<23; sol3++){
					for(int sol4=sol3+1; sol4<24; sol4++){
						for(int sol5=sol4+1; sol5<25; sol5++){
							// Computing manhattan distance
							int sum_of_scores = 0;
							for(int y=0; y<5; y++){
								for(int x=0; x<5; x++){
									sum_of_scores += grid[y][x]*min(
										manhattan_distance(sol1, y, x), min(
										manhattan_distance(sol2, y, x), min(
										manhattan_distance(sol3, y, x), min(
										manhattan_distance(sol4, y, x),
										manhattan_distance(sol5, y, x) 
									))));
								}
							}
							// Minimize score
							if(min_score > sum_of_scores){
								min_score = sum_of_scores;
								solutions[0] = sol1;
								solutions[1] = sol2;
								solutions[2] = sol3;
								solutions[3] = sol4;
								solutions[4] = sol5;
							}
						}
					}
				}
			}
		}

		printf("%d %d %d %d %d\n",
			solutions[0],
			solutions[1], 
			solutions[2],
			solutions[3], 
			solutions[4]
		);
	}
	return 0;
}