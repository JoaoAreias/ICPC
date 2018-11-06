#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	vector<vector<int>> field;
	
	int M;

	while(cin >> M){
		string str;
		field.resize(M);

		cin.ignore();
		for(int i=0; i<M; i++){
			getline(cin, str);
			for(int j=0; j<M; j++){
				field[i].push_back(str[j] - '0');
			}
		}

		int min_d, max_d=0;
		for(int i=0; i<M; i++){
			for(int j=0; j<M; j++){
				if(field[i][j] == 1){
					min_d = 2*M;
					for(int a=0; a<M; a++){
						for(int b=0; b<M; b++){
							if(field[a][b] == 3)
								min_d = min(abs(a-i) + abs(b-j), min_d);
						}
					} 
				}
				if(min_d > max_d)
					max_d = min_d;
			}
		}

		field.clear();
		cout << max_d << endl;
	}
}