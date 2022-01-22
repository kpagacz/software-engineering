import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.stream.Collectors;

public class Competition {
  private final ArrayList<Participant> participants;
  private final HashMap<Participant, Start> starts = new HashMap<>();

  public Competition(ArrayList<Participant> participants) {
    this.participants = participants;
  }

  /**
   * Returns the results of a single participant.
   *
   * @param participant the participant
   * @return the results
   */
  public Start getResult(Participant participant) {
    return starts.getOrDefault(participant, null);
  }

  /** Commences the competition. */
  public void startCompetition() {
    participants.forEach(p -> starts.put(p, new Start()));
    System.out.println("number of competitors: " +participants.size());
    ExecutorService executorService = Executors.newFixedThreadPool(participants.size());
    try {
      executorService.invokeAll(starts.values());
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    boolean executed = false;
    try {
      executorService.shutdown();
      executed = executorService.awaitTermination(10, TimeUnit.SECONDS);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    if (!executed) {
      throw new RuntimeException("Some participants did not finish the competition!");
    }

    System.out.println("Registered starts number: " + starts.values().size());
  }

  /**
   * Returns the youngest participant in the competition.
   *
   * @return the youngest participant
   */
  public Participant getYoungestParticipant() {
    return participants.stream().max(Comparator.comparing(Participant::getBirthday)).orElse(null);
  }

  /**
   * Returns the oldest participant in the competition.
   *
   * @return the oldest participant
   */
  public Participant getOldestParticipant() {
    return participants.stream().min(Comparator.comparing(Participant::getBirthday)).orElse(null);
  }

  /**
   * Returns the fastest swimmer.
   *
   * @return the fastest swimmer
   */
  public Participant getFastestSwimmer() {
    return starts.entrySet().stream()
        .min(Map.Entry.comparingByValue(Comparator.comparingDouble(start -> start.results[0])))
        .orElseThrow()
        .getKey();
  }

  /**
   * Returns the fastest cyclist.
   *
   * @return the fastest cyclist
   */
  public Participant getFastestCyclist() {
    return starts.entrySet().stream()
        .min(
            Map.Entry.comparingByValue(
                Comparator.comparingDouble(start -> start.results[1] - start.results[0])))
        .orElseThrow()
        .getKey();
  }

  /**
   * Returns the fastest runner.
   *
   * @return the fastest runner
   */
  public Participant getFastestRunner() {
    return starts.entrySet().stream()
        .min(
            Map.Entry.comparingByValue(
                Comparator.comparingDouble(start -> start.results[2] - start.results[1])))
        .orElseThrow()
        .getKey();
  }

  /**
   * Returns the mean time at the finish line of participants from one gender.
   *
   * @param gender the gender of participants
   * @return the mean number of seconds
   */
  public double meanResult(Participant.Gender gender) {
    return starts.entrySet().stream()
        .filter(entry -> entry.getKey().getGender() == gender)
        .mapToDouble(entry -> entry.getValue().results[2])
        .average()
        .orElseThrow();
  }

  /**
   * Returns the sum of times at the finish line of participants of particular gender and category.
   *
   * @param gender the gender of participants
   * @param category the category of participants
   * @return the sum of times in seconds
   */
  public double sumSwimmingResults(Participant.Gender gender, int category) {
    if (category < 1 || category > 4)
      throw new IllegalArgumentException("Category must be in the interval [1, 4]");
    return starts.entrySet().stream()
        .filter(
            entry ->
                entry.getKey().getAgeCategory() == category && entry.getKey().getGender() == gender)
        .mapToDouble(entry -> entry.getValue().results[0])
        .sum();
  }

  /**
   * Returns the oldest medalist.
   *
   * @return the oldest medalist
   */
  public Participant getOldestMedalist() {
    return starts.entrySet().stream()
        .sorted(Map.Entry.comparingByValue(Comparator.comparingDouble(start -> start.results[2])))
        .limit(3)
        .min(
            Map.Entry.comparingByKey(
                Comparator.comparingInt(
                    participant -> participant.getBirthday().get(Calendar.YEAR))))
        .orElseThrow()
        .getKey();
  }

  /**
   * Returns the month of birth of participants who on average were the quickest.
   *
   * @return the month of birth
   */
  public int getBirthMonthOfBestParticipants() {
    return starts.entrySet().stream()
        .collect(
            Collectors.groupingBy(
                entry -> entry.getKey().getBirthday().get(Calendar.MONTH),
                Collectors.averagingDouble(entry -> entry.getValue().results[2])))
        .entrySet()
        .stream()
        .min(Map.Entry.comparingByValue(Comparator.comparingDouble(Double::doubleValue)))
        .orElseThrow()
        .getKey();
  }

  /**
   * Returns the winner of the competition.
   *
   * @return the winner of the competition
   */
  public Participant getWinner() {
    return starts.entrySet().stream()
        .min(Map.Entry.comparingByValue(Comparator.comparingDouble(start -> start.results[2])))
        .orElseThrow()
        .getKey();
  }

  /**
   * Writes a competition report to a file.
   *
   * @param file the file to write the report
   * @throws Exception when the writing failed
   */
  public void writeReport(Path file) throws Exception {
    List<Participant> overallRanking =
        starts.entrySet().stream()
            .sorted(
                Map.Entry.comparingByValue(Comparator.comparingDouble(start -> start.results[2])))
            .map(Map.Entry::getKey)
            .toList();
    Map<Participant.Gender, List<Participant>> rankingByGender =
        starts.entrySet().stream()
            .sorted(
                Map.Entry.comparingByValue(Comparator.comparingDouble(start -> start.results[2])))
            .map(Map.Entry::getKey)
            .collect(Collectors.groupingBy(Participant::getGender));
    Map<String, List<Participant>> rankingByCategory =
        starts.entrySet().stream()
            .sorted(
                Map.Entry.comparingByValue(Comparator.comparingDouble(start -> start.results[2])))
            .map(Map.Entry::getKey)
            .collect(Collectors.groupingBy(Participant::getCategory));
    List<Participant> swimmingRanking =
        starts.entrySet().stream()
            .sorted(
                Map.Entry.comparingByValue(Comparator.comparingDouble(start -> start.results[0])))
            .map(Map.Entry::getKey)
            .toList();
    List<Participant> cyclingRanking =
        starts.entrySet().stream()
            .sorted(Map.Entry.comparingByValue(Comparator.comparingDouble(Start::getCyclingTime)))
            .map(Map.Entry::getKey)
            .toList();
    List<Participant> runningRanking =
        starts.entrySet().stream()
            .sorted(Map.Entry.comparingByValue(Comparator.comparingDouble(Start::getRunningTime)))
            .map(Map.Entry::getKey)
            .toList();

    StringBuilder report = new StringBuilder();
    report.append("Nr;Name;Surname;1st control;2nd control;Finish;Gender;Category;Swim;Bike;Run\n");
    for (int i = 0; i < overallRanking.size(); i++) {
      Participant participant = overallRanking.get(i);
      Start start = getResult(participant);
      report
          .append(i + 1)
          .append(";")
          .append(participant.getName())
          .append(";")
          .append(participant.getSurname())
          .append(";")
          .append(Start.formatTime(start.results[0]))
          .append(";")
          .append(Start.formatTime(start.results[1]))
          .append(";")
          .append(Start.formatTime(start.results[2]))
          .append(";")
          .append(participant.getGender() == Participant.Gender.FEMALE ? "F" : "M")
          .append("-")
          .append(rankingByGender.get(participant.getGender()).indexOf(participant) + 1)
          .append(";")
          .append(participant.getCategory())
          .append("-")
          .append(rankingByCategory.get(participant.getCategory()).indexOf(participant) + 1)
          .append(";")
          .append(swimmingRanking.indexOf(participant) + 1)
          .append(";")
          .append(cyclingRanking.indexOf(participant) + 1)
          .append(";")
          .append(runningRanking.indexOf(participant) + 1)
          .append("\n");
    }

    try {
      BufferedWriter writer =
          new BufferedWriter(new FileWriter(file.toAbsolutePath().toString()));
      writer.write(report.toString());
      writer.close();
    } catch (IOException e) {
      throw new Exception("Error writing the report", e);
    }
  }
}
