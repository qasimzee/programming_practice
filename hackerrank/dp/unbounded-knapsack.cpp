//Solution to https://www.hackerrank.com/challenges/unbounded-knapsack
#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int maxVal(vector<int> v, int k) {
  int dp[2005] = {0};
  sort(v.begin(), v.end());
  for (int g = 1; g <= k; g++) {
    for (int i = 0; i < v.size(); i++) {
      if (v[i] <= g) {
        dp[g] = max(dp[g], v[i] + dp[g - v[i]]);
      }
    }
  }
  return dp[k];
}

int main()
{
  int n, k, T;
  cin >> T;

  while (T--) {
    cin >> n >> k;
    vector<int> v;
    while (n--) {
      int a;
      cin >> a;
      v.push_back(a);
    }
    cout << maxVal(v, k) << endl;
  }
  return 0;
}
