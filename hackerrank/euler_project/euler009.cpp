//https://www.hackerrank.com/contests/projecteuler/challenges/euler009

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
struct triplet {
  int a, b, c;
};

vector<triplet> mp;

int getTripletProd(int N) {
  int ans = -1;
  for (int i = 0; i < mp.size(); i++) {
    if (mp[i].a * mp[i].b * mp[i].c > ans && mp[i].a + mp[i].b + mp[i].c == N)
      ans = mp[i].a * mp[i].b * mp[i].c;
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  triplet t;
  for (int a = 1; a <= 3000; a++) {
    for (int b = 1; b < a; b++) {
      int sum = a * a + b * b;
      double c = sqrt(sum);
      if (c == floor(c) && a != b && b != c) {
        t.a = a;
        t.b = b;
        t.c = c;
        mp.push_back(t);
      }
    }
  }
  while (T--) {
    int N;
    cin >> N;
    cout << getTripletProd(N) << endl;
  }
  return 0;
}


