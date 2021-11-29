import java.util.ArrayList;

public class Quadrangle extends Polygon {
    public Quadrangle(ArrayList<Vertex> vertices) throws ImpossiblePolygonException {
        super(vertices);
    }

    @Override
    public String toString() {
        return "Quadrangle";
    }
}
