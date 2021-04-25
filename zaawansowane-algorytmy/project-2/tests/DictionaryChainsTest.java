import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;
import static org.junit.jupiter.api.Assertions.assertEquals;

class DictionaryChainsTest {
  @Test
  void testConstructor1() {
    assertDoesNotThrow(() -> new DictionaryChains<String, Integer>());
  }

  @Test
  void testInsertingNoRehash() {
    DictionaryChains<String, Integer> dict = new DictionaryChains<>();
    for (int i = 0; i < 100; i++) {
      dict.insert("Key" + i, i);
    }
    assertEquals(100, dict.size());
  }

  @Test
  void testInsertingWithGrow() {
    assertDoesNotThrow(
        () -> {
          DictionaryChains<String, Integer> dict = new DictionaryChains<>();
          for (int i = 0; i < 128 * 8; i++) {
            dict.insert("Key" + i, i);
          }
        });
  }

  @Test
  void testDeleteWithNoRehash() {
    DictionaryChains<String, Integer> dict = new DictionaryChains<>();
    for (int i = 0; i < 128; i++) {
      dict.insert("testKey" + i, i);
    }
    assertEquals(128, dict.size());
    assertDoesNotThrow(() -> dict.delete("testKey0"));
    assertEquals(127, dict.size());
  }

  @Test
  void testDeleteWithRehash() {
    DictionaryChains<String, Integer> dict = new DictionaryChains<>();
    for (int i = 0; i < 8; i++) {
      dict.insert("testKey" + i, i);
    }
    assertEquals(8, dict.size());
    assertDoesNotThrow(() -> dict.delete("testKey0"));
    assertEquals(7, dict.size());
  }
}
