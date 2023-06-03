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