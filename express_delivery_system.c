#include <stdio.h>
#include <limits.h>

// Define the maximum number of nodes in the graph
#define MAX_NODES 100

// Define the value of infinity to represent unreachable nodes
#define INFINITY INT_MAX

// Implement Dijkstra's algorithm to find the shortest path between two nodes in a graph
void dijkstra(int graph[MAX_NODES][MAX_NODES], int num_nodes, int src, int dest, int dist[], int prev[]) {
    // Create an array to keep track of visited nodes
    int visited[MAX_NODES] = {0};
    
    // Initialize the distance to all nodes as infinity, except for the source node which has distance 0
    for (int i = 0; i < num_nodes; i++) {
        dist[i] = INFINITY;
    }
    dist[src] = 0;

    // Visit all nodes in the graph
    for (int count = 0; count < num_nodes - 1; count++) {
        // Find the unvisited node with the shortest distance from the source node
        int u = -1;
        for (int i = 0; i < num_nodes; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }
        // Add the selected node to the visited set
        visited[u] = 1;
        
        // Stop the algorithm if the destination node has been visited
        if (u == dest) {
            break;
        }
        
        // Update the distance to all unvisited neighbors of the selected node
        for (int v = 0; v < num_nodes; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INFINITY && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
}

// Calculate the shipping cost based on the shortest path distance and the number of items to be delivered
int calculate_shipping_cost(int dist[], int num_items) {
    int distance = dist[1]; // The shortest path distance is stored in the dist array
    int cost_per_mile = 2; // The cost per mile is a fixed value
    int shipping_cost = distance * cost_per_mile * num_items; // Calculate the total shipping cost
    
    return shipping_cost;
}

int main() {
    // Declare variables to store the number of nodes and edges in the graph
    int num_nodes, num_edges;
    // Prompt the user to enter the number of nodes and edges in the graph
    printf("Enter the number of nodes and edges in the graph: ");
    // Read in the values entered by the user
    scanf("%d %d", &num_nodes, &num_edges);

    // Declare a 2D array to represent the graph
    int graph[MAX_NODES][MAX_NODES] = {{0}};
    // Loop through each edge and prompt the user to enter the source node, destination node, and weight of the edge
    for (int i = 0; i < num_edges; i++) {
        int u, v, w;
        printf("Enter the source node, destination node, and weight of edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        // Add the edge to the graph
        graph[u][v] = w;
        graph[v][u] = w; // Since the graph is undirected, we need to add the edge in both directions
    }

    // Declare variables to store the source node, destination node, and number of items to be delivered
    int src, dest, num_items;
    // Prompt the user to enter the source node, destination node, and number of items to be delivered
    printf("Enter the source node, destination node, and number of items to be delivered: ");
    // Read in the values entered by the user
    scanf("%d %d %d", &src, &dest, &num_items);

    // Declare arrays to store the shortest distance and the previous node in the path from the source node to each node
    int dist[MAX_NODES], prev[MAX_NODES];
    // Use Dijkstra's algorithm to find the shortest path between the source node and the destination node
    dijkstra(graph, num_nodes, src, dest, dist, prev);
    // Calculate the shipping cost based on the shortest path distance and the number of items to be delivered
    int shipping_cost = calculate_shipping_cost(dist, num_items);
    // Print the shipping cost
    printf("The shipping cost for %d items from node %d to node %d is $%d.\n", num_items, src, dest, shipping_cost);

    return 0;
}

