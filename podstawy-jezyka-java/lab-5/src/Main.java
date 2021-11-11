import Homework.StudentIndex;

public class Main {
  public static void main(String[] args) {
    StudentIndex student = new StudentIndex("Test", 2);
    student.inputGrades();
    System.out.println(student);
  }
}
