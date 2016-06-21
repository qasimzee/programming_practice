//https://www.hackerrank.com/contests/projecteuler/challenges/euler022
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
#include <fstream>
#include <unordered_map>

using namespace std;


int getScore(string name, vector<string> names)
{
  int score = 0;
  for (int i = 0; i < name.size(); i++)
  {
    score += name[i] - 'A' + 1;
  }
  for (int i = 0; i < names.size(); i++)
  {
    if (name == names[i])
      return (i + 1) * score;
  }
  return 0;
}

int main() {
  int N, Q;
  string name;
  cin >> N;
  vector<string> names;
  while (N--)
  {
    cin >> name;
    names.push_back(name);
  }
  sort(names.begin(), names.end());
  cin >> Q;
  while (Q--)
  {
    string name;
    cin >> name;
    cout << getScore(name, names) << endl;
  }

}
