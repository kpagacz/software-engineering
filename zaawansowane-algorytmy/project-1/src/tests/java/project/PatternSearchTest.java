package project;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.assertEquals;

class PatternSearchTest {
    private PatternSearch search;

    @BeforeEach
    void setUp() throws Exception {
        search = new PatternSearch();
    }

    @Test
    void naiveSearch() {
        assertEquals(Arrays.asList(0), search.naiveSearch("can", "canoe"));
        assertEquals(Arrays.asList(2), search.naiveSearch("noe", "canoe"));
        assertEquals(Arrays.asList(0, 3), search.naiveSearch("ba", "baobab"));
        assertEquals(Arrays.asList(), search.naiveSearch("ba", "ca"));
        assertEquals(Arrays.asList(0,1,2), search.naiveSearch("a", "aaa"));
        assertEquals(Arrays.asList(), search.naiveSearch("aa", "a"));
        assertEquals(Arrays.asList(), search.naiveSearch("aa", ""));
        // assertEquals(Arrays.asList(), search.naiveSearch("", "a"));
    }

    @Test
    void sundaySearch() {
        assertEquals(Arrays.asList(0), search.sundaySearch("can", "canoe"));
        assertEquals(Arrays.asList(2), search.sundaySearch("noe", "canoe"));
        assertEquals(Arrays.asList(0, 3), search.sundaySearch("ba", "baobab"));
        assertEquals(Arrays.asList(), search.sundaySearch("ba", "ca"));
        assertEquals(Arrays.asList(0,1,2), search.sundaySearch("a", "aaa"));
        assertEquals(Arrays.asList(), search.sundaySearch("aa", "a"));
        assertEquals(Arrays.asList(), search.sundaySearch("aa", ""));
    }

    @Test
    void mpSearch() {
        assertEquals(Arrays.asList(0), search.mpSearch("can", "canoe"));
        assertEquals(Arrays.asList(2), search.mpSearch("noe", "canoe"));
        assertEquals(Arrays.asList(0, 3), search.mpSearch("ba", "baobab"));
        assertEquals(Arrays.asList(), search.mpSearch("ba", "ca"));
        assertEquals(Arrays.asList(0,1,2), search.mpSearch("a", "aaa"));
        assertEquals(Arrays.asList(), search.mpSearch("aa", "a"));
        assertEquals(Arrays.asList(), search.mpSearch("aa", ""));
        assertEquals(Arrays.asList(), search.mpSearch("abcdabcdabx", ""));
    }

    @Test
    void kmpSearch() {
        assertEquals(Arrays.asList(0), search.kmpSearch("can", "canoe"));
        assertEquals(Arrays.asList(2), search.kmpSearch("noe", "canoe"));
        assertEquals(Arrays.asList(0, 3), search.kmpSearch("ba", "baobab"));
        assertEquals(Arrays.asList(), search.kmpSearch("ba", "ca"));
        assertEquals(Arrays.asList(0,1,2), search.kmpSearch("a", "aaa"));
        assertEquals(Arrays.asList(), search.kmpSearch("aa", "a"));
        assertEquals(Arrays.asList(), search.kmpSearch("aa", ""));
        assertEquals(Arrays.asList(), search.kmpSearch("abcdabcdabx", ""));
        assertEquals(Arrays.asList(9), search.kmpSearch("abcabcd", "abcdabcacabcabcde"));
        assertEquals(Arrays.asList(0,1,2,3), search.kmpSearch("a", "aaaa"));
        assertEquals(Arrays.asList(2), search.kmpSearch("a", "bba"));
    }
}