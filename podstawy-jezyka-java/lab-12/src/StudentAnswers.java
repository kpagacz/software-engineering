import java.util.ArrayList;
import java.util.Random;
import java.util.concurrent.Callable;
import java.util.concurrent.locks.ReentrantLock;

public class StudentAnswers implements Callable<Void> {
  private static final Random rng = new Random();
  public final ReentrantLock answersLock = new ReentrantLock();
  public final ArrayList<Boolean> answerSheet = new ArrayList<>();

  public StudentAnswers() {}

  @Override
  public Void call() {
    answersLock.lock();
    try {
      answerSheet.clear();
      for (int i = 0; i < 20; i++) answerSheet.add(rng.nextBoolean());
    } finally {
      answersLock.unlock();
    }
    return null;
  }
}
