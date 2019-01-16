import math

class NoSolution(Exception):
    """Excecao para caso nenhum resultado tenha
    sido encontrado"""
    pass

def gcd(x, y):
	""" Euclidean algorithm for
	finding the greatest common divisor"""
	return y if x%y ==0 else gcd(y, x%y)


def lcm(x, y):
	return x*y // gcd(x, y)

def miller_rabin(n):
	# Value checks
	if not (type(n) is int):
		raise ValueError("input must be an integer") 
	if n < 2:
		return False
	if n == 2:
		return True


	# Step 1: Determine k and m such that n-1 = (2^k)m 
	k = round(math.log(gcd(n-1, 2**1024), 2))
	m = (n-1) // (2**k)
	while not (m%2):
		k += round(math.log(gcd(m, 2**1024), 2))
		m = (n-1) // (2**k)

	# Step 2: Choose a shuch that 1 < a < n-1
	a = 2

	# Step 3: Compute b0 = a^m mod n and b_{n} = b_{n-1}^2 mod n
	b = pow(a, m, n)
	if b == 1 or b == n-1:
		return True

	S = set([b])
	
	while True:
		b = pow(b, 2, n)
		if b == 1 or b in S:
			return False
		elif b == n-1:
			return True
		S.add(b)

def prime_factorization(x):
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

def find_factors(prime_factors, depth):
    """Uses the result of prime_factorization to
    recursivelly find all the factors of a number"""
    if depth == len(prime_factors):
        return [1]

    factors = []
    key = list(prime_factors.keys())[depth]
    for i in range(prime_factors[key] + 1):
        for j in find_factors(prime_factors, depth+1):
            factors.append(j*(key**i))

    return factors

def factor(n):
    """Returns a sorted list of all factors of n"""
    prime_factors = prime_factorization(n)
    factors = find_factors(prime_factors, 0)

    return sorted(factors)

if __name__ == '__main__':
	print(factor(60))
