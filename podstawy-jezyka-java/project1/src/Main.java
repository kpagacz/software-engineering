import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.logging.*;

public class Main {
  public static void main(String[] args) throws IOException {
    // logging configuration
    Logger globalLogger = Logger.getLogger("");
    for (Handler h : globalLogger.getHandlers())
      if (h instanceof ConsoleHandler) globalLogger.removeHandler(h);
    Logger logger = Logger.getLogger("Main");
    logger.addHandler(new FileHandler("logs-figures.log"));
    logger.info("Main entrypoint reached.");

    int figuresNumber;
    Scanner sc = new Scanner(System.in);
    System.out.println("Input number of figures:");
    figuresNumber = sc.nextInt();
    sc.nextLine(); // because nextInt left a newline character

    ArrayList<Figure> figures = new ArrayList<>();
    for (int i = 0; i < figuresNumber; i++) {
      while (true) {
        String line;
        try {
          System.out.println("Input figure no " + i + ":");
          line = sc.nextLine();
          figures.add(Figure.fromString(line));
          break;
        } catch (FigureParseException e) {
          System.err.println("Error parsing a figure");
          e.printStackTrace();
        } catch (Exception e) {
          System.err.println("Error while parsing");
        }
      }
    }

    for (int i = 0; i < figures.size(); i++) {
      System.out.println("Figure no: " + i);
      System.out.println(figures.get(i));
    }
  }
}
