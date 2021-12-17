import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Shop {
  private ArrayList<Product> products;

  public void setProducts(ArrayList<Product> products) {
    this.products = products;
  }

  public int sumQuantity() {
    return products.stream().mapToInt(Product::getQuantity).sum();
  }

  public List<String> getShortProductDescriptions() {
    return products.stream().map(Product::toSimpleString).collect(Collectors.toList());
  }

  public void lowerFruitPrices(double discount) {
    ArrayList<Product> updatedProducts =
        products.stream()
            .peek(
                p -> {
                  if (p.getType() == ProductType.FRUIT) p.setPrice(p.getPrice() * (1 - discount));
                })
            .collect(Collectors.toCollection(ArrayList::new));
    setProducts(updatedProducts);
  }

  public void printCheapProducts() {
    products.stream()
        .filter(p -> p.getPrice() < 1)
        .sorted(new Product.ProductComparator())
        .map(Product::toSimpleString)
        .forEach(System.out::println);
  }

  public Map<String, Integer> getProductCountsMap() {
    return products.stream().collect(Collectors.toMap(Product::getName, Product::getQuantity));
  }

  public boolean isAnyVegetableEndingOnA() {
    return products.stream().anyMatch(p -> p.getName().charAt(p.getName().length() - 1) == 'a');
  }
}
