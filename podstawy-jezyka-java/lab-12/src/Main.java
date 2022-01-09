import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
  public static void main(String[] args) {
    ArrayList<StudentAnswers> answerSheets =
        Stream.generate(StudentAnswers::new)
            .limit(20)
            .collect(Collectors.toCollection(ArrayList::new));
    int[] scores = new int[20];

    ExecutorService executor =
        Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());
    List<Callable<Void>> tasks = new ArrayList<>(answerSheets);

    for (int j = 0; j < 5; j++) {
      System.out.println("Asking a series of questions for the " + (j + 1) + " time");
      try {
        executor.invokeAll(tasks);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }

      for (int i = 0; i < 20; i++) {
        scores[i] += Examinator.grade(answerSheets.get(i));
      }
    }

    System.out.println("Results (from best to worst):");
    Arrays.stream(scores).boxed().sorted(Collections.reverseOrder()).forEach(System.out::println);

    executor.shutdown();
  }
}
