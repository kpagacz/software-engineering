import java.util.ArrayList;

public abstract class DictionaryLinear<K, V> {
  private static class DictionaryElement<K, V> {
    public K key;
    public V value;

    DictionaryElement(K key, V value) {
      this.key = key;
      this.value = value;
    }

    DictionaryElement() {
      this.key = null;
      this.value = null;
    }
  }
  private record Pair<First, Second>(First first, Second second) { }
  private ArrayList<DictionaryElement<K, V>>[] data;
  private int currentBucketsNumber;

  // Constructors
  public DictionaryLinear() {
    int initialBucketsNumber = 128;
    currentBucketsNumber = initialBucketsNumber;
    data = new ArrayList[initialBucketsNumber];
    for(ArrayList<DictionaryElement<K, V>> list : data) {
      list = new ArrayList<DictionaryElement<K, V>>();
    }
  }

  // Public interface
  public V find(K key) {
    Pair<Integer, Integer> indices = findIndex(key);
    if(indices.second == -1) {
      return null;
    } else {
      return value(data[indices.first].get(indices.second));
    }
  }

  public final void insert(K key, V value) {}

  public final void delete(K key) {}

  @Override
  public final String toString() {
    return "";
  }

  // Private methods
  private int hash(K key) {
    return key.hashCode() % currentBucketsNumber;
  }

  private K key(DictionaryElement<K, V> element) {
    return element.key;
  }

  private V value(DictionaryElement<K, V> element) {
    return element.value;
  }

  private Pair<Integer, Integer> findIndex(K key) {
    for(int i = 0; i < data[hash(key)].size(); i++) {
      DictionaryElement<K, V> element = data[hash(key)].get(i);
      if (key(element) == key) {
        return new Pair<>(hash(key), i);
      }
    }
    return new Pair<>(hash(key), -1);
  }
}
