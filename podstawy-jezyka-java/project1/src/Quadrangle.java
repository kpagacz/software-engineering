import java.util.ArrayList;

public class Quadrangle extends Polygon {
    public Quadrangle(ArrayList<Vertex> vertices) throws ImpossiblePolygonException {
        super(vertices);
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append("Type: Quadrangle\n");
        out.append("Perimeter: ").append(getPerimeter()).append("\n");
        out.append("Area ").append(getArea()).append("\n");
        return "Quadrangle";
    }
}
