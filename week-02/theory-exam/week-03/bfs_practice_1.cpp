// bfs->breadth first search:it is an graph traversal algorithm.if you are in a X node ,then you will go to the next node,then you will go to the next node and consequtively,you will visit all the nodes of the graph.This process is called breadth first search.

/*
    Pseudocode of Bfs:
        1.initialize a visited array 
            int visited[N]
        2.initialize a queue and push the source node to the queue and visited[source]=1
        3.while queue is not empty:
            1.take the top of the queue and pop it from the queue:
                front=q.front()
                q.pop()
            2.traverse all the adjacent node of the top node,if the node is not visited yet then,make the node visited and push to the queue.
                if(adj_node of the top node==0)
                    visited[adj_node]=1
                    q.push(adj_node)
            
*/

#include<bits/stdc++.h>

using namespace std;

const int N=1e5;
vector<int>adj_list[N];

int visited[N];

void bfs(int src){

    queue<int> q;
    q.push(src);

    visited[src]=1;

    while(!q.empty()){
        int front = q.front();
        cout<<front<<endl;
        q.pop();

        for(int adj_node:adj_list[front]){
            if(visited[adj_node]==0){
                visited[adj_node]=1;
                q.push(adj_node);
            }
        }
    }
}


int main()
{
    int nodes,edges;
    cin>>nodes>>edges;

    for(int i=0;i<edges;i++){
        int n,m;
        cin>>n>>m;

        adj_list[n].push_back(m);
        adj_list[m].push_back(n);
    }

    bfs(0);
    return 0;
}