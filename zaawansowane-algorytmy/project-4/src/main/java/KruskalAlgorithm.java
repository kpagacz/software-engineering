import java.util.ArrayList;

public class KruskalAlgorithm {
    public static ArrayList<Edge> getMst(UndirectedGraph graph) {
        ArrayList<Edge> mst = new ArrayList<>();
        MinHeap<Edge> edgesHeap = new MinHeap<>(Edge.class, graph.getAllEdges().stream().toList());
        DisjointSets forest = new DisjointSets(graph.getVerticesCount());

        while(edgesHeap.size() > 0) {
            Edge edge = edgesHeap.pop();
            if (forest.find(edge.connectedVertices[0].index) != forest.find(edge.connectedVertices[1].index)) {
                mst.add(edge);
                forest.union(edge.connectedVertices[0].index, edge.connectedVertices[1].index);
            }
        }

        return mst;
    }
}
