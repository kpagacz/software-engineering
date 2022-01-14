import java.io.FileInputStream;
import java.io.IOException;
import java.nio.file.FileSystems;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Main {
  private final static Logger logger = Logger.getLogger(Main.class.getName());

  public static void main(String[] args) {
    // set up the configuration
    Properties appConfig = new Properties();
    try {
      appConfig.load(new FileInputStream(FileSystems.getDefault().getPath("lab-13/Config.properties").toString()));
    } catch (IOException e) {
      e.printStackTrace();
      return;
    }
    logger.log(Level.FINER, "Calculation type: " + appConfig.get("calculationType"));

    // set up the locale
    Locale currentLocale = Locale.getDefault();
    logger.log(Level.FINER,"Current locale: " + currentLocale.toString());
    ResourceBundle outputStrings = ResourceBundle.getBundle("Output", currentLocale);

    // read input
    Scanner sc = new Scanner(System.in);
    double a = 0, b = 0, c = 0;
    try {
      System.out.print(outputStrings.getObject("input"));
      a = sc.nextDouble();
      b = sc.nextDouble();
      c = sc.nextDouble();
    } catch (NoSuchElementException | IllegalStateException e) {
      e.printStackTrace();
      return;
    }

    // perform calculations
    if (!isValidTriangle(a, b, c)) {
      System.out.println(
        outputStrings.getObject("sides1") + ": " + a + " " + b + " " + c + " " +
        outputStrings.getObject("sides2") + "."
      );
      return;
    }
    double sum = a + b + c;
    switch (appConfig.get("calculationType").toString()) {
      case "area" -> {
        double area = Math.sqrt(sum/2 * (sum/2 - a) * (sum/2 - b) * (sum/2 - c));
        System.out.println(outputStrings.getObject("area") + ": " + area);
      }
      case "circumference" -> {
        System.out.println(outputStrings.getObject("circumference")+": " + sum);
      }
      default -> {
        System.out.println(outputStrings.getObject("default"));
      }
    }
  }

  private static boolean isValidTriangle(double a, double b, double c) {
    return a + b > c && b + c > a && a + c > a;
  }
}
