public class Main {
  public static void main(String[] args) {
      // Task 1
      System.out.println("Task 1");
      try {
          throw new Exception("This is an Exception.");
      } catch(Exception e) {
          System.out.println("Exception message: " + e.getMessage());
      } finally {
          System.out.println("Try-catch finished.");
      }
      // Task 2
      System.out.println("Task 2");

      try {
          throw new CustomException("My custom exception");
      } catch (CustomException e){
          System.out.println("Exception message: " + e.getMessage());
      }

      // Task 3
      System.out.println("Task 3");

      try {
          ExceptionThrower.throwException();
      } catch (CustomException e) {
          System.out.println("Exception message: " + e.getMessage());
      }

      // Task 4
      System.out.println("Task 4");

      Object object = null;
      try {
          object.getClass();
      } catch(Exception e) {
          System.out.println("Exception message: " + e.getMessage());
      }

      // Task 5
      System.out.println("Task 5");

      try {
        AnotherExceptionThrower.f();
      } catch (AnotherCustomException e) {
          System.out.println("Exception message: " + e.getMessage());
      }

      // Task 6
      System.out.println("Task 6");

      try {
          AnotherExceptionThrower.throwRuntimeException();
      } catch (RuntimeException e) {
          System.out.println("Runtime exception thrown");
      }

      // Task 7
      System.out.println("Task 7");

      try {
          ExceptionThrower.throwThreeExceptions();
      } catch (CustomException | AnotherCustomException | YetAnotherException e) {
          System.out.println(e.getMessage());
      }

      // Task 8
      System.out.println("Task 8");

      try {
          int[] arr = new int[1];
          int outOfBounds = arr[2];
      } catch (IndexOutOfBoundsException e) {
          System.out.println(e.getMessage());
      }

      // Task 9
      System.out.println("Task 9");

      boolean thrown = true;
      int i = 0;
      while (thrown) {
          try {
              i++;
              if (i < 3) throw new Exception("i < 3");
              else thrown = false;
          } catch (Exception e){
              System.out.println("Exception thrown: " + e.getMessage());
          }
      }

      // Task 10
      System.out.println("Task 10");

      C c = new C();
      A a = (A) c;
      try {
          c.throwException();
      } catch(GrandParentException e) {
          System.out.println(e.getMessage());
      }

      // Task 11


      // Task 12
      System.out.println("Task 12");
      try {
          ExceptionThrower.throwThreeExceptions();
      } catch (CustomException | AnotherCustomException | YetAnotherException e) {
          System.out.println(e.getMessage());
      } finally {
          System.out.println("Finally executed task 12");
      }

  }
}
