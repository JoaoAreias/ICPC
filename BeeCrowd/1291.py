from math import pi
import sys


for line in sys.stdin:
    l2 = float(line)**2
    area_folha = l2 * (pi / 2 - 1)

    area_quadrado = 4 * l2 * (1 - pi / 6 - (3**0.5) / 4)
    area_listra = area_quadrado + 2 * area_folha - l2
    area_pontos = 2 * area_folha - 2 * area_listra


    print(f"{area_listra:.3f} {area_pontos:.3f} {area_quadrado:.3f}") 