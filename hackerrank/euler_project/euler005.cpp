//https://www.hackerrank.com/contests/projecteuler/challenges/euler005
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    int T;
    cin >> T;
    
    while(T--)
    {
        int num;
        cin >> num;
        vector<int> factors;
        vector<int> nums;
        factors.push_back(1);
        for (int i = 2; i <= num; i++)
        {
            nums.push_back(i);
        }

        for (int i = 2; i <= num; i++)
        {
            bool multiple_found = false;
            do
            {
                multiple_found = false;
                for (int j = 0; j < nums.size(); j++)
                {
                    if (nums[j] % i == 0)
                    {
                        nums[j] /= i;
                        multiple_found = true;
                    }
                }
                if (multiple_found)
                    factors.push_back(i);
            }while(multiple_found);
        }
        long long prod = 1;
        for (int i = 0; i < factors.size(); i++)
        {
            prod *= factors[i];
        }
        cout << prod << endl;
    }
    return 0;
}


