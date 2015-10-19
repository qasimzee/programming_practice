#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


bool isPalindrome(string str, int i)
{
  str.erase(str.begin() + i);
  if (str.size() == 1) return true;
  for (int i = 0; i < str.size() / 2; i++)
  {
    int j = str.size() - i - 1;
    if (str[i] != str[j])
    {
      return false;
    }
  }
  return true;
}

int indexPalindrom(string str)
{
  int N = str.size();
  if (N == 1)
    return -1;
  for (int i = 0; i < N / 2; i++)
  {
    int j = N - i - 1;
    if (str[i] != str[j])
    {
      if (str[i] == str[j - 1])
      {
        if (isPalindrome(str, j))
          return j;
      }

      if (str[i + 1] == str[j])
      {
        if (isPalindrome(str, i))
          return i;
      }

    }
  }
  return -1;
}

int main() {
  int T;
  cin >> T;
  while (T--)
  {
    string str;
    cin >> str;
    cout << indexPalindrom(str) << endl;
  }
  return 0;
}


