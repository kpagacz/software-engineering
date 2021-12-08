import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.logging.LogManager;

import static org.junit.jupiter.api.Assertions.*;

class FigureTest {
  @BeforeAll
  static void setUp() {
    LogManager.getLogManager().reset();
  }

  @Test
  @DisplayName("fromString returns a circle for a single vertex input and radius")
  void fromStringReturnsCircle() throws FigureParseException {
    Figure fig = Figure.fromString("(0,0) 1");
    assertTrue(fig instanceof Circle);
  }

  @Test
  @DisplayName("fromString returns a quadrangle from 4 vertices")
  void fromStringReturnsQuadrangle() throws FigureParseException {
    Figure fig = Figure.fromString("(0,0) (1,0) (1,1) (0,1)");
    assertTrue(fig instanceof Quadrangle);
  }

  @Test
  @DisplayName("fromString throws if passed a single vertex or two vertices")
  void fromStringThrowsWhenTooFewVertices() {
    assertThrows(FigureParseException.class, () -> Figure.fromString("(0,0)"));
    assertThrows(FigureParseException.class, () -> Figure.fromString("(0,0) (1,1)"));
  }

  @Test
  @DisplayName("getArea returns an area for a simple polygon")
  void getAreaSimplePolygon() throws FigureParseException {
    Figure fig = Figure.fromString("(0,0) (0,2) (2,2) (2,0)");
    assertEquals(4, fig.getArea());
  }

  @Test
  @DisplayName("getPerimeter returns perimeter for a simple polygon")
  void getPerimeterSimplePolygon() throws FigureParseException {
    Figure fig = Figure.fromString("(0,0) (0,2) (2,2) (2,0)");
    assertEquals(8, fig.getPerimeter());
  }

  @Test
  @DisplayName("fromString parses negative coordinates")
  void fromStringNegativeCoordinates() throws FigureParseException {
    assertDoesNotThrow(() -> Figure.fromString("(-1,-1) 1"));
  }
}
