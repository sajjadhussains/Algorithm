/*
    intput:A weighted graph with source node(with negetive cycle exists or not)
    output:if negetive cycle exists,then show "Negetive cycle exists in the graph" || print the shortest distance of all nodes from the source node

    ---
    -initialize a distance array "d" with all values to infinity
    -d[src]=0
    bool is_negetive_cycle=false

    for(i=1 to n):
        for all edges:u,v,w
            if(d[u]+w<d[v])
                d[v]=d[u]+w
                if i=n
                    is_negetive_cycle = true
*/