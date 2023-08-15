#include<bits/stdc++.h>

using namespace std;
const int N=2e5;
vector<int>adj_list[N];
int indegree[N];
stack<int>s;
int nodes,edges;
queue<int>q;

void top_sort_bfs(){
    
    for(int i=1;i<=nodes;++i){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int head = q.front();
        q.pop();
        s.push(head);

        for(int adj_node:adj_list[head]){
            indegree[adj_node]--;
            if(indegree[adj_node]==0){
                q.push(adj_node);
            }
        }
    }
   
}

int main()
{
    
    cin>>nodes>>edges;

    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;

        adj_list[u].push_back(v);
        indegree[v]++;
    }

    // top_sort_bfs(1);
    top_sort_bfs();
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    
    return 0;
}