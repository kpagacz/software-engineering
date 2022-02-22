import java.text.ParseException;

public class DepartmentHead extends ScienceEmployee {
    private double bonus;
    public DepartmentHead(String name, String surname, String startDate, int hours, double bonus) throws ParseException {
        super(name, surname, startDate, hours);
        this.bonus = bonus;
    }
    public String getDescription() {
        return "Department Head: " + getName() + " " + getSurname();
    }

    @Override
    public double getSalary() {
        return super.getSalary() + bonus;
    }
}

