#include "Dijkstra.hpp"

int main()
{
  // Initialize our graph
  Graph driver(10);
  driver.addEdge(Edge(0, 1, 9));
  driver.addEdge(Edge(1, 2, 5));
  driver.addEdge(Edge(2, 3, 2));
  driver.addEdge(Edge(3, 0, 1));
  driver.addEdge(Edge(5, 1, 2));
  driver.addEdge(Edge(7, 3, 4));
  driver.addEdge(Edge(6, 7, 5));
  driver.addEdge(Edge(8, 3, 4));

  std::cout << "Running Dijkstra's single source shortest path algorithm on the following adjacency matrix..."
            << std::endl;

  std::cout << "----Adjacency Matrix----\n";
  driver.printMatrix();

  DijkstraShortestPath(driver.adjMatrix, 0);
}
