import java.util.ArrayList;
import java.util.logging.Logger;

public class Quadrangle extends Polygon {
  // Fields
  private static final Logger logger;

  static {
    logger = Logger.getLogger("Main.Quadrangle");
  }
  // Constructors
  public Quadrangle(ArrayList<Vertex> vertices) throws ImpossiblePolygonException {
    super(vertices);
  }

  public static Quadrangle fromVertices(ArrayList<Vertex> vertices)
      throws ImpossiblePolygonException {
    Quadrangle result;
    if (Square.isSquare(vertices)) {
      result = new Square(vertices);
    } else if (Rectangle.isRectangle(vertices)) {
      result = new Rectangle(vertices);
    } else if (Parallelogram.isParallelogram(vertices)) {
      result = new Parallelogram(vertices);
    } else if (Trapezoid.isTrapezoid(vertices)) {
      result = new Trapezoid(vertices);
    } else {
      result = new Quadrangle(vertices);
    }

    return result;
  }

  // Public methods
  @Override
  Logger getLogger() {
    return logger;
  }
}
