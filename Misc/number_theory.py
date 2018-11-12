import math

class NoSolution(Exception):
    """Excecao para caso nenhum resultado tenha
    sido encontrado"""
    pass

def factor(x):
	""" Returns a dictionary
	with the number's prime factors"""
	sqrt = x**(1/2)
	i = 2
	factors = {}
	while i <= sqrt:
		if x % i == 0:
			x /= i
			factors[i] = factors[i] + 1 if i in factors else 1
			sqrt = x**(1/2)
			i -= 1
		i += 1
	if x != 1:
		x = int(x)
		factors[x] = factors[x] + 1 if x in factors else 1
	return factors

def gcd(x, y):
	""" Euclidean algorithm for
	finding the greatest common divisor"""
	return y if x%y ==0 else gcd(y, x%y)

def lcm(x, y):
	return x*y // gcd(x, y)

def mod_exp(a, b, mod):
	""" Returns a^b mod (mod)"""
	if b == 1:
		return a%mod
	elif b == 0:
		return 1

	k = a
	a = (mod_exp(a, b//2, mod)**2)
	if b%2 == 1:
		a = (a*k)
	return a%mod

def solve(a, b, c):
    """Retorna os inteiros x e y tal que
    a*x + b*y = c
    Fonte: https://www.math.utah.edu/~carlson/hsp2004/PythonShortCourse.pdf"""
    q, r = divmod(a, b)
    if r == 0:
        if c%b != 0:
            raise NoSolution(u"A equação diophantina não possui solução")
        return [0, c//b]
    else:
        sol = solve(b, r, c)
        u = sol[0]
        v = sol[1]
        return([v, u - q*v])

def mul_inverso(p, m):
    """Calcula p^{-1} mod m"""
    try:
        return solve(p, m, 1)[0] % m
    except NoSolution:
        raise NoSolution(u"%d não possui multiplicativo inverso modulo %d" % (p, m))

if __name__ == '__main__':
	print(factor(60))
