import java.util.ArrayList;
import java.util.Arrays;
import java.util.logging.Logger;

public class Triangle extends Polygon {
  // Fields
  private enum TriangleSideType {
    EQUILATERAL,
    ISOSCELES,
    SCALENE
  }

  private enum TriangleAngleType {
    ACUTE,
    RIGHT,
    OBTUSE
  }

  private TriangleSideType triangleSideType;
  private TriangleAngleType triangleAngleType;

  private static final Logger logger;

  static {
    logger =  Logger.getLogger("Main.Triangle");
  }

  // Constructors
  public Triangle(ArrayList<Vertex> vertices) throws ImpossiblePolygonException {
    super(vertices);
    determineSideType();
    determineAngleType();
  }

  // Getters
  public String getSideType() {
    String answer = "";
    switch(triangleSideType) {
      case EQUILATERAL -> answer = "equilateral";
      case ISOSCELES -> answer = "isosceles";
      case SCALENE -> answer = "scalene";
    }
    return answer;
  }

  public String getAngleType() {
    String answer = "";
    switch(triangleAngleType) {
      case ACUTE -> answer = "acute";
      case RIGHT -> answer = "right";
      case OBTUSE -> answer = "obtuse";
    }
    return answer;
  }

  // Public methods
  @Override
  public String toString() {
    StringBuilder out = new StringBuilder();
    out.append("Type: Triangle\n");
    out.append("Type of triangle: ").append(getSideType()).append(" ").append(getAngleType()).append("\n");
    out.append("Area: ").append(getArea()).append("\n");
    out.append("Perimeter: ").append(getPerimeter());
    return out.toString();
  }

  @Override
  Logger getLogger() {
    return logger;
  }

  // Private methods
  private void determineSideType() {
    double[] sides = new double[3];
    for (int i = 0; i < 3; i++) sides[i] = Vertex.distance(getVertex(i), getVertex((i + 1) % 3));

    // Threshold method of comparing doubles
    double precision = 1E-15;
    int distinct = 1;
    if (!(Math.abs(sides[0] - sides[1]) < precision && Math.abs(sides[0] - sides[2]) < precision)) ++distinct;
    if (!(Math.abs(sides[1] - sides[2]) < precision)) ++distinct;

    switch(distinct) {
      case 1 -> triangleSideType = TriangleSideType.EQUILATERAL;
      case 2 -> triangleSideType = TriangleSideType.ISOSCELES;
      case 3 -> triangleSideType = TriangleSideType.SCALENE;
    }
  }

  private void determineAngleType() {
    double[] sides = new double[3];
    for (int i = 0; i < 3; i++) sides[i] = Vertex.distance(getVertex(i), getVertex((i + 1) % 3));
    double[] cosines = new double[3];
    for (int i = 0; i < 3; i++) {
      cosines[i] = (sides[(i + 1) % 3] * sides[(i + 1) % 3]
              + sides[(i + 2) % 3] * sides[(i + 2) % 3]
              - sides[i] * sides[i]) /
              (2 * sides[(i + 1) % 3] * sides[(i + 2) % 3]);
    }

    double precision = 1E-15;
    if (Arrays.stream(cosines).anyMatch(value -> Math.abs(value) < precision)) {
      triangleAngleType = TriangleAngleType.RIGHT;
    } else if (Arrays.stream(cosines).anyMatch(value -> value < 0)) {
      triangleAngleType = TriangleAngleType.OBTUSE;
    } else {
      triangleAngleType = TriangleAngleType.ACUTE;
    }
  }

}
