import java.util.Random;

public class ExceptionThrower {
    public static void throwException() throws CustomException {
        throw new CustomException("Exception thrown from ExceptionThrower");
    }

    public static void throwThreeExceptions() throws CustomException, AnotherCustomException, YetAnotherException {
        Random rng = new Random();
        double random = rng.nextDouble();
        if (random < 0.3) {
            throw new CustomException("Below 0.3");
        } else if (random < 0.6) {
            throw new AnotherCustomException("Below 0.6");
        } else {
            throw new YetAnotherException("Below 1");
        }
    }
}
