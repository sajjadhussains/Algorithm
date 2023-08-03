#include<bits/stdc++.h>

using namespace std;

int main()
{
    int nodes=4;
    vector<pair<int,int>>adj_list[nodes];

    adj_list[0].push_back({1,7});
    adj_list[1].push_back({2,8});
    adj_list[1].push_back({3,10});
    adj_list[2].push_back({3,9});

    for(int i=0;i<nodes;i++){
        cout<<i<<"->";
        for(int j=0;j<adj_list[i].size();j++){
            cout<<"("<<adj_list[i][j].first<<","<<adj_list[i][j].second<<")";
        }
        cout<<endl;
    }

    return 0;

}