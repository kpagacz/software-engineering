import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class TriangleTest {
    @Test
    void testConstructor() {
        ArrayList<Vertex> goodVertices = new ArrayList<>(List.of(new Vertex(0, 0), new Vertex(1, 1), new Vertex(1, 0)));
        assertDoesNotThrow(() -> new Triangle(goodVertices));
    }

    @Test
    @DisplayName("Constructor throws when vertices are collinear")
    void testConstructorThrows() {
        ArrayList<Vertex> collinearVertices = new ArrayList<>(List.of(new Vertex(0, 0), new Vertex(1, 1), new Vertex(2, 2)));
        assertThrows(ImpossiblePolygonException.class, () -> new Triangle(collinearVertices));
    }
}