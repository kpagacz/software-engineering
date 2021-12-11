public enum ProductType {
  FRUIT("Owoc", 0.08),
  VEGETABLE("Warzywo", 0.08),
  OTHER("Inne", 0.23);

  private String nameInPolish;
  private double vat;

  private ProductType(String name, double vat) {
    nameInPolish = name;
    this.vat = vat;
  }
  ;

  public double getVat() {
    return vat;
  }

  public String getNameInPolish() {
    return nameInPolish;
  }
}
