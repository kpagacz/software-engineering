import java.time.LocalDate;
import java.time.LocalTime;
import java.time.YearMonth;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Input person's name: ");
    String name = sc.next();
    System.out.println("Input person's surname: ");
    String surname = sc.next();
    System.out.println("Input person's year of birth: ");
    String year = sc.next();
    System.out.println("Input person's month of birth: ");
    String month = sc.next();
    System.out.println("Input person's day of birth: ");
    String day = sc.next();

    try {
      isNameValid(name);
      isNameValid(surname);
      isDateValid(year, month, day);
    } catch (IllegalFormatPersonException e) {
      System.out.println("Input data invalid:");
      System.out.println(e.getMessage());
    }

    Person person =
        new Person(
            name,
            surname,
            LocalDate.of(Integer.parseInt(year), Integer.parseInt(month), Integer.parseInt(day)),
            LocalTime.parse("12:00:00"));

    System.out.println(person.getGender());
    System.out.println(person.getBirthDateTimeInLA());
    System.out.println(person.getDayOfBirth());
    person.reverseNameAndSurname();
  }

  public static void isNameValid(String name) throws IllegalFormatPersonException {
    if (!name.matches("^[A-Z][a-z]*$"))
      throw new IllegalFormatPersonException("Invalid name/surname format");
  }

  public static void isDateValid(String year, String month, String day)
      throws IllegalFormatPersonException {
    if (!year.matches("^\\d+$"))
      throw new IllegalFormatPersonException("Invalid year format");
    if (!month.matches("^\\d+$"))
      throw new IllegalFormatPersonException("Invalid month format");
    if (!day.matches("^\\d+$")) throw new IllegalFormatPersonException("Invalid day format");

    int yearInt = Integer.parseInt(year);
    int monthInt = Integer.parseInt(month);
    int dayInt = Integer.parseInt(day);

    if (monthInt < 1 || monthInt > 12)
      throw new IllegalFormatPersonException("Invalid month number");
    if (YearMonth.of(yearInt, monthInt).lengthOfMonth() < dayInt)
      throw new IllegalFormatPersonException("Invalid day number");
  }
}
