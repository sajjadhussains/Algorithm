// input -> weighted graph and a source
// output -> distance of all nodes from the source

/*
    --create a distance array "d"
    --initialize all values of "d" to infinity
    --d[src]=0
    --create visited array and mark all nodes as unvisited

    for i=0 to n-1:
        -pick the unvisited node with lowest d[node]
        -for all adjacent of node:
            if d[node]+c(node,adj_node)<d[adj_node]
                -d[adj_node]=d[node]+c(node,adj_node)
    
    output array "d"
    space complexity--O(n)
    time complexity->O(n)+O(n^)+O(m)
                    =O(n^2)+O(m)
                    =O(n^2)+O(n^2)=O(n^2)
*/