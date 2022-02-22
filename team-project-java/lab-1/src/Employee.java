import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;

public abstract class Employee {
  private String name, surname;
  private GregorianCalendar startDate;
  private static int nextId = 1;
  private int id;
  private double salary;

  public Employee(String name, String surname, String startDate) throws ParseException {
    this.name = name;
    this.surname = surname;
    DateFormat df = new SimpleDateFormat("dd MM yyyy");
    Date date = df.parse(startDate);
    this.startDate = new GregorianCalendar();
    this.startDate.setTime(date);
  }

  public abstract String getDescription();

  public String getName() {
    return name;
  }

  public String getSurname() {
    return surname;
  }

  public GregorianCalendar getStartDate() {
    return startDate;
  }

  public double getSalary() {
    return salary;
  }

  @Override
  public String toString() {
    return getDescription();
  }
}
