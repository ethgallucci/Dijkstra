#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <stdint.h>
#include <vector>

#define HALF_MATRIX_MAX 5

struct Edge
{
  uint32_t src, dest;
  uint32_t weight;
  Edge(uint32_t s, uint32_t d, uint32_t w)
  {
    src = s, dest = d, weight = w;
  }
};

class Graph
{
public:
  int adjMatrix[HALF_MATRIX_MAX][HALF_MATRIX_MAX];

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

  void addEdge(Edge const &edge)
  {
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
