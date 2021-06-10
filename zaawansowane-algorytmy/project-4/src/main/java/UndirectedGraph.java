import java.util.ArrayList;
import java.util.HashSet;

/**
 * Vertices are assumed to have indices from 0 to number of vertices in the graph minus one.
 * */
public class UndirectedGraph {
  ArrayList<Vertex> vertices;

  public UndirectedGraph() {
    vertices = new ArrayList<>();
  }

  public int getVerticesCount() {
    return vertices.size();
  }

  public void addVertex(Vertex vertex) {
    vertices.add(vertex);
  }

  public void addVertex() {
    vertices.add(new Vertex(vertices.size()));
  }

  public void addEdge(int source, int destination, int weight) {
    Edge newEdge = new Edge(vertices.get(source), vertices.get(destination), weight);
    vertices.get(source).addEdge(newEdge);
    vertices.get(destination).addEdge(newEdge);
  }

  public HashSet<Edge> getAllEdges() {
    HashSet<Edge> edges = new HashSet<>();
    for (Vertex n : vertices) {
      for (Edge e : n.edges) {
        edges.add(e);
      }
    }
    return edges;
  }

  public static void printEdges(ArrayList<Edge> edges) {
    for (Edge e : edges) {
      System.out.println(
          "Edge: "
              + e.connectedVertices[0].index
              + " -> "
              + e.connectedVertices[1].index
              + " weight: "
              + e.weight);
    }
  }
}
