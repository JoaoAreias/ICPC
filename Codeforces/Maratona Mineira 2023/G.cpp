#include <bits/stdc++.h>

void swap(std::vector<bool> &pos, int i, int j){
    bool aux = pos[i];
    pos[i] = pos[j];
    pos[j] = aux;
}


int main() {
    int N, a, b;
    std::vector<bool> pos = {false, true, false};
    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> a >> b;
        swap(pos, a-1, b-1);
    }

    for(int i = 0; i < 3; i++){
        if(pos[i]){
            std::cout << i+1 << std::endl;
            break;
        }
    }
    return 0;
}