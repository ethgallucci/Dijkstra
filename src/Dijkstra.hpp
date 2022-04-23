#include "Graph.h"

int findMinDistanceVertex(int weights[], bool includedAlready[])
{
  // Initialize min values
  int min = INT_MAX;
  int min_index;

  for (int v = 0; v < HALF_MATRIX_MAX; v++)
  {
    if (includedAlready[v] == false && weights[v] <= min)
    {
      min = weights[v];
      min_index = v;
    }
  }
  return min_index;
}

// Ensures total path from src to v, through u, is smaller than current path v
bool ensureSmaller(int graph[HALF_MATRIX_MAX][HALF_MATRIX_MAX], int uDist, int vDist, int uIdx, int vIdx)
{
  return uDist + graph[uIdx][vIdx] < vDist;
}

void printSoln(int shortestPaths[])
{
  std::cout << "----Dijkstra's Shortest Path: Solutions---" << '\n';
  std::cout << "\n-V  \t -DfS" << '\n';
  for (int i = 0; i < HALF_MATRIX_MAX; i++)
  {
    std::cout << i << "  \t ";
    if (shortestPaths[i] != INT_MAX)
    {
      std::cout << shortestPaths[i] << '\n';
    }
    else
    {
      std::cout << "no path!" << '\n';
    }
  }
}

void DijkstraShortestPath(int graph[HALF_MATRIX_MAX][HALF_MATRIX_MAX], int src)
{
  int shortestPaths[HALF_MATRIX_MAX];
  bool includedAlready[HALF_MATRIX_MAX];

  // Init all infinites
  for (int i = 0; i < HALF_MATRIX_MAX; i++)
  {
    shortestPaths[i] = INT_MAX, includedAlready[i] = false;
  }

  // Distance of source to itself is always 0
  shortestPaths[src] = 0;

  // Find the shortest path from source to vertex for all vertices
  for (int currVert = 0; currVert < HALF_MATRIX_MAX; currVert++)
  {
    // Fetch the minimum distance vertex from the not yet included.
    // Set it's status as included already! (same idea as Dequeue)
    int u = findMinDistanceVertex(shortestPaths, includedAlready);
    includedAlready[u] = true;

    // Updated weights for all vertices adjacent to u
    for (int v = 0; v < HALF_MATRIX_MAX; v++)
    {
      if (!includedAlready[v] && graph[u][v] && shortestPaths[u] != INT_MAX && ensureSmaller(graph, shortestPaths[u], shortestPaths[v], u, v))
      {
        shortestPaths[v] = shortestPaths[u] + graph[u][v];
      }
    }
  }

  printSoln(shortestPaths);
}
