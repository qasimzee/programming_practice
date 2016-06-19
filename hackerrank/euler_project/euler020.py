#https://www.hackerrank.com/contests/projecteuler/challenges/euler020
def factorialDigitSum(N):
  factorial = 1;
  for x in range(1, N + 1):
    factorial *= x
  sum = 0
  while factorial > 0:
    sum  = sum + factorial % 10
    factorial /= 10
    return sum

T = int(raw_input())
for x in range(0, T):
    N = int(raw_input())
    print factorialDigitSum(N)


