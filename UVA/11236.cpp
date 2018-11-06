#include <bits/stdc++.h>

using namespace std;

int main(){
	set<int> s;

	for(int a= 1; a <= 1997; a++){
		for(int b=a; b <= 1998-a; b++){
			for(int c=b; c <= 1999-a-b; c++){
				// Division by 0
				if(a == 1 && b == 1 && c == 1)
					continue;
				int d = 1000000*(a+b+c) / (a*b*c - 1000000);
				int sum = a+b+c+d;
				if(d >= 1  && sum < 20000 && s.find(sum) == s.end()){
					s.insert(sum);
					printf("%.2lf %.2lf %.2lf %.2lf\n", (double)(a)/100, (double)(b)/100, (double)(c)/100, (double)(d)/100);
				}  
			}
		}
	}

	return 0;
}