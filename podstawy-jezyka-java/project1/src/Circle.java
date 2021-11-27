import java.util.Scanner;
import java.util.regex.Pattern;

public class Circle extends Figure {
  double radius;
  Vertex center;

  /**
   * @param line the string describing this circle written in the following format:
   *     `(<x_coordinate>,<y_coordinate>) <radius>`
   */
  public Circle(String line) throws FigureParseException {
    String[] vertexAndRadius = line.split(" ");

    try {
      if (vertexAndRadius.length != 2) throw new Exception();
      this.center = new Vertex(vertexAndRadius[0]);
      Scanner sc = new Scanner(vertexAndRadius[1]);
      this.radius = sc.nextDouble();
    } catch(VertexParseException e) {
      throw new FigureParseException("Error parsing circle's center:\n" + e.getMessage());
    } catch(Exception error) {
      throw new FigureParseException("Line:\n    " + line + "\ndoes not describe a circle");
    }
  }

  /**
   * Checks whether a String describes a Circle object.
   *
   * @param line the description of a Circle. Format: (<x>,<y>) <radius>
   * @return true if the line describes a circle; false otherwise
   */
  public static boolean isCircle(String line) {
    return Pattern.matches(
            "^\\(" + doubleNumberPatter + "," + doubleNumberPatter + "\\) " + doubleNumberPatter + "$",
            line);
  }

  @Override
  public String toString() {
    return "Circle";
  }
}
