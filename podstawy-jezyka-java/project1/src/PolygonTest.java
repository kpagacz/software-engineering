import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PolygonTest {
  @Test
  @DisplayName("Passing a complex polygon to fromString throws")
  void fromStringComplexPolygonException() {
    assertThrows(FigureParseException.class, () -> Polygon.fromString("(0,0) (1,1) (0,1) (1,0)"));
    assertThrows(FigureParseException.class, () -> Polygon.fromString("(0,0) (1,0) (0,1) (1,1)"));
  }

}
