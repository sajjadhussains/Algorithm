/*
    problem_link:https://cses.fi/problemset/task/1666
    yah!!i have solved this problem thinking from my head and totaly by myself....
*/

#include<bits/stdc++.h>
using namespace std;

const int N=2e5;
vector<int>adj_list[N];
int visited[N];
vector<pair<int,int>>roads;

void dfs(int node)
{
    visited[node]=1;

    for(int adj_node:adj_list[node]){
        if(visited[adj_node]==0){
            dfs(adj_node);
        }
    }
}



int main()
{
    int nodes,edges;
    cin>>nodes>>edges;

    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int required_roads=0;
    int u;
    for(int i=1;i<=nodes;i++){
        
        if(visited[i]==0){
            dfs(i);
            if(i>1){
                u=i-1;
                required_roads++;
                roads.push_back(make_pair(u,i));
            }
        }
    }
    cout<<required_roads<<endl;
    for(int i=0;i<roads.size();i++){
        cout<<roads[i].first<<" "<<roads[i].second<<endl;
    }
    cout<<endl;
    return 0;
}