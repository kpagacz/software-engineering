import java.util.Calendar;

public class Participant {
  private final String name;
  private final String surname;
  private final String pesel;
  private final Calendar birthday;

  public enum Gender {
    MALE,
    FEMALE
  }

  public Participant(String name, String surname, Calendar birthday) {
    this.name = name;
    this.surname = surname;
    this.birthday = birthday;
    this.pesel = Pesel.fromBirthday(birthday, getGender());
  }

  public Calendar getBirthday() {
    return birthday;
  }

  public Gender getGender() {
    if (name.charAt(name.length() - 1) == 'a') return Gender.FEMALE;
    else return Gender.MALE;
  }

  public int getAgeCategory() {
    int age = Calendar.getInstance().get(Calendar.YEAR) - getBirthday().get(Calendar.YEAR);
    if (age < 20) return 1;
    if (age < 30) return 2;
    if (age < 40) return 3;
    return 4;
  }

  public String getName() {
    return name;
  }

  public String getSurname() {
    return surname;
  }

  /**
   * Returns the competition category (including gender and the age category).
   *
   * <p>E.g. M1, F2.
   *
   * @return the category including gender and age category
   */
  public String getCategory() {
    return (getGender() == Gender.FEMALE ? "F" : "M") + getAgeCategory();
  }

  @Override
  public String toString() {
    return name + " " + surname + " " + pesel;
  }

  @Override
  public boolean equals(Object obj) {
    if (obj == null) return false;
    if (obj.getClass() != this.getClass()) return false;
    final Participant other = (Participant) obj;
    return other.pesel.equals(this.pesel);
  }
}
