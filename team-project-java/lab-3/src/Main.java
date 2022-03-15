import java.util.function.BinaryOperator;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.function.Supplier;
import java.util.function.UnaryOperator;

public class Main {
  public static void main(String[] args) {
    // Task 1
    TernaryOperator<Integer> summer = (Integer a, Integer b, Integer c) -> a + b + c;
    // Task 2
    UnaryOperator<Integer> doubler = (Integer a) -> 2 * a;
    BinaryOperator<Integer> adder = (Integer a, Integer b) -> a + b;
    Consumer<Integer> printer = (Integer a) -> System.out.println(a);
    Supplier<Integer> giveOne = () -> 1;
    Function<Integer, String> toString = (Integer a) -> adder.toString();
    Predicate<Integer> largerThanTwo = (Integer a) -> a > 2;

    // Task 3
    BinaryOperator<Double> doubleAdder = Double::sum;
    BinaryOperator<Double> doubleSubtracter = (Double a, Double b) -> a - b;
    BinaryOperator<Double> doubleMultiplier = (Double a, Double b) -> a * b;
    BinaryOperator<Double> doubleDivider = (Double a, Double b) -> a / b;
    System.out.println("2 + 3 = " + Calculator.calculate(2, 3, doubleAdder));
    System.out.println("2 - 3 = " + Calculator.calculate(2, 3, doubleSubtracter));
    System.out.println("2 * 3 = " + Calculator.calculate(2, 3, doubleMultiplier));
    System.out.println("2 / 3 = " + Calculator.calculate(2, 3, doubleDivider));
  }
}
