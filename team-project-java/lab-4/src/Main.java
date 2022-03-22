import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.IntStream;

// Tasks URL: http://math.uni.lodz.pl/~wardd/dydaktyka/ul/PZJ/lab4/watki_zadania.pdf
public class Main {
  public static void main(String[] args) {
    // Task 1
    ArrayList<Runnable> threads = new ArrayList<>();
    for (int i = 0; i < 10; i++) {
      threads.add(new DigitPrinter(i));
    }
    ExecutorService executor = Executors.newFixedThreadPool(9);
//    threads.forEach(executor::submit);

    // Task 2
    class CustomInteger {
      private int value;

      public CustomInteger() {
        this.value = 0;
      }

      public synchronized void increase(int increment) {
        this.value += increment;
      }
    }
    class IntegerModifier extends Thread {
      CustomInteger integer;
      public IntegerModifier(CustomInteger integer) {
        super();
        this.integer = integer;
      }
      public void run() {
        integer.increase(1);
      }
    }
    CustomInteger integer = new CustomInteger();
    ArrayList<IntegerModifier> modifiers = new ArrayList<>();
    for(int i = 0; i < 10; i++) modifiers.add(new IntegerModifier(integer));
    modifiers.forEach(Thread::start);
    for (IntegerModifier modifier : modifiers) {
      try {
        modifier.join();
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
    System.out.println("Task 2");
    System.out.println("Result: " + integer.value);

    // Task 3
    int[] numbers = IntStream.range(1, 100).toArray();
    Arrays.stream(numbers).forEach((number) -> executor.submit(new PrimeValidator(number)));

    // Task 4
    Board board = new Board();
    System.out.println(board);
    ArrayList<SquarePusher> squarePushers = new ArrayList<>();
    for(int i = 0; i < 10; i++) squarePushers.add(new SquarePusher(i, board));
    ExecutorService pushExecutor = Executors.newFixedThreadPool(10);
    squarePushers.forEach(pushExecutor::submit);
  }
}
