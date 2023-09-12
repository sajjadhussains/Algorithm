#include<bits/stdc++.h>

using namespace std;
const int N=1e3+3;
const int INF = 1e9;
int d[N][N];

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j]=INF;
        }
    }

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        d[u][v]=w;
    }

    for(int i=1;i<=n;i++){
        d[i][i]=0;
    }

    for(int k=1;k<=n;k++){
        for(int u=1;u<=n;u++){
            for(int v=1;v<=n;v++){
                d[u][v]=min(d[u][v],d[u][k]+d[k][v]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[i][j]!=INF && d[i][j]!=0){
                cout<<"From node "<<i<<" to "<<j<<" distance: "<<d[i][j];
                cout<<endl;
            }
        }
    }
    cout<<endl;

    return 0;
}

/*
for testing input:
    1 2 5
    2 4 3
    3 1 2
    3 4 50
*/