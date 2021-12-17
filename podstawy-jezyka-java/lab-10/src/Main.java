import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.Random;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {
  public static void main(String[] args) {
    Shop shop = new Shop();
    shop.setProducts(
        new ArrayList<>(
            List.of(
                new Product(ProductType.FRUIT, "Jablko", 0.9, 15),
                new Product(ProductType.FRUIT, "Sliwka", 1.1, 13),
                new Product(ProductType.VEGETABLE, "Ziemniak", 0.4, 10),
                new Product(ProductType.VEGETABLE, "Marchewka", 0.6, 20),
                new Product(ProductType.OTHER, "Sok", 2.0, 5))));

    // Task 1
    System.out.println("Subtask 1");
    System.out.println(shop.sumQuantity());

    System.out.println("Subtask 2");
    shop.getShortProductDescriptions().forEach(System.out::println);

    System.out.println("Subtask 3");
    shop.lowerFruitPrices(0.05);

    System.out.println("Subtask 4");
    shop.printCheapProducts();

    System.out.println("Subtask 5");
    shop.getProductCountsMap().forEach((key, value) -> System.out.println(key + " - " + value));

    System.out.println("Subtask 6");
    System.out.println(shop.isAnyVegetableEndingOnA());

    // Task 2
    System.out.println("Task 2 - subtask 1");
    double result = IntStream.range(1, 101).mapToDouble(el -> ((double) el + 1) / (el * el)).sum();
    System.out.println(result);

    System.out.println("Task 2 - subtask 2");
    Random rng = new Random();
    double avg =
        rng.ints(15, 1, 101)
            .sorted()
            .limit(5)
            .peek(System.out::println)
            .average()
            .orElse(Double.NaN);
    System.out.println(avg);

    System.out.println("Task 2 - subtask 3");
    List<List<Double>> outerList = new ArrayList<>();
    for (int i = 0; i < 10; i++) outerList.add(new ArrayList<>());
    avg =
        outerList.stream()
            .peek(l -> l.addAll(rng.doubles(10, 0, 1).boxed().collect(Collectors.toList())))
            .flatMap(Collection::stream)
            .mapToDouble(Double::doubleValue)
            .average()
            .orElse(Double.NaN);
    System.out.println(avg);

    System.out.println("Task 2 - subtask 4");
    String chars =
        rng.ints(10, 0, 26)
            .mapToObj(i -> (char) ('a' + i))
            .collect(
                Collector.of(
                    StringBuilder::new,
                    StringBuilder::append,
                    StringBuilder::append,
                    StringBuilder::toString));
    System.out.println(chars);
  }
}
