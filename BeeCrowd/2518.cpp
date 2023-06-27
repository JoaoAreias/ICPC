#include <iostream>
#include <iomanip>
#include <cmath>

double hypotenuse(double c1, double c2){
    return sqrt(pow(c1, 2) + pow(c2, 2));
}

int main(){
    double N, L, H, C;

    // Otimiza a entrada e saída de dados
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << std::fixed << std::setprecision(4);

    while (std::cin >> N >> H >> C >> L){
        double area = N * L * hypotenuse(H, C) / 1e4;
        std::cout << area << std::endl;
    }
    

    return 0;
}