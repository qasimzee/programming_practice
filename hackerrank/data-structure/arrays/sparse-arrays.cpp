//Solution to https://www.hackerrank.com/challenges/sparse-arrays/submissions/code/16428616
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int N;
  unordered_map<string, int> map;
  cin >> N;
  while (N--) {
    string str;
    cin >> str;
    map[str]++;
  }
  int Q;
  cin >> Q;
  while (Q--) {
    string str;
    cin >> str;
    cout << map[str] << endl; 
  }
  return 0;
}


