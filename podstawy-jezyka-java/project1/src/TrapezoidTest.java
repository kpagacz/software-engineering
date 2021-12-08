import org.junit.jupiter.api.Test;

import javax.swing.*;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class TrapezoidTest {

  @Test
  void areSegmentsParallel() {
    Vertex s11 = new Vertex(0, 0);
    Vertex s12 = new Vertex(0, 1);
    Vertex s21 = new Vertex(1, 0);
    Vertex s22 = new Vertex(1, 2);
    assertTrue(Trapezoid.areSegmentsParallel(s11, s12, s21, s22));

    s22 = new Vertex(2, 2);
    assertFalse(Trapezoid.areSegmentsParallel(s11, s12, s21, s22));
  }

  @Test
  void isTrapezoid() {
    ArrayList<Vertex> vertices =
        new ArrayList<>(
            List.of(new Vertex(0, 0), new Vertex(3, 0), new Vertex(2, 1), new Vertex(0, 1)));
    assertTrue(Trapezoid.isTrapezoid(vertices));

    vertices =
        new ArrayList<>(
            List.of(new Vertex(0, 0), new Vertex(1, 1), new Vertex(1, 1), new Vertex(2, 2)));
    assertTrue(Trapezoid.isTrapezoid(vertices));

    vertices =
        new ArrayList<>(
            List.of(new Vertex(0, 0), new Vertex(1, 0), new Vertex(1, 1), new Vertex(2, 2)));
    assertFalse(Trapezoid.isTrapezoid(vertices));
  }

  @Test
  void constructor() {
    ArrayList<Vertex> vertices =
        new ArrayList<>(
            List.of(new Vertex(0, 0), new Vertex(3, 0), new Vertex(2, 1), new Vertex(0, 1)));
    assertDoesNotThrow(() -> new Trapezoid(vertices));
  }
}
