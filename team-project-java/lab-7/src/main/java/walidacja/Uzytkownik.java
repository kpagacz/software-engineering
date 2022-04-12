package walidacja;

public class Uzytkownik {
    public static boolean czyAutoryzowany(String user, String haslo) {
        if (user.equals("admin") && haslo.equals("1234")) {
            return true;
        }

        return false;
    }
}
