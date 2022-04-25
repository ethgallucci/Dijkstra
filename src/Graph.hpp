/*

Ethan Gallucci
COMSC-210-5068

Lab: Graphs --- Dijkstra's Algorithm
04-22-2022
OSX Monterey 12.3.1, g++ 13.1.6
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <stdint.h>

#define HALF_MATRIX_MAX 9

// Defines an edge in our matrix
struct Edge
{
  uint32_t src, dest;
  uint32_t weight;
  Edge(uint32_t s, uint32_t d, uint32_t w)
  {
    src = s, dest = d, weight = w;
  }
};

// Graph Class
class Graph
{
public:
  // 9 x 9 matrix
  int adjMatrix[HALF_MATRIX_MAX][HALF_MATRIX_MAX];

  // Overloaded constructor, accepts num vertices as argument
  Graph(uint32_t V)
  {
    // Initialize all vertices to 0
    for (int i = 0; i < HALF_MATRIX_MAX; i++)
    {
      for (int j = 0; j < HALF_MATRIX_MAX; j++)
      {
        adjMatrix[i][j] = 0;
        adjMatrix[j][i] = 0;
      }
    }
  }

  // Adds an edge to the matrix
  void addEdge(Edge const &edge)
  {
    if(edge.src > HALF_MATRIX_MAX) { return; }
    else if(edge.dest > HALF_MATRIX_MAX) { return; }

    adjMatrix[edge.dest][edge.src] = edge.weight;
    adjMatrix[edge.src][edge.dest] = edge.weight;
  }

  void printMatrix()
  {
    int i, j;
    for (i = 0; i < HALF_MATRIX_MAX; i++)
    {
      for (j = 0; j < HALF_MATRIX_MAX; j++)
      {
        std::cout << this->adjMatrix[i][j];
      }
      std::cout << '\n';
    }
    std::cout << '\n';
  }
};

#endif
