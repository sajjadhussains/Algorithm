/*
input: A weighted graph as an adjacency matrix
output:all pair shortest distance

-create a distance array "d" where d[i][j]=x where there is a direct  edge from node "i" to "j"
-for all node "i" d[i][i]=0
-for all nodes "i" and "j",where there is no direct edge from "i" to "j"
    d[i][j]=INF

for all node "k"
    for all node "u":
        for all node "v":
            -d[u][v]=min(d[u][v],d[u][k]+d[k][v])

-output all pair shortest distance "d"

Time Complexity-O(V^3)
Space Complexity-O(V^2)

*/