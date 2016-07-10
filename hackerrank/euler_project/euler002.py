#!/usr/bin/python

fibs = [1, 2]
current = 0
i = 0
while (current <= 4 * pow(10, 16)):
  current = fibs[i - 1] + fibs[i - 2]
  fibs.append(current)

  T = int(input())
  i = 0
  while (i < T):
    N = int(input())
    sum = 0;
    for num in fibs:
      if (num % 2 == 0 and num < N):
          sum += num;
          i = i + 1
      print sum
