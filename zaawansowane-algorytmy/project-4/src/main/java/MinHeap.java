import java.lang.reflect.Array;
import java.util.List;

public class MinHeap<T extends Edge> {
  private final int heapCapacity;
  private int heapSize;
  private T[] array;

  public MinHeap(Class<T> tClass, int heapCapacity) {
    this.heapCapacity = heapCapacity;
    array = (T[]) Array.newInstance(tClass, heapCapacity);
  }

  public MinHeap(Class<T> tClass, List<T> array) {
    this.heapCapacity = array.size();
    this.array = (T[]) array.toArray();
    minHeap();
  }

  private int parent(int pos) {
    return (pos - 1) / 2;
  }

  private int leftChild(int pos) {
    return 2 * pos + 1;
  }

  private int rightChild(int pos) {
    return 2 * pos + 2;
  }

  private boolean hasChildren(int pos) {
    return (pos >= 0) && (2 * pos + 1 < heapSize);
  }

  private void swapEdges(int firstNode, int secondNode) {
    T tmp = array[firstNode];
    array[firstNode] = array[secondNode];
    array[secondNode] = tmp;
  }

  private void minHeapify(int pos) {
    if (!hasChildren(pos)) return;
    if (Edge.compareEdges(array[pos], array[leftChild(pos)]) == 1
        || (array[rightChild(pos)] != null
            && Edge.compareEdges(array[pos], array[rightChild(pos)]) == 1)) {
      if (array[rightChild(pos)] == null
          || Edge.compareEdges(array[leftChild(pos)], array[rightChild(pos)]) <= 0) {
        swapEdges(pos, leftChild(pos));
        minHeapify(leftChild(pos));
      } else {
        swapEdges(pos, rightChild(pos));
        minHeapify(rightChild(pos));
      }
    }
  }

  public void insert(T edge) {
    if (heapSize >= heapCapacity) {
      return;
    }

    array[heapSize] = edge;
    int it = heapSize++;
    while (Edge.compareEdges(array[it], array[parent(it)]) < 0) {
      swapEdges(it, parent(it));
      it = parent(it);
    }
  }

  public T pop() {
    T removedEdge = array[0];
    array[0] = array[--heapSize];
    array[heapSize] = null;
    minHeapify(0);
    return removedEdge;
  }

  private void minHeap() {
    for (int pos = (heapSize / 2); pos >= 0; pos--) {
      minHeapify(pos);
    }
  }

  @Override
  public String toString() {
    StringBuilder out = new StringBuilder();
    for(int i = 0; i < heapSize; i++) {
      out.append(array[i].weight).append(" ");
    }
    return out.toString();
  }
}
