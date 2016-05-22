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

long long sum_prime[1000001] = {0};

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
  long long sum = 0;
  for (int i = 2; i < 1000001; i++)
  {
    if (isPrime(i))
    {
      sum += i;
      sum_prime[i] = sum;
    }
    else {
      sum_prime[i] = sum_prime[i - 1];
    }
  }
}



int main() {
  int T;
  cin >> T;
  calculatePrimes();
  while (T--)
  {
    int n;
    cin >> n;

    cout << sum_prime[n] << endl;
  }
}
