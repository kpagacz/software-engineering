import java.util.ArrayList;

public class Polygon extends Figure {
    private ArrayList<Vertex> vertices;
    public Polygon(ArrayList<Vertex> vertices) {
        this.vertices = vertices;
    }

    public Polygon() {
        vertices = new ArrayList<>();
    }

    @Override
    public String toString() {
        return "Polygon";
    }
}
