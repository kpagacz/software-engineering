public class PrimeValidator implements Runnable {
  private int number;

  public PrimeValidator(int number) {
    this.number = number;
  }

  @Override
  public void run() {
    if (number < 2) {
      System.out.println(number + " is not prime");
    }
    int square = (int) (Math.sqrt(number));
    boolean prime = true;
    for (int i = 2; i < square; i++) {
      if (number % i == 0) {
        prime = false;
        break;
      }
    }
    if (prime) {
      System.out.println(number + " is prime");
    } else {
      System.out.println(number + " is not prime");
    }
  }
}
