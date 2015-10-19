/**
 * https://www.hackerrank.com/challenges/find-median-1 
 * The median of a finite list of numbers can be found 
 * by arranging all the integers from lowest to highest value 
 * and picking the middle one. For example, the median of {3,3,5,9,11} is 5. 
 * If there is an even number of integers, then there is no single middle value, 
 * and the median is then usually defined to be the mean of the two middle values. 
 * For examples, the median of {3,5,7,9} is (5+7)/2=6.
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

void swap(vector<int> &v, int first, int second)
{
    int temp = v[first];
    v[first] = v[second];
    v[second] = temp;
}

class Compare
{
public:
    bool operator() (int a, int b)
    {
        return a < b;
    }
};

bool compare(int a, int b)
{
    return (a < b);
}
class PQMedian
{
private:
    std::priority_queue<int> lower;
    std::priority_queue<int, std::vector<int>, std::greater<int>> upper;
public:

    double getCurrentMedianHeap(int x)
    {
        if (upper.size() > 0 && x >= upper.top())
            upper.push(x);
        else
            lower.push(x);
        if (upper.size() - lower.size() == 2)
        {
            lower.push(upper.top());
            upper.pop();
        }
        else if (lower.size() - upper.size() == 2)
        {
            upper.push(lower.top());
            lower.pop();
        }
        
        if (upper.size() == lower.size())
            return (upper.top() + lower.top()) / 2.0;
        if (upper.size() > lower.size())
            return upper.top();
        if (upper.size() < lower.size())
            return lower.top();
        return -1;
    }
};


int main()
{
    int N;
    cin >> N;
    PQMedian pq;
    while(N--)
    {
        int x;
        cin >> x;
        cout << pq.getCurrentMedianHeap(x) << endl;
    }
    return 0;
}

