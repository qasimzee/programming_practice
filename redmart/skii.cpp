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
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

class RedmartSkii
{
    vector<vector<int>> skii_map;
    int temp[1000][1000];
    int drop[1000][1000];
    int N;  //The size of grid
    int fill(int i, int j)
    {
        if (i < 0 || j < 0 || i >= N || j >= N)
            return 0;
        if (temp[i][j] != 0)
            return temp[i][j];
        
        int max_direction = 0, direction;
        int max_i = -1, max_j  = -1;
        if (i - 1 >= 0 && skii_map[i - 1][j] < skii_map[i][j])
        {
            direction = fill(i - 1, j);
            if (direction > max_direction)
            {
                max_i = i - 1;
                max_j = j;
                max_direction = direction;
            }
            
        }
        if (j - 1 >= 0 && skii_map[i][j - 1] < skii_map[i][j])
        {
            direction = fill(i, j - 1);
            if (direction > max_direction)
            {
                max_i = i;
                max_j = j - 1;
                max_direction = direction;
            }
        }
        
        if (i + 1 < N && skii_map[i + 1][j] < skii_map[i][j])
        {
            direction = fill(i + 1, j);
            if (direction > max_direction)
            {
                max_i = i + 1;
                max_j = j;
                max_direction = direction;
            }
        }
        if (j + 1 < N && skii_map[i][j + 1] < skii_map[i][j])
        {
            direction = fill(i, j + 1);
            if (direction > max_direction)
            {
                max_i = i;
                max_j = j + 1;
                max_direction = direction;
            }
        }
        temp[i][j] = max_direction + 1;
        if (temp[i][j] == 1)
            drop[i][j] = 0;
        else
            drop[i][j] = skii_map[i][j] - skii_map[max_i][max_j] + drop[max_i][max_j];
        return temp[i][j];
    }
    void findDistances()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (temp[i][j] == 0)
                {
                    fill(i, j);
                }
            }
        }
    }
    
public:
    RedmartSkii(int N, vector<vector<int>> skii_map)
    {
        this->skii_map = skii_map;
        memset(temp, 0, sizeof(temp[0][0]) * 1000 * 1000);
        this->N = N;
    }
    string findSteep()
    {
        findDistances();
        int longest_path = 0;
        int max_drop = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (temp[i][j] > longest_path)
                {
                    longest_path = temp[i][j];
                    max_drop = drop[i][j];
                }
                else if (temp[i][j] == longest_path)
                {
                    max_drop = drop[i][j];
                }
            }
        }
        stringstream ss;
        ss << longest_path << max_drop;
        return ss.str();
    }
    void print()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << temp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << drop[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main() {
//    ifstream cin;
//    cin.open("/Users/qasimzeeshan/Documents/cpp/TC/TC/map.txt", ios::in);
    int N;
    vector<vector<int>> skii_map;
    
    cin >> N >> N;
    
    for (int i = 0; i < N; i++)
    {
        vector<int> v;
        for (int j = 0; j < N; j++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        skii_map.push_back(v);
    }
    RedmartSkii *r = new RedmartSkii(N, skii_map);
    cout << r->findSteep();
    return 0;
}

