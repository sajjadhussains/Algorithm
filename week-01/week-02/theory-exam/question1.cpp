// Write a program that takes a directed graph as input and checks whether it is bi-directionoal which means for every pair of nodes where there is an edge u -> v, there should also be an edge v -> u.
// Use this code to take the graph as input: https://ideone.com/divsSy
// Which graph representation would you prefer?


#include<bits/stdc++.h>


using namespace std;
const int N=1e5;
vector<int>adj_list[N];


bool isBidirectional(int numOfEdges)
{
    bool flag=true;
    for(int u=0;u<numOfEdges;u++){
        for(int v:adj_list[u]){
            for(int i=0;i<adj_list[v].size();i++){
                if(adj_list[v][i]==u){
                    flag=false;
                    break;
                }
            }
        }
    }
    return flag;
}
int main()
{
   
    // n = number of nodes
    // m = number of edges
    int n, m;
    cin >> n >> m;
 
    for(int i = 0 ; i < m ; i++) { // loop over the number of edges
        int u, v;
        cin >> u >> v; // There exists a directed edge from u to v
        adj_list[u].push_back(v);
        // adj_list[v].push_back(u);
    }
    if(isBidirectional(m)) cout<<"Graph is not bidirectional"<<endl;
    else cout<<"Graph is bidirectional"<<endl;


    return 0;
}
