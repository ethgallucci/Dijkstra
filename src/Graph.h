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
  int value;
  unsigned distanceFromSrc;
  const VertexNode* predecessorV; 
};

// Util func to create a new vertex
VertexNode makeVertex(int v) {
  VertexNode* newV = new VertexNode;
  newV->value = v;
  newV->distanceFromSrc = 0;
  newV->predecessorV = 0;
  return *newV;
}

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
    
      bool hasSrc, hasDest = false;
      for(auto v = 0; v < vertices.size(); v++) {
        // logic gate
        if(hasSrc && hasDest) { break; }
        // ensure we've stored both (src, dest) vertices
        if(vertices[v].value == edge.src) {
          hasSrc = true; 
        }
        else if(vertices[v].value == edge.dest) {
          hasDest = true;
        }
      } 

      if(hasSrc && hasDest) { return; }
      else if(hasSrc && !hasDest) {
        vertices.push_back(makeVertex(edge.dest));
      }
      else {
        vertices.push_back(makeVertex(edge.src));
      }
    }

    void printMatrix() {
      int i, j;
      for(i = 0; i < RC_MATRIX_MAX; i++) {
        for(j = 0; j < RC_MATRIX_MAX; j++) {
          std::cout <<  this->adjMatrix[i][j];
        }
        std::cout << '\n';
      }
    }

    void printVertices() {
      for(auto v = 0; v < this->vertices.size(); v++) {
        std::cout << this->vertices[v].value << "\t-->\t" << this->vertices[v].distanceFromSrc << '\n'; 
      }
      std::cout << '\n';
    }
};

#endif
