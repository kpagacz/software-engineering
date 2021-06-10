import java.util.ArrayList;

public class PrimAlgorithm {
  public static ArrayList<Edge> getMst(UndirectedGraph graph) {
    if (graph.nodes.size() == 0) {
      return new ArrayList<>();
    }
    ArrayList<Edge> mst = new ArrayList<>();

    // Add the first node of the graph to mst
    boolean[] isInMst = new boolean[graph.getNodesNumber()];
    isInMst[graph.nodes.get(0).index] = true;
    int nodesInMst = 1; // counter of number of nodes in mst

    // Add edges coming from the first node of the graph to the heap
    MinHeap<Edge> edgesHeap = new MinHeap<>(Edge.class, graph.getNodesNumber());
    for (Edge edge : graph.nodes.get(0).edges) {
      edgesHeap.insert(edge);
    }

    while (nodesInMst < graph.getNodesNumber()) {
      Edge newEdge = edgesHeap.pop();

      // If nodes of the edge are already in the mst - do not do anything
      if (isInMst[newEdge.connectedNodes[0].index] && isInMst[newEdge.connectedNodes[1].index]) {
        continue;
      }

      // Nodes are not in the mst - add the edge to the mst and update the heap
      Node newNode;
      if (isInMst[newEdge.connectedNodes[0].index]) {
        newNode = newEdge.connectedNodes[1];
      } else {
        newNode = newEdge.connectedNodes[0];
      }

      for (Edge edge : newNode.edges) {
        if (!edge.equals(newEdge)) {
          edgesHeap.insert(edge);
        }
      }

      mst.add(newEdge);
      isInMst[newNode.index] = true;
      nodesInMst++;
    }

    return mst;
  }
}
