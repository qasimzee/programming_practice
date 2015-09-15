/**
 * https://www.hackerrank.com/challenges/no-prefix-set
 * This hackerrank problem is attempted using Trie
 * as otherwise it will run in O(N^2) that will cause a timeout.
 *
 */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool leaf = false;
    TrieNode():leaf(false), children(){}
};

class Trie
{
    TrieNode *root;
public:
    Trie()
    {
        root = new TrieNode();
    }

    bool addWord(string s)
    {
        TrieNode* node = root;
        for (int i = 0 ; i < s.size() ; i++) {
            char c = s[i];
            if (node->children.count(c) == 0)
                node->children[c] = new TrieNode();
            node = node->children[c];
            if (node->leaf)
            {
                return false;
            }
        }
        node->leaf = true;
        if (node->children.size() == 0)
            return true;
        return false;
    }
};

int main() {
    bool added = true;
    Trie trie;
    int N;
    cin >> N;
    string bad_string;
    while (N--) {
        string str;
        cin >> str;
        if (added)
        {
            added = trie.addWord(str);
            if (!added && bad_string.size() == 0)
                bad_string = str;
        }
    }
    if (added)
    {
        cout << "GOOD SET";
    }
    else
    {
        cout << "BAD SET" << endl;
        cout << bad_string << endl;
    }
    return 0;
}

