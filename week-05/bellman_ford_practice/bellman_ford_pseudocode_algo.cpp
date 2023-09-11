/*
Bellman ford pseudocode practice:

input:A weighted graph with a source node (without negetive cycle)
output: shortest path of all nodes from source node

--initialize a distance array "d" to infinity
--shortest distance from source node to all other nodes

-d[src]=0
for(n=0 to n-1):
    for all edges:for u,v,w
        if d[u]+w<d[v]
            d[v]=d[u]+w
print the distance array "d"

*/