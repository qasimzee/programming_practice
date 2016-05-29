//https://www.hackerrank.com/contests/projecteuler/challenges/euler013
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

void findSum(vector<string> numbers)
{
  int op[51] = {0};
  for (int i = 0; i < numbers[0].size(); i++)
  {
    int sum = 0;
    for (int j = 0; j < numbers.size(); j++)
    {
      sum += numbers[j][i] - '0';
    }
    op[49 - i] = sum;
  }
  int i;
  for (i = 0; i < 50; i++)
  {
    int n = op[i];
    op[i] = n % 10;
    op[i + 1] += n / 10;
  }
  int digits = 0;
  if (op[50] > 1)
    digits = 1;
  if (op[50] > 10)
    digits = 2;
  if (op[50] > 100)
    digits = 3;
  for (i = 50; i > 39 + digits; i--)
    cout << op[i];
}

int main() {
  int T;
  cin >> T;
  vector<string> numbers;
  while (T--)
  {
    string str;
    cin >> str;
    numbers.push_back(str);
  }
  findSum(numbers);
}
