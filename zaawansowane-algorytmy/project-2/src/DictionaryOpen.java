/** Hash map.
 *
 * Implements open addressing as a tool for solving conflicts.
 * Supports double hashing, deleting elements with a shift and Robin-Hood hashing.
 *
 * @param <K> the type of keys
 * @param <V> the type of values
 */
public class DictionaryOpen<K, V> {
  private static class DictionaryElement<K, V> {
    public K key;
    public V value;
    public boolean isEmpty;

    DictionaryElement(K key, V value) {
      this.key = key;
      this.value = value;
      isEmpty = false;
    }

    DictionaryElement() {
      this.key = null;
      this.value = null;
      isEmpty = true;
    }
  }

  private DictionaryElement<K, V>[] data;
  private int dictCapacity = 128;
  private int dictSize = 0;
  private int dictCoefficientNominator = 7;
  private int dictCoefficientDenominator = 10;
  private int growCoefficient = 2;

  // Public methods
  DictionaryOpen() {
    data = new DictionaryElement[dictCapacity];
    for(int i = 0; i < dictCapacity; i++) {
      data[i] = new DictionaryElement<K, V>();
    }
  }

  public void insert(K key, V value) {
    int index = scanFor(key);
    if (data[index].isEmpty) {
      data[index] =  new DictionaryElement<K, V>(key, value);
      dictSize += 1;
      if (dictSize * dictCoefficientDenominator > dictCapacity * dictCoefficientNominator) {
        rehash(growCoefficient * dictCapacity);
      }
    } else {
      data[index] = new DictionaryElement<K, V>(key, value);
    }
  }

  public void delete(K key) {
    int originalIndex = scanFor(key);
    int distanceToNextIndex = delta(key);
    if (!data[originalIndex].isEmpty) {
      int previousIndex = originalIndex;
      int nextIndex = (originalIndex + distanceToNextIndex) % dictCapacity;
      while(nextIndex != originalIndex && !data[nextIndex].isEmpty) {
        data[previousIndex] = data[nextIndex];
        data[nextIndex] = new DictionaryElement<>();
        previousIndex = nextIndex;
        nextIndex = (originalIndex + distanceToNextIndex) % dictCapacity;
      }

      dictSize -= 1;
      if (dictCapacity > 1
          && dictSize * growCoefficient * growCoefficient * dictCoefficientDenominator
              < dictCapacity * dictCoefficientNominator) {
        rehash(dictCapacity / growCoefficient);
      }
    }
  }

  public V find(K key) {
    int index = scanFor(key);
    if(!data[index].isEmpty) {
      return value(data[index]);
    } else {
      return null;
    }
  }

  public int size() {
    return dictSize;
  }

  // Private methods
  private int hash(K key) {
    return Math.floorMod(key.hashCode(), dictCapacity);
  }

  private int delta(K key) {
    return 2 * Math.floorMod(key.hashCode(), 17) + 1;
  }

  private K key(DictionaryElement<K, V> element) {
    return element.key;
  }

  private V value(DictionaryElement<K, V> element) {
    return element.value;
  }

  private int scanFor(K key) {
    int firstIndex = hash(key);
    int distanceToNextIndex = delta(key);
    int currentIndex = firstIndex;

    while(firstIndex != currentIndex && !key(data[currentIndex]).equals(key) && !data[currentIndex].isEmpty) {
      currentIndex = (currentIndex + distanceToNextIndex) % dictCapacity;
    }

    return currentIndex;
  }

  private void rehash(int newCapacity) {
    DictionaryElement<K, V>[] newData = new DictionaryElement[newCapacity];
    for(int i = 0; i < newCapacity; i++) {
      newData[i] = new DictionaryElement<>();
    }
    int oldCapacity = dictCapacity;
    dictCapacity = newCapacity;
    for (int i = 0; i < oldCapacity; i++) {
      if (!data[i].isEmpty) {
        DictionaryElement<K, V> copiedElement =
                new DictionaryElement<K, V>(key(data[i]), value(data[i]));
        int currentIndex = hash(key(copiedElement));
        int distanceToNextIndex = delta(key(copiedElement));
        while (!newData[currentIndex].isEmpty) {
          currentIndex = (currentIndex + distanceToNextIndex) % dictCapacity;
        }
        newData[currentIndex] = copiedElement;
      }
    }
    this.data = newData;
  }
}
