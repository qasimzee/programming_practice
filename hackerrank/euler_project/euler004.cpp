//https://www.hackerrank.com/contests/projecteuler/challenges/euler004
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int is_palindrome(int num)
{
    vector<int> digits;
    while(num != 0)
    {
        digits.push_back(num % 10);
        num/=10;
    }
    for (int i = 0; i < digits.size(); i++)
    {
        if (digits[i] != digits[digits.size() - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    vector<int> pals;
    for (int i = 100; i <= 999; i++)
    {
        for (int j = i; j <= 999; j++)
        {
            int prod = i * j;
            if (is_palindrome(prod))
            {
                pals.push_back(prod);
            }
        }
    }
    while(T--)
    {
        int num;
        cin >> num;
        int max_palindrome = 0;
        for (int i = 0; i < pals.size(); i++)
        {
            if (pals[i] > max_palindrome && pals[i] < num)
            {
                max_palindrome = pals[i];
            }
        }
        cout << max_palindrome << endl;
    }
    return 0;
}


