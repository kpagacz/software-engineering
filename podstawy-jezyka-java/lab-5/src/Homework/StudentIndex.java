package Homework;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class StudentIndex {
  //    lab 2
  String lastName;
  int subjectsCount;
  double[] grades;

  public StudentIndex(String lastName, int subjectsCount) {
    this.lastName = lastName;
    this.subjectsCount = subjectsCount;
    grades = new double[0];
  }

  public void inputGrades() {
    Scanner sc = new Scanner(System.in);
    System.out.format("Input students grades (%d numbers)\n", subjectsCount);
    for (int i = 0; i < subjectsCount; i++) grades[i] = sc.nextFloat();
  }

  public double getHighestGrade() {
    double[] sortedGrades = new double[grades.length];
    System.arraycopy(grades, 0, sortedGrades, 0, grades.length);
    Arrays.sort(sortedGrades);
    return sortedGrades[sortedGrades.length - 1];
  }

  public String getMissingGrades() {
    StringBuilder out = new StringBuilder();
    out.append("Missing grades:");
    if (!Arrays.stream(grades).anyMatch(grade -> grade == 2.0)) out.append(" ").append(2.0);
    for (float i = 3; i <= 5; i += 0.5) {
      float finalI = i;
      if (Arrays.stream(grades).anyMatch(grade -> grade == finalI)) {
        continue;
      } else {
        out.append(" ").append(i);
      }
    }
    return out.toString();
  }

  @Override
  public String toString() {
    StringBuilder out = new StringBuilder();
    out.append("Student's last name: ").append(lastName).append("\n");
    out.append("Grades:");
    for (double grade : grades) out.append(" ").append(grade);
    return out.toString();
  }

  public void print() {
    System.out.println(this);
  }
  //    lab 5
  public void addGrades(double[] grades) throws IllegalArgumentException {
    HashSet<Double> allowedGrades = new HashSet<>(Arrays.asList(2.0, 3.0, 3.5, 4.0, 4.5, 5.0));
    for (double grade : grades) {
      if (!allowedGrades.contains(grade))
        throw new IllegalArgumentException(
            "All the grades must have values in: { 2.0, 3.0, 3.5, 4.0, 4.5, 5.0 }");
    }
    this.grades = grades;
    subjectsCount = grades.length;
  }

  public double calculateMean() {
    return Arrays.stream(grades).reduce(0, Double::sum) / grades.length;
  }
}
