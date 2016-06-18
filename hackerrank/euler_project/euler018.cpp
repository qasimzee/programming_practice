//https://www.hackerrank.com/contests/projecteuler/challenges/euler018
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

int arr[15][15] = {0};

int greatestSum()
{
  for (int i = 1; i < 15; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (arr[i][j] == -1)
      {
        break;
      }
      arr[i][j] = max(arr[i - 1][j] + arr[i][j], arr[i - 1][j - 1] + arr[i][j]);
    }
  }
  int sum = 0;
  for (int i = 0; i < 15; i++)
  {
    for (int j = 0; j < 15; j++)
    {
      if (arr[i][j] > sum)
        sum = arr[i][j];
    }
  }
  return sum;
}

void resetArray()
{
  for (int i = 0; i < 15; i++)
  {
    for (int j = 0; j < 15; j++)
    {
      arr[i][j] = -1;
    }
  }
}

int main() {
  int T;
  cin >> T;
  while (T--)
  {
    int N;
    cin >> N;
    resetArray();
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j <= i; j++)
      {
        cin >> arr[i][j];
      }
    }
    cout << greatestSum();

  }

}
