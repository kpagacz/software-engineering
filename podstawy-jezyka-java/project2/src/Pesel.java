import java.util.Calendar;
import java.util.HashMap;

/** Class generating a fictional, valid PESEL number. */
public class Pesel {
  private Pesel() {}

  private static final HashMap<Calendar, Integer> maleCounter = new HashMap<>();
  private static final HashMap<Calendar, Integer> femaleCounter = new HashMap<>();

  /**
   * Returns a correct PESEL number.
   *
   * @param birthday date of birth
   * @param gender gender
   * @return valid PESEL
   */
  public static String fromBirthday(Calendar birthday, Participant.Gender gender) {
    int year = birthday.get(Calendar.YEAR);
    int month = birthday.get(Calendar.MONTH);
    if (year >= 2000) month += 20;
    year %= 100;
    int day = birthday.get(Calendar.DAY_OF_MONTH);

    int counter;
    HashMap<Calendar, Integer> map =
        gender == Participant.Gender.FEMALE ? femaleCounter : maleCounter;
    if (!map.containsKey(birthday)) map.put(birthday, gender == Participant.Gender.FEMALE ? 0 : 1);
    counter = map.get(birthday);
    map.put(birthday, counter + 2);

    StringBuilder pesel = new StringBuilder();
    pesel
        .append(padIntWithZeros(year, 2))
        .append(padIntWithZeros(month, 2))
        .append(padIntWithZeros(day, 2))
        .append(padIntWithZeros(counter, 4));
    pesel.append(calculateControl(pesel.toString()));

    return pesel.toString();
  }

  /**
   * Pads an integer with leading zeros up to a specified width.
   *
   * @param n the integer to pad
   * @param width the total desired length of the integer, including the padding
   * @return the padded integer
   */
  private static String padIntWithZeros(int n, int width) {
    return String.format("%" + width + "s", n).replace(' ', '0');
  }

  /**
   * Calculates the control digit of a PESEL number
   *
   * @param pesel the pesel
   * @return the control digit
   */
  private static int calculateControl(String pesel) {
    int[] weights = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    assert (pesel.length() == weights.length);
    int sum = 0;
    for (int i = 0; i < pesel.length(); i++) {
      sum += Character.getNumericValue(pesel.charAt(i)) * weights[i];
    }
    return (10 - sum % 10) % 10;
  }
}
