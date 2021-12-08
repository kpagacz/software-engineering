import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.logging.Logger;
import java.util.regex.Pattern;

public class Circle extends Figure {
  // Fields
  double radius;
  Vertex center;
  private static final Logger logger;

  static {
    logger = Logger.getLogger("Main.Circle");
  }

  // Constructors
  public Circle(Vertex center, double radius) throws ImpossibleCircleException {
    this.center = center;
    this.radius = radius;
    validateCircle();
    calculateArea();
    calculatePerimeter();

    logger.info("Circle initialized. Center: " + center.toString() + " radius: " + radius);
  }
  /**
   * @param line the string describing this circle written in the following format:
   *     `(<x_coordinate>,<y_coordinate>) <radius>`
   */
  public static Circle fromString(String line) throws FigureParseException {
    String[] vertexAndRadius = line.split(" ");
    Vertex center;
    double radius;

    if (vertexAndRadius.length != 2)
      throw new FigureParseException("Line: \n     " + line + "\ndoes not describe a circle");
    try {
      center = new Vertex(vertexAndRadius[0]);
      Scanner sc = new Scanner(vertexAndRadius[1]);
      radius = sc.nextDouble();
    } catch (VertexParseException e) {
      throw new FigureParseException("Error parsing circle's center", e);
    } catch (NoSuchElementException | IllegalStateException error) {
      throw new FigureParseException("Line:\n    " + line + "\ndoes not describe a circle");
    }

    try {
      return new Circle(center, radius);
    } catch (ImpossibleCircleException e) {
      throw new FigureParseException("Circle parsing failed.", e);
    }
  }

  private void calculateArea() {
    setArea(Math.PI * radius * radius);
  }

  private void calculatePerimeter() {
    setPerimeter(2 * Math.PI * radius);
  }

  // Public methods
  /**
   * Checks whether a String describes a Circle object.
   *
   * @param line the description of a Circle. Format: (<x>,<y>) <radius>
   * @return true if the line describes a circle; false otherwise
   */
  public static boolean isCircle(String line) {
    return Pattern.matches(
        "^\\("
            + doubleNumberPattern
            + ","
            + doubleNumberPattern
            + "\\) "
            + doubleNumberPattern
            + "$",
        line);
  }

  @Override
  public String toString() {
    StringBuilder out = new StringBuilder();
    out.append("Type: Circle\n");
    out.append("Perimeter: ").append(getPerimeter()).append("\n");
    out.append("Area ").append(getArea()).append("\n");
    return out.toString();
  }

  // Private methods
  private void validateCircle() throws ImpossibleCircleException {
    if (radius <= 0) throw new ImpossibleCircleException("Circle's radius must be non-negative");
  }
}

class ImpossibleCircleException extends Exception {
  public ImpossibleCircleException(String msg) {
    super(msg);
  }
}
