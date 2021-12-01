public class Figure {
  // Fields
  public static final String doubleNumberPattern = "(\\p{Digit}*\\.)?\\p{Digit}+";
  private double area;
  private double perimeter;

  // Constructors
  public static Figure fromString(String input) throws FigureParseException {
    Figure fig;
    if (Circle.isCircle(input)) {
      fig = Circle.fromString(input);
    } else {
      fig = Polygon.fromString(input);
    }

    return fig;
  }

  @Override
  public String toString() {
    return "Figure";
  }

  double getArea() {
    return area;
  }

  void setArea(double area) {
    this.area = area;
  }

  double getPerimeter() {
    return perimeter;
  }

  void setPerimeter(double perimeter) {
    this.perimeter = perimeter;
  }
}

class FigureParseException extends Exception {
  public FigureParseException(String msg) {
    super(msg);
  }

  public FigureParseException(String msg, Throwable e) {
    super(msg, e);
  }
}
