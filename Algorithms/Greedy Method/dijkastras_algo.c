/* Dijkstra algorithm
Dijkstra algorithm is a single-source shortest path algorithm. Here, single-source means that only one source is given,
and we have to find the shortest path from the source to all the nodes.

Dijkstra’s algorithm is very similar to Prim’s algorithm for minimum spanning tree. 
Like Prim's MST, generate a SPT (shortest path tree) with a given source as a root. 
Maintain two sets, one set contains vertices included in the shortest-path tree, 
other set includes vertices not yet included in the shortest-path tree. At every step of the algorithm, 
find a vertex that is in the other set (set not yet included) and has a minimum distance from the source.

Follow the steps below to solve the problem:
o	Create a set sptSet (shortest path tree set) that keeps track of vertices included in the shortest-path tree, i.e., whose minimum distance from the source is calculated and finalized. Initially, this set is empty. 
o	Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE. Assign the distance value as 0 for the source vertex so that it is picked first. 
o	While sptSet doesn’t include all vertices 
    >	Pick a vertex u which is not there in sptSet and has a minimum distance value. 
    >	Include u to sptSet. 
    >	Then update distance value of all adjacent vertices of u. 
    >	To update the distance values, iterate through all adjacent vertices. 
    >	For every adjacent vertex v, if the sum of the distance value of u (from source) and weight of edge u-v, is less than the distance value of v, then update the distance value of v.

Pseudocode
    COST = 0
    PREVIOUS = 1

    FUNCTION dijkstras(graph, start_node)
        unvisited = {}
        visited = {}
        
        FOR key IN graph
                unvisited[key] = [infinity, NULL]
    NEXT key
    
    unvisited[start_node][COST] = 0
    
    finished = False
    WHILE finished == False
        IF LEN(unvisited) == 0
            finished = True
        ELSE
            current_node = minimum(unvisited)
            
            FOR neighbour IN graph[current_node]
                IF neighbour NOT IN visited
                    cost = unvisited[current_node][COST] + graph[current_node][neighbour]
                    IF cost < unvisited[neighbour][COST]
                        unvisited[neighbour][COST] = cost
                        unvisited[neighbour][PREVIOUS] = current_node
                    ENDIF
                ENDIF
            NEXT neighbour
            
            visited[current_node] = unvisited[current_node]
            DEL(unvisited[current_node])
            ENDIF
    ENDWHILE
    RETURN visited
    
    ENDFUNCTION        

------------------------------------------------------------------------------------------------
#-- Time Complexcity --#

Worst Case Time Complexity
    Total: O(V^2)

Average Case Time Complexity
    Total: O(V^2)

Best Case Time Complexity
    Total: O(V^2)

*/