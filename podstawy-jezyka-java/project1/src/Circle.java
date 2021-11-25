public class Circle extends Figure {
    double radius;
    Vertex center;

    public Circle(Vertex center, double radius) {
        this.center = center;
        this.radius = radius;
    }

    @Override
    public String toString() {
        return "Circle";
    }
}
