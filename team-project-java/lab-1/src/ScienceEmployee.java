import java.text.ParseException;
import java.util.GregorianCalendar;

public abstract class ScienceEmployee extends Employee {
    private GregorianCalendar endDate;
    private int hours;
    public ScienceEmployee(String name, String surname, String startDate, int hours) throws ParseException {
        super(name, surname, startDate);
        this.hours = hours;
    }
}
