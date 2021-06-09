import java.util.ArrayList;

public class Node {
    ArrayList<Edge> edges;

    public Node() {
        edges = new ArrayList<>();
    }

    public Node(ArrayList<Edge> edges) {
        this.edges = edges;
    }

    public void addEdge(Edge edge) {
        edges.add(edge);
    }
}
