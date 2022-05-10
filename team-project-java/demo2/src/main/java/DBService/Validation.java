package DBService;

public class Validation {
    public static boolean isAuthorized(String user, String passwd) {
        if (user.equals("admin") && passwd.equals("qwerty")) {
            return true;
        }
        else {
            return false;
        }
    }


}

