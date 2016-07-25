//https://www.hackerrank.com/contests/projecteuler/challenges/euler017
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

string GetString(long long n)
{
  if (n == 0)
    return "Zero";
  string parts[5] = {"", "Thousand ", "Million ", "Billion ", "Trillion "};
  string numbers[] = {"One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ",
    "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
  string tens[] = {"Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};

  vector<string> v;

  while (n > 0)
  {
    string ans = "";
    int x = n % 1000;
    if (x >= 100)
    {
      ans += numbers[x / 100 - 1] + "Hundred ";
    }
    x = x % 100;
    if (x > 0)
    {
      if (x <= 19)
      {
        ans += numbers[x - 1];
      }
      else
      {
        ans += tens[x / 10 - 2];
        if (x % 10 - 1 >= 0)
          ans += numbers[x % 10 - 1];
      }
    }

    v.push_back(ans);
    n /= 1000;

  }
  string ret = "";
  for (int i = v.size() - 1; i >= 0; i--)
  {
    if (v[i].size() > 0)
      ret += v[i] + parts[i];
  }
  ret.erase(ret.end() - 1);
  return ret;
}

int main(){
  long long N, T;
  cin >> T;
  while (T--)
  {
    cin >> N;
    cout << GetString(N) << endl;
  }

  return 0;
}



