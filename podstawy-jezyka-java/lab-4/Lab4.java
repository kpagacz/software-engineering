import java.util.*;

public class Lab4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Input a number between 0.1 and 9999.99");
        try {
            double user_number = sc.nextDouble();
            if (user_number < 0) throw new ArithmeticException();
            if (user_number < 0.1) throw new ValueOutOfBoundsException();
            if (user_number > 9999.99) throw new ValueOutOfBoundsException();
            double squared = Math.sqrt(user_number);
            System.out.println("Square root of " + user_number + " is " + squared);
        } catch(ValueOutOfBoundsException exc) {
            System.out.println("Value is out of the allowed range.");
        } catch(ArithmeticException exc) {
            System.out.println("Number should be positive.");
        } catch(InputMismatchException exc) {
            System.out.println("The input is not a number.");
        }
    }

}

class ValueOutOfBoundsException extends Exception {
    public ValueOutOfBoundsException() {
        super("ValueOutOfBoundsException - value is out of bounds");
    }
}
