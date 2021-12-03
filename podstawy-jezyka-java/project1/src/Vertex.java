import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.regex.Pattern;

public class Vertex {
  double x, y;

  public Vertex(double x, double y) {
    this.x = x;
    this.y = y;
  }

  /**
   * Vertex constructor.
   *
   * @param vertex the string describing this Vertex of format: (<x_coordinate>,<y_coordinate>)
   */
  public Vertex(String vertex) throws VertexParseException {
    if (!Pattern.matches(
        "^\\(" + Figure.doubleNumberPattern + "," + Figure.doubleNumberPattern + "\\)$", vertex))
      throw new VertexParseException("Could not parse vertex: " + vertex);
    try {
      vertex = vertex.replace("(", "");
      vertex = vertex.replace(")", "");
      vertex = vertex.replace(",", " ");
      Scanner sc = new Scanner(vertex);
      this.x = sc.nextDouble();
      this.y = sc.nextDouble();
    } catch (NoSuchElementException | IllegalStateException e) {
      throw new VertexParseException("Could not parse vertex: " + vertex, e);
    }
  }

  public static double distance(Vertex vertex1, Vertex vertex2) {
    return Math.sqrt(
        (vertex1.x - vertex2.x) * (vertex1.x - vertex2.x)
            + (vertex1.y - vertex2.y) * (vertex1.y - vertex2.y));
  }

  @Override
  public String toString() {
    return "(" + x + "," + y + ")";
  }
}

class VertexParseException extends Exception {
  public VertexParseException(String msg) {
    super(msg);
  }

  public VertexParseException(String msg, Throwable e) {
    super(msg, e);
  }
}
