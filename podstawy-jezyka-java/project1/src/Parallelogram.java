import java.util.ArrayList;
import java.util.logging.Logger;

public class Parallelogram extends Trapezoid {
  // Fields
  private static final Logger logger;

  static {
    logger = Logger.getLogger("Main.Parallelogram");
  }
  // Constructors
  public Parallelogram(ArrayList<Vertex> vertices) throws ImpossiblePolygonException {
    super(vertices);
  }

  // Public methods
  @Override
  Logger getLogger() {
    return logger;
  }

  public static boolean isParallelogram(ArrayList<Vertex> vertices) {
    if (vertices.size() != 4) return false;

    return areSegmentsParallel(vertices.get(0), vertices.get(1), vertices.get(2), vertices.get(3))
        && areSegmentsParallel(vertices.get(1), vertices.get(2), vertices.get(3), vertices.get(0));
  }
}
