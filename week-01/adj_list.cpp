/*
    Graph Representation
    =====================
    Topic:Adjacency List-->2d Array

    0->1
    1->0,2,3
    2->1,3
    3->1,2
    space complexity=O(n^n)
    time complexity=O(n^n)

    Another-Example:
        #no of nodes=10
        #no of edge=2
        0-----1
        0-----5
        for these example,edge is comparetively small,that means it is a sparse graph.for the sparse graph adjacency list will perform better than adjacency matrix.
    Adjacency Matrix-for weighted and directed graph
        matrix[0][1]=2
        matrix[1][0]=2
        matrix[4][5]=9
        matrix[5][4]=9
    Adjacency List directed graph
        0->1
        1->2
        3->2
        3->1

*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int nodes=4;
    vector<pair<int,int>>adj_list[nodes];
    adj_list[0]={{1,2}};
    adj_list[1]={{2,4}};
    adj_list[3]={{2,8}};
    adj_list[3]={{1,7}};
    // adj_list[0].push_back({1,2});
    // adj_list[1].push_back({2,4});
    // adj_list[3].push_back({2,8});
    // adj_list[3].push_back({1,7});

    // for adjacency list --unweighted and undirected graph
    // adj_list[0]={1};
    // adj_list[1]={0,2,3};
    // adj_list[2]={1,3};
    // adj_list[3]={1,2};

    for(int i=0;i<nodes;i++){
        cout<<i<<"->";
        for(int j=0;j<adj_list[i].size();j++){
            // cout<<adj_list[i][j]<<",";
            cout<<"("<<adj_list[i][j].first<<","<<adj_list[i][j].second<<")";
        }
        cout<<endl;
    }
    return 0;
}