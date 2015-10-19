//Solution to Hackerrank https://www.hackerrank.com/challenges/two-strings
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

string twoStrings(string str1, string str2)
{
  int map[26] = {0};
  for (int i = 0; i <str1.size(); i++)
  {
    map[str1[i] - 'a']++;
  }
  for (int i = 0; i <str2.size(); i++)
  {
    if (map[str2[i] - 'a']) return "YES";
  }
  return "NO";
}

int main() {

  int T;
  cin >> T;
  while(T--)
  {
    string str1, str2;
    cin >> str1 >> str2;
    cout << twoStrings(str1, str2) << endl;
  }



  return 0;
}



