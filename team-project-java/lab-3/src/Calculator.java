import java.util.function.BinaryOperator;

public class Calculator {
  private Calculator() {}

  public static double calculate(double a, double b, BinaryOperator<Double> operation) {
    return operation.apply(a, b);
  }
}
