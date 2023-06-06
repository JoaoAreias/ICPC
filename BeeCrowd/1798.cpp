#include <iostream>
#include <algorithm>
#include <vector>


int main() {
    int N, T;
    std::vector<int> C;
    std::vector<int> V;
    std::vector<int> dp;

    while (std::cin >> N >> T) {
        C.resize(N);
        V.resize(N);
        dp.resize(T + 1);

        for (int i = 0;  i < N; i++) {
            std::cin >> C[i] >> V[i];
        }

        std::fill(dp.begin(), dp.end(), 0);
        for (int i = 1; i <= T; i++) {
            for (int j = 0; j < N; j++){
                if (C[j] > i) 
                    continue;
                
                dp[i] = std::max(dp[i], V[j] + dp[i - C[j]]);
            }
        }

        std::cout << dp[T] << std::endl;
    }

    return 0;
}