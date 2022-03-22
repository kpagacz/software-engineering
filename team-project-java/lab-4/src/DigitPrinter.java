import java.util.concurrent.TimeUnit;

public class DigitPrinter implements Runnable {
  private final int digit;

  public DigitPrinter(int digit) {
    this.digit = digit;
  }

  @Override
  public void run() {
    while (true) {
      System.out.println(digit);
      try {
        TimeUnit.SECONDS.sleep(1);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }
}
