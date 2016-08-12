//https://www.hackerrank.com/contests/projecteuler/challenges/euler007
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


bool isPrime(long long n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<long long> calcPrime() {
    vector<long long> primes;
    primes.push_back(2);
    primes.push_back(3);
    long long n = 5;
    while (primes.size() <= 10000) {
        if (isPrime(n))
            primes.push_back(n);
        n++;
    }
    return primes;
}

int main() {
    int T = 0;
    cin >> T;
    vector<long long> primes = calcPrime();
    while (T--) {
        int n;
        cin >> n;
        cout << primes[n - 1] << endl;
    }
    
    
    
    return 0;
}


