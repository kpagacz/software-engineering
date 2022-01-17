import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.Calendar;
import java.util.GregorianCalendar;

import static org.junit.jupiter.api.Assertions.assertEquals;

class PeselTest {

  @Test
  @DisplayName("fromBirthday returns different PESEL numbers for people born on the same day")
  void fromBirthday() {
    Calendar date = new GregorianCalendar(1990, 1, 1);
    assertEquals("90010100016", Pesel.fromBirthday(date, Participant.Gender.MALE));
    assertEquals("90010100030", Pesel.fromBirthday(date, Participant.Gender.MALE));
    assertEquals("90010100054", Pesel.fromBirthday(date, Participant.Gender.MALE));

    assertEquals("90010100009", Pesel.fromBirthday(date, Participant.Gender.FEMALE));
    assertEquals("90010100023", Pesel.fromBirthday(date, Participant.Gender.FEMALE));

    date.set(Calendar.DAY_OF_MONTH, 2);
    assertEquals("90010200013", Pesel.fromBirthday(date, Participant.Gender.MALE));
  }

  @Test
  @DisplayName(
      "fromBirthday adds 20 to the month parth of the number for people born after year 1999")
  void fromBirthdayForLaterThan2k() {
    Calendar date = new GregorianCalendar(2000, 1, 1);
    assertEquals("00210100004", Pesel.fromBirthday(date, Participant.Gender.FEMALE));
    assertEquals("00210100011", Pesel.fromBirthday(date, Participant.Gender.MALE));
  }
}
