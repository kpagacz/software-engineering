package project;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.regex.Pattern;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

class PatternSearchTest {
    @Test
    void naiveSearch() {
        assertEquals(Arrays.asList(0), PatternSearch.naiveSearch("can", "canoe"));
        assertEquals(Arrays.asList(2), PatternSearch.naiveSearch("noe", "canoe"));
        assertEquals(Arrays.asList(0, 3), PatternSearch.naiveSearch("ba", "baobab"));
        assertEquals(Arrays.asList(), PatternSearch.naiveSearch("ba", "ca"));
        assertEquals(Arrays.asList(0,1,2), PatternSearch.naiveSearch("a", "aaa"));
        assertEquals(Arrays.asList(), PatternSearch.naiveSearch("aa", "a"));
        assertEquals(Arrays.asList(), PatternSearch.naiveSearch("aa", ""));
        // assertEquals(Arrays.asList(), search.naiveSearch("", "a"));
    }

    @Test
    void sundaySearch() {
        assertEquals(Arrays.asList(0), PatternSearch.sundaySearch("can", "canoe"));
        assertEquals(Arrays.asList(2), PatternSearch.sundaySearch("noe", "canoe"));
        assertEquals(Arrays.asList(0, 3), PatternSearch.sundaySearch("ba", "baobab"));
        assertEquals(Arrays.asList(), PatternSearch.sundaySearch("ba", "ca"));
        assertEquals(Arrays.asList(0,1,2), PatternSearch.sundaySearch("a", "aaa"));
        assertEquals(Arrays.asList(), PatternSearch.sundaySearch("aa", "a"));
        assertEquals(Arrays.asList(), PatternSearch.sundaySearch("aa", ""));
    }

    @Test
    void mpSearch() {
        assertEquals(Arrays.asList(0), PatternSearch.mpSearch("can", "canoe"));
        assertEquals(Arrays.asList(2), PatternSearch.mpSearch("noe", "canoe"));
        assertEquals(Arrays.asList(0, 3), PatternSearch.mpSearch("ba", "baobab"));
        assertEquals(Arrays.asList(), PatternSearch.mpSearch("ba", "ca"));
        assertEquals(Arrays.asList(0,1,2), PatternSearch.mpSearch("a", "aaa"));
        assertEquals(Arrays.asList(), PatternSearch.mpSearch("aa", "a"));
        assertEquals(Arrays.asList(), PatternSearch.mpSearch("aa", ""));
        assertEquals(Arrays.asList(), PatternSearch.mpSearch("abcdabcdabx", ""));
    }

    @Test
    void kmpSearch() {
        assertEquals(Arrays.asList(0), PatternSearch.kmpSearch("can", "canoe"));
        assertEquals(Arrays.asList(2), PatternSearch.kmpSearch("noe", "canoe"));
        assertEquals(Arrays.asList(0, 3), PatternSearch.kmpSearch("ba", "baobab"));
        assertEquals(Arrays.asList(), PatternSearch.kmpSearch("ba", "ca"));
        assertEquals(Arrays.asList(0,1,2), PatternSearch.kmpSearch("a", "aaa"));
        assertEquals(Arrays.asList(), PatternSearch.kmpSearch("aa", "a"));
        assertEquals(Arrays.asList(), PatternSearch.kmpSearch("aa", ""));
        assertEquals(Arrays.asList(), PatternSearch.kmpSearch("abcdabcdabx", ""));
        assertEquals(Arrays.asList(9), PatternSearch.kmpSearch("abcabcd", "abcdabcacabcabcde"));
        assertEquals(Arrays.asList(0,1,2,3), PatternSearch.kmpSearch("a", "aaaa"));
        assertEquals(Arrays.asList(2), PatternSearch.kmpSearch("a", "bba"));
    }

    @Test
    void sundayPairsSearch() {
        assertThrows(RuntimeException.class, () -> { PatternSearch.sundayPairsSearch("a", "aaaaa");});
        assertEquals(Arrays.asList(0, 3), PatternSearch.sundayPairsSearch("kot", "kotkot"));
        assertEquals(Arrays.asList(0, 3), PatternSearch.sundayPairsSearch("ba", "baobab"));
        assertEquals(Arrays.asList(9), PatternSearch.sundayPairsSearch("abcabcd", "abcdabcacabcabcde"));
    }
}