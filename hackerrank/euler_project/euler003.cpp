#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool is_prime(long long n)
{
    for (int i = 2; i <= ceil(sqrt(n)); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}


int main() {

    vector<long long> primes;
    primes.push_back(2);
    for (int i = 3; i <= ceil(sqrt(1000000000000)); i+=2)
    {
        if (is_prime(i))
        {
            primes.push_back(i);
        }
    }
    int T;
    cin >> T;
    while(T--)
    {
        long long N;
        cin >> N;
        long long prime = 0;
        for (int i = 0; i < primes.size(); i++)
        {
            while (N % primes[i] == 0)
            {
                N /= primes[i];
                if (primes[i] > prime)
                {
                    prime = primes[i];
                }
            }
            
        }
        if (N > 1 && N > prime) prime = N;
        cout << (prime == 0 ? N : prime) << endl;
    }
    
    return 0;
}


