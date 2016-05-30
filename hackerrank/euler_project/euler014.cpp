//Draft: euler014
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

int mem[5000001] = {0};

int findTerms(int n)
{
  int count = 1;
  while (n > 1)
  {
    n = n % 2 == 0 ? n >> 1 : 3 * n + 1;
    count++;
  }
  return count;
}

int findMaxTerms(int n)
{
  int max_terms = 0;
  int ret = 1;
  for (int i = 2; i <= n; i++)
  {
    int terms;
    if (mem[i] == 0)
      terms = mem[i] = findTerms(i);
    else
      terms = mem[i];
    if (terms >= max_terms)
    {
      max_terms = terms;
      ret = i;
    }
  }
  return ret;
}

int main() {
  int T;
  cin >> T;
  vector<string> numbers;
  while (T--)
  {
    int a;
    cin >> a;
    cout << findMaxTerms(a) << endl;
  }

}
