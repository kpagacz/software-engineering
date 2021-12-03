import java.util.ArrayList;
import java.util.logging.Logger;

public class Trapezoid extends Quadrangle {
  // Fields
  private static final Logger logger;

  static {
    logger = Logger.getLogger("Main.Trapezoid");
  }
  // Constructors
  public Trapezoid(ArrayList<Vertex> vertices) throws ImpossiblePolygonException {
    super(vertices);
  }

  // Public methods
  @Override
  Logger getLogger() {
    return logger;
  }

  public static boolean areSegmentsParallel(Vertex s11, Vertex s12, Vertex s21, Vertex s22) {
    double precision = 1E-15;
    if ((s11.y - s12.y) == 0 && (s21.y - s22.y) == 0) {
      return true;
    } else if ((s11.y - s12.y) == 0 || (s21.y - s22.y) == 0) {
      return false;
    } else {
      return Math.abs((s11.x - s12.x) / (s11.y - s12.y) - (s21.x - s22.x) / (s21.y - s22.y))
          < precision;
    }
  }

  public static boolean isTrapezoid(ArrayList<Vertex> vertices) {
    if (vertices.size() != 4) return false;

    return areSegmentsParallel(vertices.get(0), vertices.get(1), vertices.get(2), vertices.get(3))
        || areSegmentsParallel(vertices.get(1), vertices.get(2), vertices.get(3), vertices.get(0));
  }
}
