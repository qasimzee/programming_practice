//Solution to https://www.hackerrank.com/challenges/bigger-is-greater
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

int main() {

  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    string w;
    cin >> w;
    if (next_permutation(w.begin(), w.end()))
    {
      cout << w << endl;
    }
    else
      cout << "no answer" << endl;
  }
  return 0;
}




