//https://www.hackerrank.com/contests/projecteuler/challenges/euler023
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> isSumAbundant;

bool IsAbundant(int n)
{
  int sum = 1;
  int sq = sqrt(n);
  for (int i = 2; i <= sq; i++)
  {
    if (n % i == 0)
    {
      sum += i;
      if ( n / i != i)
      {
        sum += n / i;
      }
    }
  }
  return sum > n;
}

void GenerateAbundantNumbers()
{
  vector<int> abundatNumbers;
  for (int i = 4; i <= 50000; i++)
  {
    if (IsAbundant(i))
    {
      abundatNumbers.push_back(i);
      for (int j = 0; j < abundatNumbers.size(); j++)
        isSumAbundant[i + abundatNumbers[j]] = true;
    }
  }
}

string CheckAbundantSum(int n)
{
  if (isSumAbundant.count(n) && isSumAbundant[n])
    return "YES";
  return "NO";
}

int main(){
  int N, T;
  cin >> T;
  GenerateAbundantNumbers();
  while (T--)
  {
    cin >> N;
    cout << CheckAbundantSum(N) << endl;
  }
  return 0;
}


