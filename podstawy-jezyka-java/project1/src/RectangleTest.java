import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class RectangleTest {

  @Test
  void isOrthogonal() {
    assertTrue(Rectangle.isOrthogonal(new Vertex(0, 1), new Vertex(0, 0), new Vertex(1, 0)));
    assertFalse(Rectangle.isOrthogonal(new Vertex(0, 1), new Vertex(0, 0), new Vertex(1, 1)));
  }

  @Test
  void isRectangle() {
    ArrayList<Vertex> vertices =
        new ArrayList<>(
            List.of(new Vertex(0, 0), new Vertex(2, 0), new Vertex(2, 1), new Vertex(0, 1)));
    assertTrue(Rectangle.isRectangle(vertices));
    vertices =
        new ArrayList<>(
            List.of(new Vertex(0, 0), new Vertex(2, 0), new Vertex(2, 1), new Vertex(0, 2)));
    assertFalse(Rectangle.isRectangle(vertices));

    vertices = new ArrayList<>(List.of(new Vertex(0, 0), new Vertex(2, 0), new Vertex(2, 1)));
    assertFalse(Rectangle.isRectangle(vertices));
  }
}
