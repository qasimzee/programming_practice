/**
 * The following program will match a list words in a string using a trie.
 * It uses Trie data structure to print the workds and their count.
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

    void addWord(string s)
    {
        TrieNode* node = root;
        for (auto c: s) {
            if (node->children.count(c) == 0) node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->leaf = true;
    }
    
    unordered_map<string, int> searchWords(string stream)
    {
        TrieNode *cur = root;
        cout << "search start" << endl;
        unordered_map<string, int> words_count_map;
        string current_word = "";
        for (int i = 0; i < stream.size(); i++)
        {
            char c = stream[i];
            if (cur->children.count(c) == 0)
            {
                current_word = "";
                cur = root;
            }
            if (cur->children.count(c))
            {
                current_word += c;
                cur = cur->children[c];
            }
            if (cur->leaf)
            {
                if (words_count_map.count(current_word) == 0)
                    words_count_map[current_word] = 0;
                words_count_map[current_word]++;
            }
        }
        for (auto wcmap_it = words_count_map.begin(); wcmap_it != words_count_map.end(); wcmap_it++)
        {
            cout << wcmap_it->first << " " << wcmap_it->second << endl;
        }
        return words_count_map;
    }
};

int main() {
    Trie trie;
    trie.addWord("yahoo");
    trie.addWord("abcdefgh");
    trie.addWord("abcde");
    trie.addWord("abcdefghijk");
    //yahooabcdefghijkyahooabcdefghijkyahooabcdefghijkyahooabcdefghijkyahooyahoo
    trie.searchWords("yahooabcdefghijkyahooabcdefghijkyahooabcdefghijkyahooabcdefghijkyahooyahoo");
    return 0;
}

