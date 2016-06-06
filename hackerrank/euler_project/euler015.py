#Lattice paths: https://www.hackerrank.com/contests/projecteuler/challenges/euler015

def factorial(n):
	x = 1;
	for i in range(1, n + 1):
		x *= i
	return x


def computePaths(a, b):
	return (factorial(a + b) / (factorial(a) * factorial(b))) % (1000000000 + 7);


T = int(raw_input())
while (T > 0):
	str = raw_input().split(' ') 
	a = int(str[0])
	b = int(str[1])
	print computePaths(a, b)
	T = T - 1
	
