/*
    problem-link:https://cses.fi/problemset/task/1678
input:
4 5
1 3
2 1
2 4
3 2
3 4

*/

#include<bits/stdc++.h>

using namespace std;
const int N=2e5;

int visited[N];
vector<int>adj_list[N];

bool detect_cycle(int node){
    visited[node]=1;

    for(int adj_node:adj_list[node]){
        /*
            -visited[adj_node]==0 ->unexplored node|apply dfs
            -visited[adj_node]==1 ->"paused" node |cycle detected
            -visited[adj_node]==2 ->"done" node|continue
        */
       if(visited[adj_node]==0){
            bool got_cycle = detect_cycle(adj_node);
            if(got_cycle){
                return true;
            }
       }
       else if(visited[adj_node]==1){
        return true;
       }
    }
    return false;
}

int main()
{   
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;

        adj_list[a].push_back(b);
    }

    bool cycle_exist = false;

    for(int i=1;i<=n;i++){
        bool got_cycle = detect_cycle(i);
        if(got_cycle){
            cycle_exist = true;
            break;
        }
    }

    if(cycle_exist){
        cout<<"Cycle Exist"<<endl;
    }
    else{
        cout<<"Cycle Does Not Exist"<<endl;
    }

    return 0;
}