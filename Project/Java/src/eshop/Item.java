package eshop;

abstract class Item {
    private String name;
    private double price;
    private String description;
    private int stock;
    private int id;

    public String getBasicInfo(){
       return "Name: " + name + ", Price: " + price + ", Description: " + description + ", Stock: " + stock + ", Id: " + id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setStock(int stock) {
        this.stock = stock;
    }

    public int getStock() {
        return stock;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public double getPrice() {
        return price;
    }

    abstract String getDetails();

    @Override
    public String toString(){
        return getBasicInfo() + ", " + getDetails();
    }

}