/*
    Graph Representation
    =====================
    Topic:Adjacency matrix-->2d Array

    0-------1
           / \
          2---3
    
    #total nodes=4
    #total edge=4
    #undirected+unweighted

    matrix-->#no of nodes * #no of nodes
           ->4*4
    matrix[i][j]=1
        if and only if (i->j)
    
    0->1
    1->0
    1->2
    2->1
    2->3
    3->2
    3->1
    1->3
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    int nodes=4;

    int matrix[nodes][nodes];

    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            matrix[i][j]=0;
        }
    }

    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}