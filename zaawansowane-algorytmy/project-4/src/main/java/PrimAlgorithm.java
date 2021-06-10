import java.util.ArrayList;

public class PrimAlgorithm {
  /**
   * Finds edges of the minimum spanning tree given an undirected graph.
   *
   * @param graph the graph to analyze
   * @return the array of edges in the minimum spanning tree
   */
  public static ArrayList<Edge> getMst(UndirectedGraph graph) {
    if (graph.vertices.size() == 0) {
      return new ArrayList<>();
    }
    ArrayList<Edge> mst = new ArrayList<>();

    // Add the first node of the graph to mst
    boolean[] isInMst = new boolean[graph.getVerticesCount()];
    isInMst[graph.vertices.get(0).index] = true;
    int nodesInMst = 1; // counter of number of vertices in mst

    // Add edges coming from the first node of the graph to the heap
    MinHeap<Edge> edgesHeap = new MinHeap<>(Edge.class, graph.getVerticesCount());
    for (Edge edge : graph.vertices.get(0).edges) {
      edgesHeap.insert(edge);
    }

    while (nodesInMst < graph.getVerticesCount()) {
      Edge newEdge = edgesHeap.pop();

      // If vertices of the edge are already in the mst - do not do anything
      if (isInMst[newEdge.connectedVertices[0].index] && isInMst[newEdge.connectedVertices[1].index]) {
        continue;
      }

      // Nodes are not in the mst - add the edge to the mst and update the heap
      Vertex newVertex;
      if (isInMst[newEdge.connectedVertices[0].index]) {
        newVertex = newEdge.connectedVertices[1];
      } else {
        newVertex = newEdge.connectedVertices[0];
      }

      for (Edge edge : newVertex.edges) {
        if (!edge.equals(newEdge)) {
          edgesHeap.insert(edge);
        }
      }

      mst.add(newEdge);
      isInMst[newVertex.index] = true;
      nodesInMst++;
    }

    return mst;
  }
}
