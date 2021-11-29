import java.util.ArrayList;

public class Triangle extends Polygon {
  public Triangle(ArrayList<Vertex> vertices) throws ImpossiblePolygonException {
    super(vertices);
  }

  // TO-DO: write a function determining the type of the triangle (konrad.pagacz@gmail.com)

  @Override
  public String toString() {
    StringBuilder out = new StringBuilder();
    out.append("Type: Triangle");
    out.append("Type of triangle: ");
    out.append("Area: ").append(getArea());
    return "Triangle";
  }
}

class ImpossibleTriangleException extends Exception {
  public ImpossibleTriangleException(String msg) {
    super(msg);
  }
}
