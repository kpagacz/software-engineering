public class Product {
  private ProductType productType;
  private String name;
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

  public double getTotalPrice() {
    return quantity * price;
  }

  public void setQuantity(int i) {
    this.quantity = i;
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
}
