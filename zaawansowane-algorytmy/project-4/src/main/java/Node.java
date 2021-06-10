import java.util.ArrayList;

public class Node {
  ArrayList<Edge> edges;
  final int index;

  public Node(int index) {
    edges = new ArrayList<>();
    this.index = index;
  }

  public Node(int index, ArrayList<Edge> edges) {
    this.edges = edges;
    this.index = index;
  }

  public void addEdge(Edge edge) {
    if (edges.stream().noneMatch(e -> e == edge)) {
      edges.add(edge);
    }
  }

  @Override
  public boolean equals(Object obj) {
    return this.index == ((Node)obj).index;
  }
}
