#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <sstream>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool leaf = false;
    unordered_map<string, int> questions_count;
    TrieNode():leaf(false), children(){}
};

class Trie {
    TrieNode *root;
public:
    Trie()
    {
        root = new TrieNode();
    }

    void addQuestion(string str, unordered_map<string, vector<string>> &tree) {
        string topic = "";
        int i;
        for (i = 0; i < str.size(); i++) {
            if (str[i] == ':')
                break;
            topic += str[i];
        }
        TrieNode* node = root;
        i += 2; //Skipping colon and first space
        for (; i < str.size(); i++) {
            char c = str[i];
            if (node->children.count(c) == 0) {
                TrieNode *n = new TrieNode();
                node->children[c] = n;
            }
            node->children[c]->questions_count[topic]++;
            for (int i = 0; i < tree[topic].size(); i++) {
                node->children[c]->questions_count[tree[topic][i]]++;
            }
            node = node->children[c];
        }
    }
    int searchTrie(string str, string topic) {
        TrieNode *node = root;
        for (int i = 0; i < str.size(); i++) {
            if (node->children.count(str[i]) > 0) {
                node = node->children[str[i]];
            }
            else {
                return 0;
            }
        }

        return node->questions_count[topic];
    }
};


class QuestionsSearcher {
    unordered_map<string, vector<string>> tree;
    Trie *trie;
public:
    void populateTree(string str) {
        vector<string> topic_stack;
        stringstream ss(str);
        string tok;

        bool opened = false;
        string prev_string = "";
        while (ss >> tok) {
            if (tok == "(") {
                opened = true;
            }
            else if (tok == ")") {
                topic_stack.pop_back();
            }
            else  {
                if (opened) {
                    topic_stack.push_back(prev_string);
                    opened = false;
                }
                for (int i = 0; i < topic_stack.size(); i++) {
                    tree[tok].push_back(topic_stack[i]);
                }
                prev_string = tok;
            }
        }
        /*for (auto i = tree.begin(); i != tree.end(); i++) {
            cout << i->first << ":";
            vector<string> v = i->second;
            for (int j = 0; j < v.size(); j++) {
                cout << v[j] << " ";
            }
            cout << endl;
        }*/
    }
    
    void populateQuestions(vector<string> questions) {
        trie = new Trie();
        for (int i = 0; i < questions.size(); i++) {
            trie->addQuestion(questions[i], tree);
        }
    }
    int search(string query) {
        string topic = "";
        int i;
        for (i = 0; i < query.size(); i++) {
            if (query[i] == ' ')
                break;
            topic += query[i];
        }
        query = query.substr(i + 1);
        return trie->searchTrie(query, topic);
    }
};

int main() {
    QuestionsSearcher s;
    string str;
    std::getline(cin, str);
    std::getline(cin, str);
    s.populateTree(str);
    std::getline(cin, str);
    int N = stoi(str);
    vector<string> questions;
    for (int i = 0; i < N; i++) {
        std::getline(cin, str);
        questions.push_back(str);
    }
    s.populateQuestions(questions);
    std::getline(cin, str);
    N = stoi(str);
    for (int i = 0; i < N; i++) {
        std::getline(cin, str);
        cout << s.search(str) << endl;
    }
    return 0;
}

