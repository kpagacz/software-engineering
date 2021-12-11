import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Shop shop = new Shop();
    shop.setProducts(
        new ArrayList<>(
            List.of(
                new Product(ProductType.FRUIT, "Jablko", 0.9, 15),
                new Product(ProductType.VEGETABLE, "Ziemniak", 0.4, 10))));

    // The below examples work because the lambdas capture all the final and effectively final
    // variables from the enclosing scope.
    // Task 1
    final double price = 0.5;
    shop.doOnProductList(
        p -> p.getPrice() > price,
        (Product p) -> {
          System.out.println(p.getType());
        });

    // Task 2
    // I wanted to show that it's possible to capture variables provided dynamically during the
    // runtime of the program
    Scanner sc = new Scanner(System.in);
    System.out.print(
        "Input the increase in price (as a decimal fraction of increase from the base price): ");
    final double percent = sc.nextDouble();
    ProductType chosenProductType =
        ProductType
            .FRUIT; // lambda works because this is an effectively final variable (assigned only
    // once)
    shop.doOnProductList(
        p -> p.getType() == chosenProductType, p -> p.setPrice(p.getPrice() * (1 + percent)));

    // Task 3
    System.out.print("Input the name of the product: ");
    final String productName = sc.next();
    shop.doOnProductList(
        p -> Objects.equals(p.getName(), productName), p -> System.out.println(p.getTotalPrice()));

    // Task 4
    final char firstLetter = 'Z';
    shop.doOnProductList(p -> p.getName().charAt(0) == firstLetter, p -> p.setQuantity(0));

    // Task 5
    shop.doOnProductList(p -> true, System.out::println);
  }
}
