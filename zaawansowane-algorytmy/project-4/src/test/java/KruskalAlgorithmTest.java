import org.junit.jupiter.api.Test;

import java.util.ArrayList;

class KruskalAlgorithmTest {
    @Test
    void getMst() {
        Vertex vertex0 = new Vertex(0);
        Vertex vertex1 = new Vertex(1);
        Vertex vertex2 = new Vertex(2);
        Vertex vertex3 = new Vertex(3);
        Vertex vertex4 = new Vertex(4);
        Edge edge0 = new Edge(vertex0, vertex1, 4);
        Edge edge1 = new Edge(vertex0, vertex2, 4);
        Edge edge2 = new Edge(vertex0, vertex3, 6);
        Edge edge3 = new Edge(vertex0, vertex4, 6);
        Edge edge4 = new Edge(vertex1, vertex2, 2);
        Edge edge5 = new Edge(vertex2, vertex3, 8);
        Edge edge6 = new Edge(vertex3, vertex4, 9);
        vertex0.addEdge(edge0);
        vertex0.addEdge(edge1);
        vertex0.addEdge(edge2);
        vertex0.addEdge(edge3);
        vertex1.addEdge(edge4);
        vertex1.addEdge(edge0);
        vertex2.addEdge(edge1);
        vertex2.addEdge(edge4);
        vertex2.addEdge(edge5);
        vertex3.addEdge(edge2);
        vertex3.addEdge(edge5);
        vertex3.addEdge(edge6);
        vertex4.addEdge(edge3);
        vertex4.addEdge(edge6);

        UndirectedGraph graph = new UndirectedGraph();
        graph.addVertex(vertex0);
        graph.addVertex(vertex1);
        graph.addVertex(vertex2);
        graph.addVertex(vertex3);
        graph.addVertex(vertex4);

        ArrayList<Edge> mst = KruskalAlgorithm.getMst(graph);
        UndirectedGraph.printEdges(mst);
    }
}