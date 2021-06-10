import java.util.ArrayList;
import java.util.HashSet;

public class UndirectedGraph {
  ArrayList<Node> nodes;

  public UndirectedGraph() {
    nodes = new ArrayList<>();
  }

  public int getNodesNumber() {
    return nodes.size();
  }

  public void addNode(Node node) {
    nodes.add(node);
  }

  public HashSet<Edge> getAllEdges() {
    HashSet<Edge> edges = new HashSet<>();
    for (Node n : nodes) {
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
              + e.connectedNodes[0].index
              + " -> "
              + e.connectedNodes[1].index
              + " weight: "
              + e.weight);
    }
  }
}
