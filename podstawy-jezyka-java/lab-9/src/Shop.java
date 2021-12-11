import java.util.ArrayList;
import java.util.function.Consumer;
import java.util.function.Predicate;

public class Shop {
  private ArrayList<Product> products;

  public void doOnProductList(Predicate<Product> predicate, Consumer<Product> consumer) {
    for (Product p : products) {
      if (predicate.test(p)) consumer.accept(p);
    }
  }

  public void setProducts(ArrayList<Product> products) {
    this.products = products;
  }
}
