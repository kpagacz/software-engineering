import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Calendar;

public class ParticipantsReader {
  private ParticipantsReader() {}

  public static ArrayList<Participant> readManifest(Path manifestPath) {
    ArrayList<Participant> participants = new ArrayList<>();
    try {
      BufferedReader reader = new BufferedReader(new FileReader(manifestPath.toString()));
      String row;
      while ((row = reader.readLine()) != null) {
        String[] args = row.split(";");
        Calendar birthday = Calendar.getInstance();
        birthday.set(
            Integer.parseInt(args[2]), Integer.parseInt(args[3]), Integer.parseInt(args[4]));
        participants.add(new Participant(args[0], args[1], birthday));
      }
    } catch (IOException e) {
      throw new RuntimeException("Error reading competition manifest", e);
    }
    return participants;
  }
}
