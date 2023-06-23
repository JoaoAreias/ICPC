#include <bits/stdc++.h>

int main(){
    std::vector<int> r(4);
    std::vector<int> votos(4, 0);
    
    for(int i = 0; i < 4; i++){
        std::cin >> r[i];
        if(i + r[i] < 4)
            votos[i + r[i]]++;
        
        if(i - r[i] >= 0)
            votos[i - r[i]]++;
    }

    for(int i = 0; i < 4; i++){
        if(votos[i] == 3){
            std::cout << i + 1 << std::endl;
            break;
        }
    }
    return 0;
}