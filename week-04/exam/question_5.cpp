// problem-link:https://www.spoj.com/problems/ABCPATH/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    while(true){
        int h,w;
        cin>>h>>w;
        int maze[h][50];
        if(h==0 && w==0){
            break;
        }
        

        for(int i=0;i<h;i++){
            string input;
            cin>>input;

            for(int j=0;j<w;j++){
                if(input[j]=='A'){
                    cout<<input[j]<<" ";
                    maze[i][j]=1;
                }
                maze[i][j]=-1;
            }
        }

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cout<<maze[i][j]<<"\t";
            }
            cout<<endl;
        }

    }

    return 0;
}