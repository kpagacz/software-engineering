import java.util.Calendar;
import java.util.GregorianCalendar;

public class Main {
  public static void main(String[] args) {
    //
      Calendar date = new GregorianCalendar(1990, 1, 1);
      System.out.println(Pesel.fromBirthday(date, Participant.Gender.MALE));
      System.out.println(Pesel.fromBirthday(date, Participant.Gender.MALE));
      System.out.println(Pesel.fromBirthday(date, Participant.Gender.MALE));
  }
}
