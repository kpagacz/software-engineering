import java.util.Scanner;
import java.util.regex.Pattern;

public class Circle extends Figure {
  // Fields
  double radius;
  Vertex center;

  // Constructors
  public Circle(Vertex center, double radius) throws ImpossibleCircleException {
    this.center = center;
    this.radius = radius;
    validateCircle();
    calculateArea();
    calculatePerimeter();
  }
  /**
   * @param line the string describing this circle written in the following format:
   *     `(<x_coordinate>,<y_coordinate>) <radius>`
   */
  public static Circle fromString(String line) throws FigureParseException {
    String[] vertexAndRadius = line.split(" ");
    Vertex center;
    double radius;

    try {
      if (vertexAndRadius.length != 2) throw new Exception();
      center = new Vertex(vertexAndRadius[0]);
      Scanner sc = new Scanner(vertexAndRadius[1]);
      radius = sc.nextDouble();
    } catch(VertexParseException e) {
      throw new FigureParseException("Error parsing circle's center", e);
    } catch(Exception error) {
      throw new FigureParseException("Line:\n    " + line + "\ndoes not describe a circle");
    }

    try{
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
            "^\\(" + doubleNumberPattern + "," + doubleNumberPattern + "\\) " + doubleNumberPattern + "$",
            line);
  }

  @Override
  public String toString() {
    return "Circle";
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