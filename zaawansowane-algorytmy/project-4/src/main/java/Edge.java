public class Edge {
    int weight;
    Node[] connectedNodes;

    public Edge(Node firstNode, Node secondNode, int weight) {
        connectedNodes = new Node[2];
        connectedNodes[0] = firstNode;
        connectedNodes[1] = secondNode;
        this.weight = weight;
    }

    /**
     * @param firstEdge
     * @param secondEdge
     * @return -1 if firstEdge has smaller weight than secondEdge; 0 if weights are equal; 1 if firstEdge has
     * bigger weight than secondEdge
     */
    public static int compareEdges(Edge firstEdge, Edge secondEdge) {
        return Integer.compare(firstEdge.weight, secondEdge.weight);
    }
}
