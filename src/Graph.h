#ifndef GRAPH_H
# define GRAPH_H

#include <iostream>
#include <vector>

#define RC_MATRIX_MAX 10

struct Edge {
  unsigned src, dest;
  Edge(unsigned s, unsigned d) {
    src = s, dest = d;
  }
};

struct VertexNode {
  unsigned distance;
  const VertexNode* predV; 
};

class Graph {
  public:
    std::vector<VertexNode> vertices;
    int adjMatrix[RC_MATRIX_MAX][RC_MATRIX_MAX];     

    Graph(unsigned V) {
      vertices.resize(V);
      for (int i = 0; i < RC_MATRIX_MAX; i++)
      {
        for (int j = 0; j < RC_MATRIX_MAX; j++)
        {
          adjMatrix[i][j] = 0;
          adjMatrix[j][i] = 0;
        }
      }
    }

    void addEdge(Edge const &edge) {
      adjMatrix[edge.src][edge.dest] = 1;
      adjMatrix[edge.dest][edge.src] = 1;
    }

    void print() {
      int i, j;
      for(i = 0; i < RC_MATRIX_MAX; i++) {
        for(j = 0; j < RC_MATRIX_MAX; j++) {
          std::cout <<  this->adjMatrix[i][j];
        }
        std::cout << '\n';
      }
    }
};

#endif
