import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FigureTest {

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
        assertThrows(FigureParseException.class, ()->Figure.fromString("(0,0) (1,1)"));
    }
}