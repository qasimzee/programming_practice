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

int findTerms(int n)
{
  int count = 1;
  while (n > 1)
  {
    if (n % 2 == 0)
      n = n / 2;
    else
      n = 3 * n + 1;
    count++;
  }
  return count;
}

int findMaxTerms(int n)
{
  int max_terms = 0;
  for (int i = 2; i <= n; i++)
  {
    int terms = findTerms(i);
    cout <<"Terms: "<< terms << endl;
    if (terms > max_terms)
      max_terms = terms;
  }
  return max_terms;
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
