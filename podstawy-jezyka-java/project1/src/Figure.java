public class Figure {
  public static final String doubleNumberPattern = "(\\p{Digit}*\\.)?\\p{Digit}+";

  public static Figure fromString(String input) throws FigureParseException {
    Figure fig;
    if (Circle.isCircle(input)) {
      fig = new Circle(input);
    } else {
      fig = Polygon.fromString(input);
    }

    return fig;
  }

  @Override
  public String toString() {
    return "Figure";
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
