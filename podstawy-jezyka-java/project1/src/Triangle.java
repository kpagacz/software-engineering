import java.util.ArrayList;

public class Triangle extends Polygon {
    private ArrayList<Vertex> vertices;

    public Triangle() {}

    public Triangle(ArrayList<Vertex> vertices) {
        this.vertices = vertices;
    }

    @Override
    public String toString() {
        return "Triangle";
    }
}
