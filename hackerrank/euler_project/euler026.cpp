//https://www.hackerrank.com/contests/projecteuler/challenges/euler026
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

int getCycles(int n)
{
  int a[100000] = {0};
  int q = 10;
  int count = 0;
  int mod = (q % n);
  while (a[mod] == 0)
  {
    count++;
    if (a[mod] == 0)
      a[mod] = count;
    q = mod * 10;
    mod = (q % n);
    if (mod == 0)
      return -1;
  }

  return count - a[mod] + 1;
}

map<int, int> GetAllCycles()
{
  map<int, int> rec_cycles;
  int max_cycle = 0;
  int max_value = 0;
  for (int i = 3; i <= 10000; i++)
  {
    int cycles = getCycles(i);
    if (cycles > max_cycle)
    {
      max_cycle = cycles;
      max_value = i;
    }
    rec_cycles[i + 1] = max_value;

  }
  return rec_cycles;
}

int main(){
  int N, T;
  cin >> T;
  map<int, int> cycles = GetAllCycles();
  while (T--)
  {
    cin >> N;
    cout << cycles[N] << endl;
  }
  return 0;
}




