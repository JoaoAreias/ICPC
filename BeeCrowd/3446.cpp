#include <iostream>
#include <algorithm>
#include <vector>

typedef std::vector<std::vector<std::vector<int>>> memo_t;

int main() {
    int n, k, e;
    std::cin >> n >> k >> e;
    int esquerda = e;        // Espaços vazios na esquerda
    int direita = n - k - e; // Espaços vazios na direita

    memo_t memo(n, std::vector<std::vector<int>>(esquerda + 1, std::vector<int>(direita + 1, n - k)));
    
    // Para cada peça do tabuleiro
    int idx = 0;
    for(int peca=1; peca <= n; peca++){
        // Pula a peça que já foi colocada
        if (peca == k)
            continue;

        idx++;
        for(int j=0; j <= esquerda; j++) {
            for(int l=0; l <= direita; l++){
                memo[idx][j][l] = memo[idx-1][j][l];
                
                if(j >= peca)
                    memo[idx][j][l] = std::min(memo[idx][j][l], memo[idx-1][j-peca][l] - peca);

                if(l >= peca)
                    memo[idx][j][l] = std::min(memo[idx][j][l], memo[idx-1][j][l-peca] - peca);
                
            }
        }
    }

    std::cout << memo[n-1][esquerda][direita] << std::endl;

    return 0;
}