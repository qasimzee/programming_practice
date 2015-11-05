#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

int getPalindrome(string str) {
  int op = 0;
  for (int i = 0 ; i < str.size() / 2; i++) {
    int j = str.size() - i - 1;
    if (str[i] != str[j]) {
      op += abs(str[i] - str[j]);
    }
  }
  return op;
}

int main() {
  int N;
  cin >> N;
  while (N--) {
    string str;
    cin >> str;
    cout << getPalindrome(str) << endl;
  }
  return 0;
}



