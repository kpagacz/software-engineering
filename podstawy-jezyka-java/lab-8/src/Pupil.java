import java.util.Objects;

public class Pupil implements Cloneable {
  private final String name, surname, birthday;

  public Pupil(String name, String surname, String birthday) {
    this.name = name;
    this.surname = surname;
    this.birthday = birthday;
  }

  public final String getName() {
    return name;
  }

  @Override
  public final Pupil clone() throws CloneNotSupportedException {
    return (Pupil) super.clone();
  }

  @Override
  public final boolean equals(Object obj) {
    if (!(obj instanceof Pupil other)) return false;
    if (!(this.name.equals(other.name))) return false;
    if (!(this.surname.equals(other.surname))) return false;
    return this.birthday.equals(other.birthday);
  }

  @Override
  public final int hashCode() {
    return Objects.hash(name, surname, birthday);
  }

  @Override
  public final String toString() {
    return "Pupil Name: " + name + " Surname: " + surname + " Birthday: " + birthday;
  }
}
