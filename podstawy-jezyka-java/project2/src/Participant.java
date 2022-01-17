import java.util.Calendar;

public class Participant {
  private final String name;
  private final String surname;
  private final String pesel;
  private final Calendar birthday;

  public enum Gender {
    MALE,
    FEMALE
  };

  public Participant(String name, String surname, Calendar birthday) {
    this.name = name;
    this.surname = surname;
    this.birthday = birthday;
    this.pesel = Pesel.fromBirthday(birthday, getGender());
  }

  public Gender getGender() {
    if (surname.charAt(surname.length() - 1) == 'a') return Gender.MALE;
    else return Gender.FEMALE;
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
