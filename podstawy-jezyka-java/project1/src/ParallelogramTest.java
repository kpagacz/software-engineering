import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class ParallelogramTest {

  @Test
  void isParallelogram() {
    ArrayList<Vertex> vertices =
        new ArrayList<>(
            List.of(new Vertex(0, 0), new Vertex(1, 1), new Vertex(3, 1), new Vertex(2, 0)));
    assertTrue(Parallelogram.isParallelogram(vertices));
  }
}
