/* Programação dinâmica:
    https://codeforces.com/group/YgJmumGtHD/contest/103794/problem/C
*/
#include <iostream>
#include <vector>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int N;
    std::vector<long long int> K;

    /*Input:
        A primeira linha da entrada contem um inteiro N, a quantidade de dias que durará a turnê. 
    Cada uma das próximas N linhas seguintes contém um inteiro K[i], representando o valor do 
    cachê de Pedro no dia i.
    */
   while (std::cin >> N){
        K.resize(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> K[i];
        }

        /*Output:
            A saída deve conter um único inteiro X, o valor máximo do cachê que Pedro pode receber na turnê.
        */
        if (N == 1)
            std::cout << K[0] << std::endl;
        else {
            std::vector<long long int> dp(N);
            dp[0] = K[0];
            dp[1] = MAX(K[0], K[1]);
            for (int i = 2; i < N; ++i) {
                dp[i] = MAX(dp[i - 1], dp[i - 2] + K[i]);
            }
            std::cout << dp[N - 1] << std::endl;
        }
   }        
    return 0;
}