import java.util.ArrayList;

public class Polygon extends Figure {
  private final ArrayList<Vertex> vertices;

  public Polygon() {
    this.vertices = new ArrayList<>();
  }

  public Polygon(ArrayList<Vertex> vertices) {
    this.vertices = vertices;
  }

  public static Polygon fromString(String input) throws FigureParseException {
    ArrayList<Vertex> vertices = new ArrayList<>();

    String[] verticesDescriptions = input.split(" ");
    for (String vertex : verticesDescriptions) {
      try{
        vertices.add(new Vertex(vertex));
      } catch (VertexParseException e) {
        throw new FigureParseException("Couldn't parse the Polygon: " + e.getMessage());
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
    } catch (ImpossibleTriangleException e) {
      throw new FigureParseException("Creation of triangle failed. Error: " + e.getMessage());
    }

    return polygon;
  }

  @Override
  public String toString() {
    return "Polygon";
  }
}
