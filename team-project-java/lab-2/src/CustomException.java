public class CustomException extends Exception {
    private String message;
    public CustomException(String msg) {
        this.message = msg;
    }

    @Override
    public String getMessage() {
        return message;
    }
}
