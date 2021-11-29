import java.util.ArrayList;

public class Polygon extends Figure {
  // Fields
  private final ArrayList<Vertex> vertices;
  private double area;

  // Constructors
  public Polygon() {
    this.vertices = new ArrayList<>();
  }

  public Polygon(ArrayList<Vertex> vertices) throws ImpossiblePolygonException {
    this.vertices = vertices;
    validatePolygon();
    calculateArea();
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
  public double getArea() {
    return area;
  }
  // Setters

  // Methods

  /**
   * Calculates the area of this Polygon.
   * Uses the shoelace formula: [https://en.wikipedia.org/wiki/Shoelace_formula]
   * The formula assume this Polygon is simple:
   * [https://en.wikipedia.org/wiki/Simple_polygon]
   */
  private void calculateArea() {
    double sumA = 0, sumB = 0;
    for(int i = 0; i < vertices.size() - 1; i++) {
      sumA += vertices.get(i).x * vertices.get(i + 1).y;
      sumB += vertices.get(i + 1).x * vertices.get(i).y;
    }
    sumA += vertices.get(vertices.size() - 1).x * vertices.get(0).y;
    sumB += vertices.get(0).x * vertices.get(vertices.size() - 1).y;
    area = Math.abs(sumA - sumB) / 2;
  }

  private void validatePolygon() throws ImpossiblePolygonException {
    if (anyThreeVerticesCollinear())
      throw new ImpossiblePolygonException("Polygon cannot have collinear consecutive vertices");

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
    return v1.x * (v2.y - v3.y) + v2.x * (v1.y - v3.y) + v3.x * (v1.y - v2.y) == 0;
  }

  @Override
  public String toString() {
    return "Polygon";
  }
}

class ImpossiblePolygonException extends Exception {
  ImpossiblePolygonException(String msg) {
    super(msg);
  }
}