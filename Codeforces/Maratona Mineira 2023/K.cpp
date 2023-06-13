#include <iostream>
#include <vector>
#include <cmath>

#define MAX_INT 2147483647

struct Point{
    int x;
    int y;
    int z;
    Point(int x, int y, int z) : x(x), y(y), z(z) {}
};

inline int distance(const Point& p1, const Point& p2){
    return abs(p1.x - p2.x) + abs(p1.y - p2.y) + abs(p1.z - p2.z);
}

int main() {
    int N, R, G, B;
    std::vector<Point> points;

    // Otimiza a entrada e saída de dados
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;
    points.reserve(N);
    while(N--){
        std::cin >> R >> G >> B;
        points.emplace_back(R, G, B);
    }

    // Solução por força bruta
    int max = -1;
    int r, g, b;
    for(int i=0; i < 256; i++){
        for(int j=0; j < 256; j++){
            for(int k=0; k < 256; k++){
                Point p(i, j, k);
                int min = MAX_INT;
                for(const Point& point : points){
                    int dist = distance(p, point);
                    if(dist < min){
                        min = dist;
                    }
                }
                if(min > max){
                    max = min;
                    r = i; g = j; b = k;
                }
            }
        }
    }

    std::cout << r << " " << g << " " << b << std::endl;
       

    return 0;
}