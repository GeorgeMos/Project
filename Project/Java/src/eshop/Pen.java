package eshop;

public class Pen extends Item{
    private String color;
    private double tipSize;
    private static int count = 0;
    Pen(String name, double price, String description, int stock, int id,String color, double tipSize){
        setName(name);
        setPrice(price);
        setDescription(description);
        setStock(stock);
        setId(id);
        this.color = color;
        this.tipSize = tipSize;
        count++;
    }

    public String getDetails(){
        return "Color: " + color + ", Tip size: " + tipSize;
    }
    public static int getCount() {
        return count;
    }
}
