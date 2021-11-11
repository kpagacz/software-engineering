package Homework;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class StudentIndexTest {
  @Test
  void getHighestGrade() {
    StudentIndex student = new StudentIndex("test", 2);
    student.addGrades(new double[] {2, 3});
    assertEquals(student.getHighestGrade(), 3);
  }

  @Test
  void getMissingGrades() {
    StudentIndex student = new StudentIndex("test", 2);
    assertEquals("Missing grades: 2.0 3.0 3.5 4.0 4.5 5.0", student.getMissingGrades());
    student.addGrades(new double[] {2, 3, 3.5, 4, 4.5, 5});
    assertEquals("Missing grades:", student.getMissingGrades());
  }

  @Test
  void testToString() {
    StudentIndex student = new StudentIndex("test", 2);
    assertEquals("Student's last name: test\n" + "Grades:", student.toString());
  }

  @Test
  @DisplayName("addGrades throws IllegalArgument if passed a value outside of the allowed set")
  void addGrades() {
    StudentIndex student = new StudentIndex("test", 2);
    assertAll(
        () ->
            assertThrows(IllegalArgumentException.class, () -> student.addGrades(new double[] {0})),
        () ->
            assertThrows(
                IllegalArgumentException.class,
                () -> student.addGrades(new double[] {Double.MAX_VALUE})));
  }

  @Test
  void calculateMean() {
    StudentIndex student = new StudentIndex("test", 2);
    student.addGrades(new double[] {2, 3, 4});
    assertEquals(student.calculateMean(), 3);

    student.addGrades(new double[] {2, 3});
    assertEquals(student.calculateMean(), 2.5);
  }
}
