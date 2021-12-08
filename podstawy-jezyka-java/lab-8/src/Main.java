import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args){
        School school = School.getInstance();
        School.setName("Akademia Pana Kleksa");
        System.out.println(school);

        Pupil adam1 = new Pupil("Adam", "1", "Ktoz to wie");
        Pupil adas = new Pupil("Adas", "Jedyny", "Ktoz to wie");

        System.out.println("Pupils:");
        System.out.println(adam1);
        System.out.println(adas);

        ArrayList<Pupil> pupils = new ArrayList<>(List.of(adam1, adas));
        School.setPupils(pupils);
        System.out.println("School again:");
        System.out.println(school);

        System.out.println(Coder.code(adas.getName()));
        System.out.println(Coder.code("Kowalska"));
    }
}
