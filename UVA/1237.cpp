#include <bits/stdc++.h>

using namespace std;
typedef tuple<string, int, int> data;
vector<data> data_base;

string querry(int P){
	string result = "";
	for(data d: data_base){
		if((P >= get<1>(d)) && (P <= get<2>(d))){
			if(result != "")
				return "UNDETERMINED";
			result = get<0>(d);
		}
	}
	return (result == "" ? "UNDETERMINED" : result);
}


int main(){
	ios_base::sync_with_stdio(false);
	bool first = true;

	int T;
	cin >> T;
	while(T--){
		if(!first)
			cout << endl;
		string name;
		int Q, D, L, H;
		cin >> D;
		data_base.resize(D);
		for(int i=0; i<D; i++){
			cin >> name >> L >> H;
			data_base[i] = make_tuple(name, L, H);
		}

		cin >> Q;
		while(Q--){
			cin >> D;
			cout << querry(D) << endl;
		}
		first = false;
	}
	return 0;
}