// --create a distance array "d"
// --initialize all values of "d" to infinity
// --d[src]=0
// --create visited array and mark all nodes as unvisited

// for i=0 to n-1:
//     -pick the unvisited node with lowest d[node]
//     -for all adjacent of node:
//         if d[node]+c(node,adj_node)<d[adj_node]
//             -d[adj_node]=d[node]+c(node,adj_node)
    
// output array "d"
// store the minimum value in "d" as min_distance
// initialize second_min_distance to infinity

// for i=0 to n-1:
//     if d[i] > min_distance and d[i] < second_min_distance:
//         second_min_distance = d[i]

// output second_min_distance
