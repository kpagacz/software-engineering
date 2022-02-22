import java.text.ParseException;

public class DepartmentEmployee extends ScienceEmployee {
    public DepartmentEmployee(String name, String surname, String startDate, int hours) throws ParseException {
        super(name, surname, startDate, hours);
    }
    @Override
    public String getDescription() {
        return "Department employee: " + getName() + " " + getSurname();
    }
}
