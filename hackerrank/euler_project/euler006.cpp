//https://www.hackerrank.com/contests/projecteuler/challenges/euler006
#include <cmath>
#include <cstdio>
#include <stack>
#include <queue>
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
        int N;
        cin >> N;
        long long square_sum = (N * (N + 1) / 2);
        square_sum *= square_sum;
        long long sum_of_squares = 0;
        for (int i = 1; i <= N; i++)
        {
            sum_of_squares += pow(i, 2);
        }
        cout << (square_sum - sum_of_squares) << endl;
    }
    return 0;
}


