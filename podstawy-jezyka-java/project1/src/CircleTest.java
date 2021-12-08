import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.logging.LogManager;

import static org.junit.jupiter.api.Assertions.*;

class CircleTest {
  @BeforeAll
  static void setUp() {
    LogManager.getLogManager().reset();
  }

  @Test
  void testFromString() {
    assertDoesNotThrow(() -> Circle.fromString("(0,0) 1"));
  }

  @Test
  @DisplayName("fromString throws when radius is negative")
  void testFromStringThrows() throws FigureParseException {
    assertThrows(FigureParseException.class, ()-> Circle.fromString("(0,0) -1"));
  }

  @Test
  @DisplayName("fromString throws when there are more vertices than one")
  void testFromStringThrowsForMoreVertices() {
    assertThrows(FigureParseException.class, () -> Circle.fromString("(0,0) (0,1) 1"));
  }

  @Test
  @DisplayName("isCircle returns true for one vertex and radius")
  void isCircleTest() {
    assertTrue(Circle.isCircle("(0,0) 1"));
  }
}
