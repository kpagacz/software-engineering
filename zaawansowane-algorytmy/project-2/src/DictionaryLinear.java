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
  private int currentElementsNumber;
  private int dictCoefficient = 4;
  private int growCoefficient = 2;

  // Constructors
  public DictionaryLinear() {
    currentBucketsNumber = 128;
    currentElementsNumber = 0;
    data = new ArrayList[currentBucketsNumber];
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

  public final void insert(K key, V value) {
    Pair<Integer, Integer> indices = findIndex(key);
    if(indices.second == -1) {
      data[indices.first].add(new DictionaryElement<>(key, value));
      ++currentElementsNumber;
      if (currentElementsNumber > currentBucketsNumber * dictCoefficient) {
        rehash(growCoefficient * currentBucketsNumber);
      }
    } else {
      data[indices.first].get(indices.second).value = value;
    }
  }

  public final void delete(K key) {}

  public final int size() {
    return currentElementsNumber;
  }

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

  private void rehash(int newSize) {
    currentBucketsNumber = newSize;
    ArrayList<DictionaryElement<K, V>>[] newData = new ArrayList[currentBucketsNumber];
    for(ArrayList<DictionaryElement<K, V>> list : newData) {
      list = new ArrayList<DictionaryElement<K, V>>();
    }

    for(ArrayList<DictionaryElement<K, V>> list : data) {
      for(DictionaryElement<K, V> element : list) {
        newData[hash(key(element))].add(element);
      }
    }

    data = newData;
  }
}
