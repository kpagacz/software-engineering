import org.junit.jupiter.api.Test;

class MinHeapTest {
    MinHeap<Edge> heap;
    @Test
    void testCreatingHeap() {
        heap = new MinHeap<>(Edge.class, 5);
        heap.insert(new Edge(null, null, 0));
        heap.insert(new Edge(null, null, -2));
        heap.insert(new Edge(null, null, 3));
        System.out.println(heap.toString());

        heap.pop();
        System.out.println(heap.toString());
    }
}