import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class VertexTest {
    @Test
    @DisplayName("Constructor does not throw when passed two doubles")
    void constructorDoesNotThrowForDoubles() {
        assertDoesNotThrow(()-> new Vertex(0.0, 0.0));
    }

    @Test
    @DisplayName("Constructor does not throw for two integers")
    void constructorDoesNotThrowForIntegers() {
        assertDoesNotThrow(() -> new Vertex(0, 0));
    }

    @Test
    @DisplayName("Constructor does not throw when passed a vertex via (0,0)")
    void constructorDoesNotThrowForValidVertex() {
        assertDoesNotThrow(()-> new Vertex("(0,0)"));
    }

    @Test
    @DisplayName("Constructor does not throw when passed a vertex of doubles")
    void constructorDoesNotThrowForVertexOfDoubles() {
        assertDoesNotThrow(() -> new Vertex("(0.0,0.0)"));
    }

    @Test
    @DisplayName("Constructor throws when any bracket is missing or when passed additional blank characters")
    void constructorThrowsWhenPassedInvalidVertex() {
        assertThrows(VertexParseException.class, ()-> new Vertex("(0,0"));
        assertThrows(VertexParseException.class, ()-> new Vertex("0,0)"));
        assertThrows(VertexParseException.class, ()-> new Vertex("0,0"));
        assertThrows(VertexParseException.class, ()-> new Vertex("(0 ,0)"));
        assertThrows(VertexParseException.class, ()-> new Vertex("(0, 0"));
    }
}