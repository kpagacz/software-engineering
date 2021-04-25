import java.util.ArrayList;
import java.util.Dictionary;
import java.util.RandomAccess;

/** Hashmap.
* Implements chains as a solution to hash conflicts.
* @param <K>
* @param <V>
*/
public class DictionaryChains<K, V> implements RandomAccess {
  public static class DictionaryElement<K, V> {
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
  public DictionaryChains() {
    currentBucketsNumber = 128;
    currentElementsNumber = 0;
    data = new ArrayList[currentBucketsNumber];
    for(int i = 0; i < currentBucketsNumber; i++) {
      data[i] = new ArrayList<DictionaryElement<K, V>>();
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
      currentElementsNumber += 1;
      if (currentElementsNumber > currentBucketsNumber * dictCoefficient) {
        rehash(growCoefficient * currentBucketsNumber);
      }
    } else {
      data[indices.first].get(indices.second).value = value;
    }
  }

  public final void delete(K key) {
    Pair<Integer, Integer> indices = findIndex(key);
    if (indices.second != -1) {
      data[indices.first].remove(indices.second);
      --currentElementsNumber;
      if(currentBucketsNumber > 1 && growCoefficient * growCoefficient * currentElementsNumber < currentBucketsNumber * dictCoefficient) {
        rehash(currentBucketsNumber / growCoefficient);
      }
    }
  }

  public final int size() {
    return currentElementsNumber;
  }

  public final ArrayList<K> getKeys() {
    ArrayList<K> keys = new ArrayList<>();
    for(ArrayList<DictionaryElement<K, V>> chain : data) {
      for(DictionaryElement<K, V> element : chain) {
        keys.add(element.key);
      }
    }

    return keys;
  }

  @Override
  public final String toString() {
    StringBuilder buffer = new StringBuilder();
    for(ArrayList<DictionaryElement<K, V>> chain : data) {
      for(DictionaryElement<K, V> element : chain) {
        buffer.append("(" + element.key + " : " + element.value + ") ");
      }
    }

    return buffer.toString();
  }

  // Private methods
  private int hash(K key) {
    return Math.floorMod(key.hashCode(), currentBucketsNumber);
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
      if (key(element).equals(key)) {
        return new Pair<>(hash(key), i);
      }
    }
    return new Pair<>(hash(key), -1);
  }

  private void rehash(int newSize) {
    currentBucketsNumber = newSize;

    // initialize the new container for the data
    ArrayList<DictionaryElement<K, V>>[] newData = new ArrayList[currentBucketsNumber];
    for(int i = 0; i < currentBucketsNumber; i++) {
      newData[i] = new ArrayList<DictionaryElement<K, V>>();
    }

    // fill up the new container
    for(ArrayList<DictionaryElement<K, V>> list : data) {
      for(DictionaryElement<K, V> element : list) {
        newData[hash(key(element))].add(element);
      }
    }

    data = newData;
  }
}
