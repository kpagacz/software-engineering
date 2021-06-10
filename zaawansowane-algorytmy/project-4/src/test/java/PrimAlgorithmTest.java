import org.junit.jupiter.api.Test;

import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.*;

class PrimAlgorithmTest {

    @Test
    void getMst() {
        Node node0 = new Node(0);
        Node node1 = new Node(1);
        Node node2 = new Node(2);
        Node node3 = new Node(3);
        Node node4 = new Node(4);
        Edge edge0 = new Edge(node0, node1, 4);
        Edge edge1 = new Edge(node0, node2, 4);
        Edge edge2 = new Edge(node0, node3, 6);
        Edge edge3 = new Edge(node0, node4, 6);
        Edge edge4 = new Edge(node1, node2, 2);
        Edge edge5 = new Edge(node2, node3, 8);
        Edge edge6 = new Edge(node3, node4, 9);
        node0.addEdge(edge0);
        node0.addEdge(edge1);
        node0.addEdge(edge2);
        node0.addEdge(edge3);
        node1.addEdge(edge4);
        node1.addEdge(edge0);
        node2.addEdge(edge1);
        node2.addEdge(edge4);
        node2.addEdge(edge5);
        node3.addEdge(edge2);
        node3.addEdge(edge5);
        node3.addEdge(edge6);
        node4.addEdge(edge3);
        node4.addEdge(edge6);

        UndirectedGraph graph = new UndirectedGraph();
        graph.addNode(node0);
        graph.addNode(node1);
        graph.addNode(node2);
        graph.addNode(node3);
        graph.addNode(node4);

        ArrayList<Edge> mst = PrimAlgorithm.getMst(graph);
        UndirectedGraph.printEdges(mst);
    }
}