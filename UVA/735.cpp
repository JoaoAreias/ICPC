#include <bits/stdc++.h>
#define size 43

using namespace std;

int main(){
	const int points[size] = {
		 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
		10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
		20, 21, 22, 24, 26, 27, 28, 30, 32, 33,
		34, 36, 38, 39, 40, 42, 45, 48, 50, 51,
		54, 57, 60
	};
	bool visited[size][size][size];

	int score;
	while(scanf("%d", &score) && (score > 0)){
		int perm=0, comb=0;
		memset(visited, false, sizeof(visited));

		for(int p1=0; p1 < size; p1++){
			for(int p2=p1; p2<size; p2++){
				for(int p3=p2; p3<size; p3++){
					if(points[p1] + points[p2] + points[p3] == score){
						comb++;
						if(points[p1] == points[p2] && points[p1] == points[p3])
							perm++;
						else if(points[p1] == points[p2] || points[p1] == points[p3] || points[p3] == points[p2])
							perm += 3;
						else
							perm += 6;
					}
				}
			}
		}

		if(comb == 0){
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
		}else{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", score, comb);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, perm);
		}
		printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");
}