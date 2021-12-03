import java.util.ArrayList;
import java.util.logging.Logger;

public class Rectangle extends Parallelogram {
  // Fields
  private static final Logger logger;

  static {
    logger = Logger.getLogger("Main.Rectangle");
  }
  // Constructors
  public Rectangle(ArrayList<Vertex> vertices) throws ImpossiblePolygonException {
    super(vertices);
  }

  // Public methods
  @Override
  Logger getLogger() {
    return logger;
  }

  /**
   * Checks whether the angle constructed from three points is a right angle.
   *
   * @param v1 the first vertex
   * @param v2 the second vertex
   * @param v3 the third vertex
   * @return true if the angle is right; false otherwise
   */
  public static boolean isOrthogonal(Vertex v1, Vertex v2, Vertex v3) {
    double precision = 1E-15;
    return (v2.x - v1.x) * (v2.x - v3.x) + (v2.y - v1.y) * (v2.y - v3.y) < precision;
  }

  public static boolean isRectangle(ArrayList<Vertex> vertices) {
    if (vertices.size() != 4) return false;

    for (int i = 0; i < 3; i++) {
      if (!isOrthogonal(vertices.get(i), vertices.get((i + 1) % 4), vertices.get((i + 2) % 4)))
        return false;
    }

    return true;
  }
}
