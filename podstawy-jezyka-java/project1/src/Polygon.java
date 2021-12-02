import java.sql.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.TreeSet;
import java.util.stream.IntStream;

public class Polygon extends Figure {
  // Fields
  private final ArrayList<Vertex> vertices;

  // Constructors
  public Polygon() {
    this.vertices = new ArrayList<>();
  }

  public Polygon(ArrayList<Vertex> vertices) throws ImpossiblePolygonException {
    this.vertices = vertices;
    validatePolygon();
    calculateArea();
    calculatePerimeter();
  }

  public static Polygon fromString(String input) throws FigureParseException {
    ArrayList<Vertex> vertices = new ArrayList<>();

    String[] verticesDescriptions = input.split(" ");
    for (String vertex : verticesDescriptions) {
      try{
        vertices.add(new Vertex(vertex));
      } catch (VertexParseException e) {
        throw new FigureParseException("Couldn't parse the Polygon.", e);
      }
    }

    Polygon polygon;
    try {
      switch(vertices.size()) {
        case 1 -> throw new FigureParseException("Can't create a polygon from one vertex");
        case 2 -> throw new FigureParseException("Can't create a polygon from two vertices");
        case 3 -> polygon = new Triangle(vertices);
        case 4 -> polygon = new Quadrangle(vertices);
        default -> polygon = new Polygon(vertices);
      }
    } catch (ImpossiblePolygonException e) {
      throw new FigureParseException("Creation of a polygon failed", e);
    }

    return polygon;
  }

  // Getters
  public Vertex getVertex(int vertexNumber) {
    return vertices.get(vertexNumber);
  }
  // Setters

  // Public methods
  void calculatePerimeter() {
    double perimeter = 0;
    for (int i = 0; i < vertices.size(); i++)
      perimeter += Vertex.distance(getVertex(i), getVertex((i + 1) % vertices.size()));
    setPerimeter(perimeter);
  }

  /**
   * Calculates the area of this Polygon.
   * Uses the shoelace formula: [https://en.wikipedia.org/wiki/Shoelace_formula]
   * The formula assume this Polygon is simple:
   * [https://en.wikipedia.org/wiki/Simple_polygon]
   */
  void calculateArea() {
    double sumA = 0, sumB = 0;
    for(int i = 0; i < vertices.size() - 1; i++) {
      sumA += vertices.get(i).x * vertices.get(i + 1).y;
      sumB += vertices.get(i + 1).x * vertices.get(i).y;
    }
    sumA += vertices.get(vertices.size() - 1).x * vertices.get(0).y;
    sumB += vertices.get(0).x * vertices.get(vertices.size() - 1).y;
    setArea(Math.abs(sumA - sumB) / 2);
  }

  @Override
  public String toString() {
    StringBuilder out = new StringBuilder();
    out.append("Type: Polygon\n");
    out.append("Perimeter: ").append(getPerimeter()).append("\n");
    out.append("Area ").append(getArea()).append("\n");
    return out.toString();
  }

  // Private methods
  private void validatePolygon() throws ImpossiblePolygonException {
    if (anyThreeVerticesCollinear())
      throw new ImpossiblePolygonException("Polygon cannot have collinear consecutive vertices");
    if (isPolygonComplex()) throw new ImpossiblePolygonException("Complex polygons not supported");
  }

  private boolean isPolygonComplex() {
    return areAnySegmentsIntersecting(vertices);
  }

  /**
  * Implements a naive approach to determine whether any segments intersect with one another.
  *
  * @param vertices the list of vertices of segments. Vertices define segments of a polygon.
  *                 Two neighbouring vertices are part of the same segment.
  * @return true if any segment defined by vertices intersects another segment; false otherwise
  */
  private boolean areAnySegmentsIntersecting(ArrayList<Vertex> vertices) {
    for(int i = 0; i < vertices.size(); i++) {
      for(int j = i + 2; j < (i == 0 ? vertices.size() - 1 : vertices.size()); j++) {
        if (doSegmentsIntersect(vertices.get(i), vertices.get((i + 1) % vertices.size()), vertices.get(j), vertices.get((j + 1) % vertices.size()))) {
          return true;
        }
      }
    }
    return false;
  }


  /**
  * Implements algorithm described in:
  * https://stackoverflow.com/a/3842157/8580062
  * @param line1V1 the first vertex of the first line
  * @param line1V2 the second vertex of the first line
  * @param line2V1 the first vertex of the second line
  * @param line2V2 the second vertex of the second line
  * @return true if the two segments intersect; false otherwise
  */
  private boolean doSegmentsIntersect(Vertex line1V1, Vertex line1V2, Vertex line2V1, Vertex line2V2) {
    double cOrientationAB = (line1V1.x - line2V1.x) * (line1V2.y - line2V1.y) - (line1V2.x - line2V1.x) * (line1V1.y - line2V1.y);
    double dOrientationAB = (line1V1.x - line2V2.x) * (line1V2.y - line2V2.y) - (line1V2.x - line2V2.x) * (line1V1.y - line2V2.y);
    double aOrientationCD = (line2V1.x - line1V1.x) * (line2V2.y - line1V1.y) - (line2V2.x - line1V1.x) * (line2V1.y - line1V1.y);
    double bOrientationCD = (line2V1.x - line1V2.x) * (line2V2.y - line1V2.y) - (line2V2.x - line1V2.x) * (line2V1.y - line1V2.y);
    return Math.signum(cOrientationAB) != Math.signum(dOrientationAB) && Math.signum(aOrientationCD) != Math.signum(bOrientationCD);
  }

  private boolean anyThreeVerticesCollinear() {
    for (int i = 0; i < vertices.size(); i++)
      if(areThreeVerticesCollinear(
              vertices.get(i),
              vertices.get((i + 1) % vertices.size()),
              vertices.get((i + 2) % vertices.size()))) return true;
    return false;
  }

  private boolean areThreeVerticesCollinear(Vertex v1, Vertex v2, Vertex v3) {
    double precision = 1E-15;
    return Math.abs(v1.x * (v2.y - v3.y) + v2.x * (v3.y - v1.y) + v3.x * (v1.y - v2.y)) < precision;
  }

}

class ImpossiblePolygonException extends Exception {
  ImpossiblePolygonException(String msg) {
    super(msg);
  }
}