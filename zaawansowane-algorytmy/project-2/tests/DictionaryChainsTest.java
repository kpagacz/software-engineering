import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Dictionary;

import static org.junit.jupiter.api.Assertions.*;

class DictionaryChainsTest {

    @BeforeEach
    void setUp() {
    }

    @Test
    void testConstructor1() {
        assertDoesNotThrow(() -> new DictionaryChains<String, Integer>());
    }
    @Test
    void testInsertingNoRehash() {
        DictionaryChains<String, Integer> dict = new DictionaryChains<>();
        for(int i = 0; i < 100; i++) {
            dict.insert("Key" + i, i);
        }
        System.out.println(dict.toString());
    }

    @Test
    void testInsertingWithGrow() {
        assertDoesNotThrow(() -> {
                    DictionaryChains<String, Integer> dict = new DictionaryChains<>();
                    for (int i = 0; i < 128 * 8; i++) {
                      dict.insert("Key" + i, i);
                    }
                });
    }

    @Test
    void testDeleteWithNoRehash() {
      DictionaryChains<String, Integer> dict = new DictionaryChains<>();
      for(int i = 0; i < 128; i++) {
        dict.insert("testKey" + i, i);
      }
      assertEquals(128, dict.size());
      assertDoesNotThrow(() -> dict.delete("testKey0"));
      assertEquals(127, dict.size());
    }

    @Test
    void testDeleteWithRehash() {
        DictionaryChains<String, Integer> dict = new DictionaryChains<>();
        for(int i = 0; i < 8; i++) {
            dict.insert("testKey" + i, i);
        }
        assertEquals(8, dict.size());
        assertDoesNotThrow(() -> dict.delete("testKey0"));
        assertEquals(7, dict.size());
    }
}