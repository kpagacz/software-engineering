import java.text.ParseException;

public class AdminEmployee extends Employee {
    private String fullTime;
    public AdminEmployee(String name, String surname, String startDate, String fullTime) throws ParseException {
        super(name, surname, startDate);
        this.fullTime = fullTime;
    }

    @Override
    public String getDescription() {
        return "Admin employee: " + getName() + " " + getSurname();
    }

    public String getFullTime() {
        return fullTime;
    }
}

