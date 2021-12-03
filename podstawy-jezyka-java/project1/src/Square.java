import java.util.ArrayList;
import java.util.logging.Logger;

public class Square extends Rectangle {
  // Fields
  private static final Logger logger;

  static {
    logger = Logger.getLogger("Main.Square");
  }
  // Constructors
  public Square(ArrayList<Vertex> vertices) throws ImpossiblePolygonException {
    super(vertices);
  }

  // Public methods
  @Override
  Logger getLogger() {
    return logger;
  }

  public static boolean isSquare(ArrayList<Vertex> vertices) {
    if (!isRectangle(vertices)) return false;

    double precision = 1E-15;
    double previousDistance = Vertex.distance(vertices.get(0), vertices.get(1));
    for (int i = 1; i < 4; i++) {
      double currentDistance = Vertex.distance(vertices.get(i), vertices.get((i + 1) % 4));
      if (Math.abs(currentDistance - previousDistance) > precision) return false;
      previousDistance = currentDistance;
    }

    return true;
  }
}
