//https://www.hackerrank.com/contests/projecteuler/challenges/euler001
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long findSum(int n) {
  long long k1 = (n - 1) / 3;
  long long k2 = (n - 1) / 5;
  long long k3 = (n - 1) / 15;
  return 3 * (k1 * (k1 + 1) / 2) + 5 * (k2 * (k2 + 1) / 2) - 15 * (k3 * (k3 + 1) / 2);
}

int main() {
  int N, T;

  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> N;
    cout << findSum(N) << endl;
  }
  return 0;
}
