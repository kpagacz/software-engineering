import java.util.ArrayList;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
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
        } catch (Exception e) {
          System.out.println("Error while parsing");
        }
      }
    }

    for (int i = 0; i < figures.size(); i++) {
      System.out.println("Figure no: " + i);
      System.out.println(figures.get(i));
    }
  }
}
