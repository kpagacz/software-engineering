import java.util.ArrayList;

public class Vertex {
  ArrayList<Edge> edges;
  final int index;

  public Vertex(int index) {
    edges = new ArrayList<>();
    this.index = index;
  }

  public void addEdge(Edge edge) {
    if (edges.stream().noneMatch(e -> e == edge)) {
      edges.add(edge);
    }
  }

  @Override
  public boolean equals(Object obj) {
    return this.index == ((Vertex)obj).index;
  }
}
