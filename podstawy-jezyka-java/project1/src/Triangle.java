import java.util.ArrayList;

public class Triangle extends Polygon {
  private final ArrayList<Vertex> vertices;
  private double area;

  public Triangle(ArrayList<Vertex> vertices) throws ImpossibleTriangleException {
    this.vertices = vertices;
    calculateArea();
    validateTriangle();
  }

  /**
   * Calculates the area of this triangle. Uses a modified shoelace approach.
   * */
  private void calculateArea() {
    area =
        ((vertices.get(1).x - vertices.get(2).x) * (vertices.get(2).y - vertices.get(3).y)
                - (vertices.get(2).x - vertices.get(3).x) * (vertices.get(1).y - vertices.get(2).y))
            / 2;
  }

  private void validateTriangle() throws ImpossibleTriangleException {
    if (area <= 0)
      throw new ImpossibleTriangleException("Collinear points cannot create a proper triangle");
  }

  @Override
  public String toString() {
    return "Triangle";
  }
}

class ImpossibleTriangleException extends Exception {
  public ImpossibleTriangleException(String msg) {
    super(msg);
  }
}
