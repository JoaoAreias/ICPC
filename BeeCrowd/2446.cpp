#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int V, M;
    std::vector<int> coins;
    std::vector<std::vector<bool>> dp;

    /*
    Otimiza cin e cout para problemas de maratona
    */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    /*
    Input:
        A primeira linha da entrada contém dois números inteiros V (1 ≤ V ≤ 10^5) e 
    M (1 ≤ M ≤ 10^3), indicando, respectivamente, o valor final da compra e o 
    número de moedas que você tem em seu bolso. 
        A segunda linha contém M números inteiros que descrevem o valor 
    Mi (1 ≤ Mi ≤ 10^5)de cada moeda existente em seu bolso.
    */
    std::cin >> V >> M;
    coins.resize(M);
    for (int i = 0; i < M; i++){
        std::cin >> coins[i];
    }

    // Inicializa tabela de memorização
    dp.resize(M + 1);
    for (auto&& v: dp){
        v.resize(V + 1);
    }
    std::fill(dp[0].begin(), dp[0].end(), false);
    dp[0][0] = true;

    // Programação dinâmica
    for (int i = 1; i <= M; i++) {
        dp[i][0] = true;

        for (int j = 1; j <= V; j++) {
            dp[i][j] = dp[i - 1][j];

            if (coins[i - 1] > j)
                continue;
            
            dp[i][j] = dp[i][j] || dp[i - 1][j - coins[i-1]];
        }
    }

    // Resposta
    std::cout << (dp[M][V] ? "S" : "N") << std::endl;

    return 0;
}