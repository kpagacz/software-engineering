package project;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

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
}