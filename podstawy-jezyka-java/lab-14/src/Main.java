import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Random;
import java.util.Scanner;

/**
 * This program assumes a running mySQL instance on port 3306 with a user `root`, password `root`
 * and an already created schema `test`. I couldn't make it work with the JDBC driver without
 * manually creating the schema before connecting with the driver (got a "No database selected"
 * error).
 *
 * <p>I have installed the latest mysql-connector-java via the intellij's .iml configuration file (which sets
 * up the the dependency from the Maven repository).
 */
public class Main {
  public static void main(String[] args) throws Exception {
    // establish the connection
    Connection conn;
    try {
      conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "root");
    } catch (SQLException e) {
      throw new Exception("Error connecting to the database.", e);
    }

    // create a table and insert records
    Statement stmt;
    ArrayList<String> names =
        new ArrayList<>(
            List.of(
                "Anna",
                "Beata",
                "Cecylia",
                "Dawid",
                "Eustachy",
                "Filip",
                "Grzegorz",
                "Halina",
                "Irena",
                "Justyna"));
    try {
      stmt = conn.createStatement();
      stmt.execute(
          "CREATE TABLE IF NOT EXISTS players("
              + "    id int NOT NULL PRIMARY KEY AUTO_INCREMENT,"
              + "    name varchar(255) NOT NULL,"
              + "    result int"
              + ");");

      Random rng = new Random();
      for (String name : names) {
        int random = rng.nextInt(10) + 1;
        stmt.execute("INSERT INTO players(name, result) values('" + name + "'," + random + ");");
      }
    } catch (SQLException throwable) {
      throwable.printStackTrace();
    }

    // user input
    Scanner sc = new Scanner(System.in);
    System.out.println("Input an integer between 1 and 10");
    int value;
    try {
      value = sc.nextInt();
    } catch (NoSuchElementException | IllegalArgumentException e) {
      throw new Exception("Error reading the value.", e);
    }

    // print the names
    ResultSet res;
    try {
      stmt = conn.createStatement();
      res = stmt.executeQuery("SELECT name from players where result > " + value + ";");
      while (res.next()) {
        System.out.println(res.getString("name"));
      }
    } catch (SQLException e) {
      e.printStackTrace();
    }
  }
}
