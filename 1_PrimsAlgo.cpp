#include <iostream>
#include <cstring>
#define INF 9999999
#define NUM_VERTICES 5
using namespace std;

// Adjacency matrix to represent the graph
int graph[NUM_VERTICES][NUM_VERTICES] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}};

// Function to implement Prim's Minimum Spanning Tree algorithm
void primMST() {
  // Array to track selected vertices
  bool selectedVertices[NUM_VERTICES];
  
  // Initialize all vertices as unselected
  memset(selectedVertices, false, sizeof(selectedVertices));
  
  // Number of edges in the minimum spanning tree
  int numEdges = 0;
  
  // Select the first vertex as the starting point
  selectedVertices[0] = true;
  
  // Variables to store the indices of vertices forming the edge with minimum weight
  int x, y;
  
  // Print header for the output
  cout << "Edge"
     << " : "
     << "Weight";
  cout << endl;
  
  // Loop until all vertices are selected
  while (numEdges < NUM_VERTICES - 1) {
    // Initialize minimum weight to infinity
    int minWeight = INF;
    x = 0;
    y = 0;
    
    // Iterate through all selected vertices
    for (int i = 0; i < NUM_VERTICES; i++) {
      if (selectedVertices[i]) {
        // Check adjacent vertices to the selected vertex
        for (int j = 0; j < NUM_VERTICES; j++) {
          // If the vertex is not selected and there is an edge between them
          if (!selectedVertices[j] && graph[i][j]) {
            // Update minimum weight and indices of vertices if a smaller weight is found
            if (minWeight > graph[i][j]) {
              minWeight = graph[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    
    // Print the edge and its weight
    cout << x << " - " << y << " :  " << graph[x][y];
    cout << endl;
    
    // Mark the selected vertex as visited
    selectedVertices[y] = true;
    
    // Increment the number of edges
    numEdges++;
  }
}

// Main function
int main() {
  // Call the Prim's MST function
  primMST();
  return 0;
}
