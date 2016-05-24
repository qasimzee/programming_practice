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

int input[20][20] = {0};


long long maxSum()
{
  long long max_prod = 1;
  int inc1[] = {0, 1, 2, 3};
  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 20; j++)
    {
      long long prod[] = {1,1,1,1,1,1};

      for (int c = 0; c < 4; c++)
      {
        if (j + inc1[c] < 20)
          prod[0] *= input[i][j + inc1[c]];
        if (i + inc1[c] < 20)
          prod[1] *= input[i + inc1[c]][j];
        if (i + inc1[c] < 20 && j + inc1[c] < 20)
          prod[2] *= input[i + inc1[c]][j + inc1[c]];
        if (i + inc1[c] < 20 && j - inc1[c] >= 0)
          prod[3] *= input[i + inc1[c]][j - inc1[c]];
        if (i - inc1[c] >= 0)
          prod[4] *= input[i - inc1[c]][j];
        if (j - inc1[c] >= 0)
          prod[5] *= input[i][j - inc1[c]];
      }
      for (int c = 0; c < 6; c++)
      {
        max_prod = max_prod > prod[c] ? max_prod : prod[c];
      }
    }
  }
  return max_prod;
}

int main() {
  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 20; j++)
    {
      cin >> input[i][j];
    }
  }
  cout << maxSum();
}
