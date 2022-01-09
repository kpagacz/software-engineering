public class Examinator {
  private Examinator() {}

  public static int grade(StudentAnswers answers) {
    answers.answersLock.lock();
    int res;
    try {
      res = (int) answers.answerSheet.stream().filter(answer -> answer).count();
    } finally {
      answers.answersLock.unlock();
    }
    return res;
  }
}
