import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Locale;

public class Main {
  public static void main(String[] args) throws Exception {
    // read list of participants
    Path manifestPath =
        Paths.get(".", "project2", "resources", "daneBZ.txt").normalize().toAbsolutePath();
    ArrayList<Participant> participants = ParticipantsReader.readManifest(manifestPath);
//    participants.forEach(System.out::println);

    // launch the competition
    Competition competition = new Competition(participants);
    competition.startCompetition();

    // Print weird statistics
    System.out.println("The winner: " + competition.getWinner());
    // question 1
    System.out.println("The youngest competitor: " + competition.getYoungestParticipant());
    System.out.println("The oldest competitor: " + competition.getOldestParticipant());
    // question 2
    System.out.println(
        "The fastest swimmer: "
            + competition.getFastestSwimmer()
            + " "
            + Start.formatTime(competition.getResult(competition.getFastestSwimmer()).results[0]));

    Participant fastestCyclist = competition.getFastestCyclist();
    double time = competition.getResult(fastestCyclist).getCyclingTime();
    System.out.println("The fastest cyclist: " + fastestCyclist + " " + Start.formatTime(time));

    Participant fastestRunner = competition.getFastestRunner();
    time = competition.getResult(fastestRunner).getRunningTime();
    System.out.println("The fastest runner: " + fastestRunner + " " + Start.formatTime(time));

    // question 3
    System.out.println("Mean female time: " + Start.formatTime(competition.meanResult(Participant.Gender.FEMALE)));
    System.out.println("Mean male time: " + Start.formatTime(competition.meanResult(Participant.Gender.MALE)));

    // question 4
    System.out.println(
        "Sum of swimming times in the category W1 "
            + Start.formatTime(competition.sumSwimmingResults(Participant.Gender.FEMALE, 1)));
    System.out.println(
        "Sum of swimming times in the category M4: "
            + Start.formatTime(competition.sumSwimmingResults(Participant.Gender.MALE, 4)));

    // question 5
    System.out.println("The oldest medalist was: " + competition.getOldestMedalist());

    // question 6
    int month = competition.getBirthMonthOfBestParticipants();
    Calendar mCalendar = Calendar.getInstance();
    mCalendar.set(Calendar.MONTH, month);
    String monthName = mCalendar.getDisplayName(Calendar.MONTH, Calendar.LONG, Locale.ENGLISH);
    System.out.println(
        "The people born in the month of "
            + monthName
            + " were on average the fastest");

    // Write report to a file
    Path file = Paths.get(".", "report.csv");
    competition.writeReport(file);
  }
}
