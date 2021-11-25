import java.util.ArrayList;
import java.util.Arrays;

public class Figure {
  public static Figure fromString(String input) throws FigureParseException {
    ArrayList<Vertex> vertices = VertexParser.parseStringToVertices(input);
    return switch (vertices.size()) {
      case 1, 2 -> throw new FigureParseException("Too few vertices");
      case 3 -> new Triangle(vertices);
      case 4 -> new Quadrangle(vertices);
      default -> new Polygon(vertices);
    };
  }

  @Override
  public String toString() {
    return "Figure";
  }
}

class FigureParseException extends Exception {
  public FigureParseException() {
    super("Couldn't parse the input");
  }

  public FigureParseException(String msg) {
    super(msg);
  }
}

class VertexParser {
  public static ArrayList<Vertex> parseStringToVertices(String line) throws FigureParseException {
    ArrayList<Vertex> vertices = new ArrayList<>();
    switch(line) {
      case "triangle" -> vertices.addAll(Arrays.asList(new Vertex(0, 0), new Vertex(0, 0), new Vertex(0, 0)));
      case "quadrangle" -> vertices.addAll(Arrays.asList(new Vertex(0, 0), new Vertex(0, 0), new Vertex(0, 0), new Vertex(0, 0)));
      case "polygon" -> vertices.addAll(Arrays.asList(new Vertex(0, 0), new Vertex(0, 0), new Vertex(0, 0), new Vertex(0, 0), new Vertex(0, 0)));
      default -> throw new FigureParseException();
    }
    return vertices;
  }
}