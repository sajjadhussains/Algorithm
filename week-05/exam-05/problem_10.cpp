#include <bits/stdc++.h>

using namespace std;

int n,m;
const long long INF = 100000;
const int N = 1e5 + 10;
long long dist[N];
int parent[N];
vector<pair<int, int>> g[N];
int last_updated_node, start_node;

bool bellman_ford()
{
    for(int i=0;i<n;i++)
        dist[i]=INF;

    bool negetive_cycle=false;

    for (int i = 1; i <= n; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            for (auto adj: g[node])
            {
                int u = node;
                int v = adj.first;
                int w = adj.second;
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    if (i == n)
                    {
                        negetive_cycle = true;
                        last_updated_node = v;
                    }
                }
            }
        }
    }
    return !negetive_cycle;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int weight;
            cin >> weight;
            if (weight == INF || weight == 0)
                {
                    continue;
                }
            g[i + 1].push_back({j+1,weight});
        }
    }

    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
    }

    if (bellman_ford())
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        int selected_node = last_updated_node;
        for (int i = 1; i <= n - 1; i++)
        {
            selected_node = parent[selected_node];
        }

        start_node = selected_node;
        vector<int> cycle;
        cycle.push_back(selected_node);
        while (true)
        {
            selected_node = parent[selected_node];
            cycle.push_back(selected_node);
            if (start_node == selected_node)
            {
                break;
            }
        }

        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << endl;
        for (auto v : cycle)
        {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}