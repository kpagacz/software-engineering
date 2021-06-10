public class Edge {
    final int weight;
    final Vertex[] connectedVertices;

    public Edge(Vertex firstVertex, Vertex secondVertex, int weight) {
        connectedVertices = new Vertex[2];
        connectedVertices[0] = firstVertex;
        connectedVertices[1] = secondVertex;
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
