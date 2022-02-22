import java.text.ParseException;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws ParseException {
        ArrayList<Employee> employees = new ArrayList<>();
        employees.add(new AdminEmployee("Adam", "Pracownik", "18 02 1992", "full"));
        employees.add(new DepartmentEmployee("Barbara", "Pracownik", "19 02 2000", 190));
        employees.add(new DepartmentHead("Cecylia", "Pracowniczka", "10 12 2020", 100, 1000));
        employees.forEach(System.out::println);
    }
}
