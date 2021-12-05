import java.util.ArrayList;

public class School {
  private static String name;
  private static ArrayList<Pupil> pupils;
  private static final School instance = new School();

  private School() {
    pupils = new ArrayList<Pupil>();
  }

  public static School getInstance() {
    return instance;
  }

  public static String getName() {
    return name;
  }

  public static void setName(String name) {
    School.name = name;
  }

  public static ArrayList<Pupil> getPupils() {
    return pupils;
  }

  public static void setPupils(ArrayList<Pupil> pupils) {
    School.pupils = pupils;
  }

  @Override
  public String toString() {
    StringBuilder answer = new StringBuilder("School: " + name);
    answer.append("\n");
    for(Pupil p : getPupils()) {
      answer.append(p.toString()).append("\n");
    }

    return answer.toString();
  }
}
