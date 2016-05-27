//https://www.hackerrank.com/contests/projecteuler/challenges/euler012
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
#include <fstream>
#include <unordered_map>

using namespace std;

vector<int> primes;

bool isPrime(int n)
{
  if (n == 2 || n == 3)
    return true;
  int sq_rt = sqrt(n);
  for (int i = 2; i <= sq_rt; i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

void calculatePrimes()
{
  primes.push_back(2);
  for (int i = 3; i < 1000000; i+=2)
  {
    if (isPrime(i))
    {
      primes.push_back(i);
    }
  }
}

int countFactors(int n)
{
  int r = n;
  int factors = 1;
  for (int i = 0; i < primes.size(); i++)
  {
    int exp = 1;
    while (r % primes[i] == 0)
    {
      r /= primes[i];
      exp++;
    }
    factors *= exp;
    if (r == 1)
      return factors;
  }
  return factors;
}

int findDivisors(int n)
{
  int sum = 0;

  for (int i = 1; i < 1000000; i++)
  {
    sum += i;
    int divisors = countFactors(sum);
    if (divisors > n)
      return sum;
  }
  return -1;
}

int main() {
  int T;
  cin >> T;

  calculatePrimes();

  while (T--)
  {
    int n;
    cin >> n;
    cout << findDivisors(n) << endl;
  }
}
