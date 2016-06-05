#!/usr/bin/python

def sumPower(n):
	power = pow(2, n)
	ans = 0
	while (power > 0):
		ans += power % 10
		power /= 10
	return ans
	

T = int(raw_input())
while (T > 0):
	N = int(raw_input())
	print sumPower(N)
	T = T - 1
	