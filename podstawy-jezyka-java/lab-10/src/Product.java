import java.util.Comparator;

public class Product {
  private final ProductType productType;
  private final String name;
  private double price;
  private int quantity;

  public Product(ProductType productType, String name, double price, int quantity) {
    this.productType = productType;
    this.name = name;
    this.price = price;
    this.quantity = quantity;
  }

  public ProductType getType() {
    return productType;
  }

  public double getPrice() {
    return price;
  }

  public void setPrice(double price) {
    this.price = price;
  }

  public String getName() {
    return name;
  }

  public int getQuantity() {
    return this.quantity;
  }

  public String toSimpleString() {
    return productType.getNameInPolish() + " " + getName();
  }

  private double getGrossPrice() {
    return price * (1 + productType.getVat());
  }

  @Override
  public String toString() {
    return getName()
        + ", "
        + productType.getNameInPolish()
        + ", Cena netto "
        + String.format("%.2f", price)
        + " zl, Cena brutto: "
        + String.format("%.2f", getGrossPrice())
        + " zl, w sklepie sztuk: "
        + quantity;
  }

  static class ProductComparator implements Comparator<Product> {
    @Override
    public int compare(Product o1, Product o2) {
      return Double.compare(o1.getPrice(), o2.getPrice());
    }
  }
}
