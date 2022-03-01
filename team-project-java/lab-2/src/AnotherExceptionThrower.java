public class AnotherExceptionThrower {
    public static void g() throws CustomException {
        throw new CustomException("Custom exception");
    }

    public static void f() throws AnotherCustomException {
        try {
            g();
        } catch (CustomException e) {
            throw new AnotherCustomException("CustomException thrown from g()");
        }
    }

    public static void throwRuntimeException() {
        try {
            g();
        } catch (CustomException e) {
            throw new RuntimeException("Caught custom exception from g()");
        }
    }
}
