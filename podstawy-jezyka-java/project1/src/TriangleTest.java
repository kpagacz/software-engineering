import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class TriangleTest {
  @Test
  void testConstructor() {
    ArrayList<Vertex> goodVertices =
        new ArrayList<>(List.of(new Vertex(0, 0), new Vertex(1, 1), new Vertex(1, 0)));
    assertDoesNotThrow(() -> new Triangle(goodVertices));
  }

  @Test
  @DisplayName("Constructor throws when vertices are collinear")
  void testConstructorThrows() {
    ArrayList<Vertex> collinearVertices =
        new ArrayList<>(List.of(new Vertex(0, 0), new Vertex(1, 1), new Vertex(2, 2)));
    assertThrows(ImpossiblePolygonException.class, () -> new Triangle(collinearVertices));
  }

  @Test
  @DisplayName("Constructor builds an isosceles triangle")
  void testIsoscelesTriangle() throws ImpossiblePolygonException {
    ArrayList<Vertex> vertices =
        new ArrayList<>(List.of(new Vertex(-1, 0), new Vertex(1, 0), new Vertex(0, 3)));
    Triangle triangle = new Triangle(vertices);
    assertEquals("isosceles", triangle.getSideType());
  }

  @Test
  @DisplayName("Constructor builds a scalene triangle")
  void testScaleneTriangle() throws ImpossiblePolygonException {
    ArrayList<Vertex> vertices =
        new ArrayList<>(List.of(new Vertex(0, 0), new Vertex(1, 0), new Vertex(0, 3)));
    Triangle triangle = new Triangle(vertices);
    assertEquals("scalene", triangle.getSideType());
  }

  @Test
  @DisplayName("Constructor builds an equilateral triangle")
  void testEquilateralTriangle() throws ImpossiblePolygonException {
    ArrayList<Vertex> vertices =
        new ArrayList<>(
            List.of(new Vertex(0, 0), new Vertex(1, 0), new Vertex(0.5, Math.sqrt(3) / 2)));
    Triangle triangle = new Triangle(vertices);
    assertEquals("equilateral", triangle.getSideType());
  }

  @Test
  @DisplayName("Constructor builds a right triangle")
  void testRightTriangle() throws ImpossiblePolygonException {
    ArrayList<Vertex> vertices =
        new ArrayList<>(List.of(new Vertex(0, 0), new Vertex(1, 0), new Vertex(0, 1)));
    Triangle triangle = new Triangle(vertices);
    assertEquals("right", triangle.getAngleType());
  }

  @Test
  @DisplayName("Constructor builds an obtuse triangle")
  void testObtuseTriangle() throws ImpossiblePolygonException {
    ArrayList<Vertex> vertices =
        new ArrayList<>(List.of(new Vertex(0, 0), new Vertex(1, 0), new Vertex(-0.2, 1)));
    Triangle triangle = new Triangle(vertices);
    assertEquals("obtuse", triangle.getAngleType());
  }

  @Test
  @DisplayName("Constructor builds an acute triangle")
  void testAcuteTriangle() throws ImpossiblePolygonException {
    ArrayList<Vertex> vertices =
        new ArrayList<>(List.of(new Vertex(0, 0), new Vertex(1, 0), new Vertex(0.2, 1)));
    Triangle triangle = new Triangle(vertices);
    assertEquals("acute", triangle.getAngleType());
  }

  @Test
  @DisplayName("Regression test for vertices (0,0) (1,0) (0.2,1)")
  void regressionTest1() throws ImpossiblePolygonException {
    ArrayList<Vertex> vertices =
        new ArrayList<>(List.of(new Vertex(0, 0), new Vertex(1, 0), new Vertex(0.2, 1)));
    Triangle triangle = new Triangle(vertices);
    assertEquals("acute", triangle.getAngleType());
    assertEquals("scalene", triangle.getSideType());
  }

  @Test
  @DisplayName("getPerimeter returns the correct perimeter")
  void testGetPerimeter() throws ImpossiblePolygonException {
    ArrayList<Vertex> vertices =
        new ArrayList<>(List.of(new Vertex(0, 0), new Vertex(1, 0), new Vertex(0, 1)));
    Triangle triangle = new Triangle(vertices);
    assertEquals(2 + Math.sqrt(2), triangle.getPerimeter(), 1E-15);
  }
}
