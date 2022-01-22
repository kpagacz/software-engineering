import java.util.Random;
import java.util.concurrent.Callable;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Start implements Callable<Void> {
  private final int meanSwimmingTime = 20 * 60,
      meanBicycleTime = 60 * 60,
      meanRunningTime = 30 * 60,
      variance = 240;
  private static final Random rng = new Random(System.nanoTime());
  public final Lock lock = new ReentrantLock();
  public double[] results = new double[3];

  public Start() {}

  public double getCyclingTime() {
    double time;
    try {
      lock.lock();
      time = results[1] - results[0];
    } finally {
      lock.unlock();
    }
    return time;
  }

  public double getRunningTime() {
    double time;
    try {
      lock.lock();
      time = results[2] - results[1];
    } finally {
      lock.unlock();
    }
    return time;
  }

  /**
   * Formats the elapsed time.
   *
   * <p>The format is: HH:MM:SS where HH is the number of hours (possibly more than two digits), MM
   * is the number of minutes (two digits), SS is the number of seconds (two digits).
   *
   * @param seconds elapsed time in seconds
   * @return the formatted elapsed time
   */
  public static String formatTime(double seconds) {
    int hours = (int) (seconds / 60 / 60);
    int minutes = (int) (seconds / 60) % 60;
    int secs = (int) seconds % 60;

    return String.format("%02d:%02d:%02d", hours, minutes, secs);
  }

  @Override
  public Void call() {
    try {
      // I could have used something like
      // int before = System.currentTimeMillis();
      // Thread.sleep(<random_value>);
      // int after = System.currentTimeMillis();
      // int delta = before - after;
      // but at this point it doesn't really matter, I might just as well randomize the values
      // directly
      lock.lock();
      results[0] = meanSwimmingTime + 2 * variance * rng.nextDouble() - variance;
      results[1] = results[0] + meanBicycleTime + 2 * variance * rng.nextDouble() - variance;
      results[2] = results[1] + meanRunningTime + 2 * variance * rng.nextDouble() - variance;
    } finally {
      lock.unlock();
    }
    return null;
  }
}
