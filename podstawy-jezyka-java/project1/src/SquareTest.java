import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class SquareTest {

  @Test
  void isSquare() {
    ArrayList<Vertex> vertices =
        new ArrayList<>(
            List.of(new Vertex(0, 0), new Vertex(1, 0), new Vertex(1, 1), new Vertex(0, 1)));
    assertTrue(Square.isSquare(vertices));

    vertices =
        new ArrayList<>(
            List.of(new Vertex(0, 0), new Vertex(2, 0), new Vertex(2, 1), new Vertex(0, 1)));
    assertFalse(Square.isSquare(vertices));
  }

  @Test
  void constructor() {
    ArrayList<Vertex> vertices =
        new ArrayList<>(
            List.of(new Vertex(0, 0), new Vertex(1, 0), new Vertex(1, 1), new Vertex(0, 1)));
    assertDoesNotThrow(() -> new Square(vertices));
  }
}
