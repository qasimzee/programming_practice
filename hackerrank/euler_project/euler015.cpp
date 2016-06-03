//DRAFT: https://www.hackerrank.com/contests/projecteuler/challenges/euler015
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
#include <fstream>
#include <unordered_map>

using namespace std;

long long factorial(int n)
{
  long long x = 1;
  for (int i = 1; i <= n; i++)
  {
    x *= i;
    x = x % (1000000000 + 7);
  }
  return x;
}

long long computePaths(int a, int b){
  return factorial(a + b) / (factorial(a) * factorial(b));
}





int main() {
  int T;
  cin >> T;
  while (T--)
  {
    int a,b;
    cin >> a >> b;
    cout << computePaths(a, b) << endl;
  }

}
