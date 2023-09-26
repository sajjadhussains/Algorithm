#include <bits/stdc++.h>

using namespace std;

int n;
const long long INF = 100000;
const int N = 1e5 + 10;
long long d[N];
int parent[N];
vector<pair<int, int>> adj_list[N];
int last_updated_node, start_node;

bool bellman_ford()
{
    for (int i = 0; i < n; i++)
    {
        d[i] = INF;
    }
    bool negetive_cycle = false;

    for (int i = 1; i <= n; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            for (pair<int, int> adj_node : adj_list[node])
            {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;
                if (d[u] + w < d[v])
                {
                    d[v] = d[u] + w;
                    parent[v] = u;
                    if (i = n)
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
            adj_list[i + 1].push_back({j + 1, weight});
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
        for (auto node : cycle)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}