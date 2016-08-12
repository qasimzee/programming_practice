//https://www.hackerrank.com/contests/projecteuler/challenges/euler008
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int getProduct(string str, int k) {
    int prod = 1;
    for (int i = 0; i < k; i++) {
        prod *= str[i] - '0';
    }

    for (int i = k; i < str.size(); i++) {
        int current_prod = 1;
        for (int j = i - k; j < i; j++) {
            current_prod *= str[j] - '0';
        }
        if (current_prod > prod)
            prod = current_prod;
    }
    return prod;
}

int main() {
    int T = 0;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        cout << getProduct(str, k) << endl;
    }
    return 0;
}


