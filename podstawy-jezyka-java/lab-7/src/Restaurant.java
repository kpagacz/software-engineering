import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Restaurant {
  HashMap<Integer, String> meals =
      new HashMap<>(
          Map.ofEntries(
              new AbstractMap.SimpleEntry<>(1, "Zupa pomidorowa"),
              new AbstractMap.SimpleEntry<>(2, "Krupnik"),
              new AbstractMap.SimpleEntry<>(3, "Gulasz"),
              new AbstractMap.SimpleEntry<>(4, "Pierogi"),
              new AbstractMap.SimpleEntry<>(5, "Rolada z kurczaka"),
              new AbstractMap.SimpleEntry<>(6, "Ziemniaki"),
              new AbstractMap.SimpleEntry<>(7, "Kasza gryczana"),
              new AbstractMap.SimpleEntry<>(8, "Kasza jęczmienna"),
              new AbstractMap.SimpleEntry<>(9, "Surówka z kapusty kiszonej"),
              new AbstractMap.SimpleEntry<>(10, "Buraki"),
              new AbstractMap.SimpleEntry<>(11, "Sernik")));
  HashMap<Integer, Double> prices =
      new HashMap<>(
          Map.ofEntries(
              new AbstractMap.SimpleEntry<>(1, 4.0),
              new AbstractMap.SimpleEntry<>(2, 4.0),
              new AbstractMap.SimpleEntry<>(3, 9.0),
              new AbstractMap.SimpleEntry<>(4, 9.5),
              new AbstractMap.SimpleEntry<>(5, 9.0),
              new AbstractMap.SimpleEntry<>(6, 4.0),
              new AbstractMap.SimpleEntry<>(7, 3.5),
              new AbstractMap.SimpleEntry<>(8, 3.5),
              new AbstractMap.SimpleEntry<>(9, 4.0),
              new AbstractMap.SimpleEntry<>(10, 4.0),
              new AbstractMap.SimpleEntry<>(11, 6.0)));
  ArrayList<ArrayList<Integer>> orders = new ArrayList<>();
  int mealOfTheDay;

  public Restaurant(int mealOfTheDay) {
    this.mealOfTheDay = mealOfTheDay;
  }

  /**
   * Creates a new order.
   *
   * @return the number of the order
   */
  public int newOrder() {
    orders.add(new ArrayList<>());
    return orders.size() - 1;
  }

  public void addMealToOrder(int meal, int order) throws IllegalArgumentException {
    if (orders.size() < order)
      throw new IllegalArgumentException("Order with this number does not exist");
    if (!meals.containsKey(meal))
      throw new IllegalArgumentException("Meal with this number does not exist");

    orders.get(order).add(meal);
  }

  /**
   * Checks whether an order has the meal of the day in it.
   *
   * @param order the number of the order
   * @return true if the order has the meal of the day in it; false otherwise
   */
  public boolean hasMealOfTheDay(int order) throws IllegalArgumentException {
    if (orders.size() < order)
      throw new IllegalArgumentException("Order with this number does not exist");
    return orders.get(order).contains(mealOfTheDay);
  }

  public int getOrderSize(int order) throws IllegalArgumentException {
    if (orders.size() < order)
      throw new IllegalArgumentException("Order with this number does not exist");
    return orders.get(order).size();
  }

  public double getOrderTotal(int order) throws IllegalArgumentException {
    if (orders.size() < order)
      throw new IllegalArgumentException("Order with this number does not exist");
    double sum = 0;
    for (int mealNumber : orders.get(order)) sum += prices.get(mealNumber);
    return sum;
  }

  public void printOrder(int order) {
    if (orders.size() < order)
      throw new IllegalArgumentException("Order with this number does not exist");
    System.out.println("Order no: " + order);
    for (int mealNumber : orders.get(order))
      System.out.println(meals.get(mealNumber) + " " + prices.get(mealNumber) + " zl");
  }
}
