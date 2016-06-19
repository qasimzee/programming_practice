//https://www.hackerrank.com/contests/projecteuler/challenges/euler021
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

int sumDivisors[100001] = {0};

unordered_map<int, int> mapCount;

int FindSumOfDivisors(int n)
{
  if (n == 1)
    return 0;
  int sqrtN = sqrt(n);
  int sum = 0;
  for (int i = 2; i <= sqrtN; i++)
  {
    if (n % i == 0)
    {
      if (i != n / i)
      {
        sum += i;
        sum += n/i;
      }
      else
        sum += i;
    }
  }
  return sum + 1;
}

void FillSumDivisors()
{
  for (int i = 1; i < 100001; i++)
  {
    int sumOfDivisors = FindSumOfDivisors(i);
    sumDivisors[i] = sumOfDivisors;
    if (!mapCount.count(sumOfDivisors))
      mapCount[sumOfDivisors] = 1;
    else
      mapCount[sumOfDivisors] = mapCount[sumOfDivisors] + 1;
  }
}

int FindAmicableNumbers(int n)
{
  int amicable = 0;
  for (int i = 1; i < n; i++)
  {
    int s = sumDivisors[i];
    if (s < 100001 && sumDivisors[s] == i && i != s)
      amicable += i;
  }
  return amicable;
}


int main() {
  FillSumDivisors();

  int T;
  cin >> T;

  while (T--)
  {
    int N;
    cin >> N;
    cout << FindAmicableNumbers(N) << endl;
  }

}
