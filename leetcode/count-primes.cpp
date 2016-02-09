//Solution to https://leetcode.com/problems/count-primes/
class Solution {
  bool *primes;
  public:

  int countPrimes(int n) {
    primes = new bool[n + 1];
    primes[0] = primes[1] = false;
    for (int i = 2; i < n; i++) {
      primes[i] = true;
    }

    for (int i = 2; i <= sqrt(n); i++) {
      if (primes[i]) {
        for (int j = i + i; j < n; j+=i) {
          primes[j] = false;
        }
      }
    }
    int count = 0;
    if (n > 2) {
      count++;
    }
    for (int i = 3; i < n; i+=2) {
      if (primes[i])
        count ++;
    }
    return count;
  }
};
