import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CircleTest {
  @Test
  void testFromString() {
    assertDoesNotThrow(() -> Circle.fromString("(0,0) 1"));
  }

  @Test
  @DisplayName("fromString throws when radius is negative")
  void testFromStringThrows() throws FigureParseException {
    assertThrows(FigureParseException.class, ()-> Circle.fromString("(0,0) -1"));
  }
}
