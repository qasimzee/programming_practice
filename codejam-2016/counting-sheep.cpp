#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;



void CountringSheep(int n, int c)
{
    cout << "Case #"<<c<<": ";
    if (n == 0) {
        cout << "INSOMNIA" << endl;
        return;
    }
    int i_n = n;
    unordered_map<int, bool> map;

    while (map.size() < 10) {
        int x = n;
        while (x > 0) {
            map[x%10] = true;
            x /= 10;
        }
        if (map.size() < 10)
            n += i_n;
    }
    cout << n << endl;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        CountringSheep(n, i + 1);
    }
}