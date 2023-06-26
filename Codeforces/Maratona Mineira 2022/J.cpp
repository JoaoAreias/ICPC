#include <iostream>
#include <vector>

typedef std::pair<double, double> Point;
typedef std::pair<double, double> Vector;

int oriantation(Point &p1, Point &p2, Point &p3) {
    Vector v1(p2.first - p1.first, p2.second - p1.second);
    Vector v2(p3.first - p2.first, p3.second - p2.second);
    double cross = v1.first * v2.second - v1.second * v2.first;

    if(cross > 0) {
        return 1;
    } else if(cross < 0) {
        return -1;
    } else {
        return 0;
    }
}


int main() {
    int n;
    double x, y;
    Point camera;
    std::vector<Point> polygon;

    // Otimiza a entrada e saída de dados
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Entrada de dados
    std::cin >> n;
    polygon.reserve(n);
    for(int i = 0; i < n; i++) {
        std::cin >> x >> y;
        polygon.emplace_back(x, y);
    }
    std::cin >> x >> y;
    camera = Point(x, y);

    bool darkCorner = false;
    int orientation = oriantation(polygon[n - 1], polygon[0], camera);
    for(int i = 0; i < n - 1; i++) {
        if(oriantation(polygon[i], polygon[i + 1], camera) != orientation) {
            darkCorner = true;
            break;
        }
    }
    std::cout << (!darkCorner ? "S" : "N") << std::endl;


    return 0;
}
