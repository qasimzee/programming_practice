/**
 * https://www.hackerrank.com/challenges/bfsshortreach
 *
 */
#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

struct node
{
    int val;
    int distance;
};

class Graph
{
    list<int> *adj;
    int V;
    
public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void BFS(int s)
    {
        bool *visited = new bool[V];
        int *distances = new int[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            distances[i] = -1;
        }
        queue<node> q;
        q.push({s, 0});
        visited[s] = 0;
        
        while(!q.empty())
        {
            node n = q.front();
            distances[n.val] = n.distance;
            q.pop();
            for (auto i = adj[n.val].begin(); i != adj[n.val].end(); i++)
            {
                if (!visited[*i])
                {
                    q.push({*i, n.distance + 6});
                    visited[*i] = true;
                }
            }
        }
        for (int i = 0 ; i < this->V; i++)
        {
            if (distances[i] != 0 && i != s)
                cout << distances[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        Graph *g = new Graph(N);
        for (int i = 0; i < M; i++)
        {
            int s, d;
            cin >> s >> d;
            g->addEdge(s - 1, d - 1);
        }
        int s;
        cin >> s;
        g->BFS(s - 1);
    }
    return 0;
}

