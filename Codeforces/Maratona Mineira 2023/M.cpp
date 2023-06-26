#include <cstdio>

int main () {
    const double C = 1.123501108793;
    double r;

    scanf("%lf", &r);
    printf("%.10lf\n", C * r * r);
}