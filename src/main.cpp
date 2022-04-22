#include "Graph.h"

int main() {
  Graph g(10);
  g.addEdge(Edge(0, 1));
  g.addEdge(Edge(1, 2));
  g.addEdge(Edge(2, 3));

  g.print();
}
