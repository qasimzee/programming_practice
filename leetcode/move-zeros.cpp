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


class Solution {
  public:
    void moveZeroes(vector<int>& nums)
    {
      int count = 0;
      for (int i = 0; i < nums.size(); i++)
      {
        if (nums[i] == 0)
        {
          nums.erase(nums.begin() + i);
          i--;
          count ++;
        }
      }
      for (int i = 0; i < count; i++)
      {
        nums.push_back(0);
      }
    }
};
int main() {
  vector<int> v;
  v.push_back(0);
  v.push_back(0);
  v.push_back(1);

  Solution s;
  s.moveZeroes(v);
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  return 0;
}


