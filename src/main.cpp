#include "Graph.h"

int main() {
  Graph g(10);
  g.addEdge(Edge(0, 1));
  g.addEdge(Edge(1, 2));
  g.addEdge(Edge(2, 3));

  std::cout << "----Adjacency Matrix----\n";
  g.printMatrix();

  std::cout << "All Vertices   -D\n";
  g.printVertices();
}
