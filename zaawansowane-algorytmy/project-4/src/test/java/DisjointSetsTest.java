import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class DisjointSetsTest {
    DisjointSets disjointSets;
    @BeforeEach
    void setUp() {
        disjointSets = new DisjointSets(4);
    }

    @Test
    void newlyInitializedElementsAreTheirOwnSets() {
        for(int i = 0; i < 4; i++) {
            assertEquals(disjointSets.elements[i], disjointSets.find(i));
        }
    }

    @Test
    void unionOfTwoElements() {
        disjointSets.union(0, 1);
        assertEquals(disjointSets.find(0), disjointSets.find(1));
    }

    @Test
    void unionOfTwoElementsSecondHasHigherRank() {
        disjointSets.union(0, 1);
        disjointSets.union(3, 1);
        assertEquals(disjointSets.find(0), disjointSets.find(3));
    }
}