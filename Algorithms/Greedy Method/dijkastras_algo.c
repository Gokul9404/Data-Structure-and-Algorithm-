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
// C program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // The output array. dist[i] will hold the
				// shortest
	// distance from src to i

	bool sptSet[V]; // sptSet[i] will be true if vertex i is
					// included in shortest
	// path tree or shortest distance from src to i is
	// finalized

	// Initialize all distances as INFINITE and stpSet[] as
	// false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed. u is always equal to
		// src in the first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	printSolution(dist);
}

// driver's code
int main()
{
	/* Let us create the example graph discussed above */
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	// Function call
	dijkstra(graph, 0);

	return 0;
}
