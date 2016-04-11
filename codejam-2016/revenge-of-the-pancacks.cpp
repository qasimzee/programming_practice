#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

bool isValid(string str) {
    for (int i = 0; i < str.size(); i++)
        if (str[i] == '-')
            return false;
    return true;
}

char Flip(char ch) {
    if (ch == '-')
        return '+';
    return '-';
}

string DoFlip(string str) {
    if (str[0] == '+') {
        int i = 0;
        while (str[i] == '+') {
            str[i++] = '-';
        }
        return str;
    }
    int index = -1;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '-') {
            index = i;
        }
    }
    for (int i = 0; i <= index / 2; i++) {
        char temp = str[i];
        str[i] = Flip(str[index - i]);
        str[index - i] = Flip(temp);
    }
    return str;
}

int FlipCakes(string str)
{
    int moves = 0;
    while (!isValid(str)) {
        str = DoFlip(str);
        moves++;
    }
    return moves;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        cout <<"Case #"<<(i + 1)<<": "<< FlipCakes(str) << endl;
    }
}