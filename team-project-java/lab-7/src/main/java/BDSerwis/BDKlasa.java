package BDSerwis;

import com.sun.rowset.CachedRowSetImpl;

import java.sql.*;
import java.util.Properties;

public class BDKlasa {
    private static Connection conn = null;

    public static void polaczBD() throws SQLException, ClassNotFoundException {
      String url = "jdbc:mysql://localhost:3306/pracownicy";
        Properties prop = new Properties();
        prop.setProperty("user","root");
        prop.setProperty("password","root");

        try {
            conn = DriverManager.getConnection(url, prop);
        } catch (SQLException e) {
            System.out.println("Błąd z połączeniem z bazą danych.");
            throw e;
        }

        System.out.println("Połączono z bazą danych.");
    }

   public static void rozlaczBD() throws SQLException {
       try {
           if (conn != null && !conn.isClosed()) {
               conn.close();
               System.out.println("Zamknięto połączenie z bazą danych.");
           }
       } catch (SQLException e) {
           System.out.println("Błąd z zamknięciem połączenia z bazą danych.");
           throw e;
       }
   }

   public static void wykonajDMLSQL(String instrukcjaSQL) throws SQLException, ClassNotFoundException {
       Statement stat = null;

       try {
           polaczBD();
           stat = conn.createStatement();
           stat.execute(instrukcjaSQL);
       } catch (SQLException | ClassNotFoundException e) {
           System.out.println("Błąd z wykonaniem instruckji SQL typu DML.");
           throw e;
       }
       finally {
           assert stat != null;
           if (!stat.isClosed()) {
               stat.close();
           }
           rozlaczBD();
       }
   }

   public static ResultSet pobierzDane(String instrukcjaSQL) throws SQLException, ClassNotFoundException {
        Statement stat = null;
        ResultSet resultSet = null;
        CachedRowSetImpl cachedRowSet;


       try {
           polaczBD();
           stat = conn.createStatement();
           resultSet = stat.executeQuery(instrukcjaSQL);
           cachedRowSet = new CachedRowSetImpl();
           cachedRowSet.populate(resultSet);
       } catch (SQLException | ClassNotFoundException e) {
           System.out.println("Błąd z wykonaniem zapytania pobierającego dane!");
           throw e;
       } finally {
           rozlaczBD();
           if (stat!=null && !stat.isClosed()) {
               stat.close();
           }
       }


       return cachedRowSet;
   }

}
