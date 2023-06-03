/*
5 8
########
#.A#...#
#.##.#B#
#......#
########
output:9

*/

#include<bits/stdc++.h>

using namespace std;
const int N=2002;

int maze[N][N],visited[N][N];
int level[N][N];


void bfs(pair<int,int>src){
    queue<pair<int,int>>q;
    visited[src.first][src.second]=1;

    q.push(src);

    while(!q.empty()){
        pair<int,int>head=q.front();
        q.pop();

        int x=head.first;
        int y=head.second;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    pair<int,int>src,dst;

    for(int i=0;i<n;i++){
        string input;
        cin>>input;

        for(int j=0;j<m;j++){
            if(input[j]=='#'){
                maze[i][j]=-1;
            }
            else if(input[j]=='A'){
                src={i,j};
            }
            else if(input[j]=='B'){
                dst={i,j};
            }

        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<maze[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    // cout<<"source is: "<<src.first<<","<<src.second<<endl;
    // cout<<"destination is: "<<dst.first<<","<<dst.second<<endl;

    return 0;
}