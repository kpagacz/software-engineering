public class Figure {
  public static final String doubleNumberPatter = "(\\p{Digit}*\\.)?\\p{Digit}+";

  public static Figure fromString(String input) throws FigureParseException {
    Figure fig = new Figure();
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
  public FigureParseException() {
    super("Couldn't parse the input");
  }

  public FigureParseException(String msg) {
    super(msg);
  }
}
