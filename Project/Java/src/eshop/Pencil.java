package eshop;

public class Pencil extends Item{
    public static final int HB = 0;
    public static final int H = 1;
    public static final int B = 2;
    private int type;
    private double tipSize;
    private static int count = 0;


    Pencil(String name, double price, String description, int stock, int id, double tipSize, int type){
        setName(name);
        setPrice(price);
        setDescription(description);
        setStock(stock);
        this.type = type;
        this.tipSize = tipSize;
        count++;
    }
    public String getDetails(){
       return "Type: " + type + ", Tip size: " + tipSize;
    }
    public static int getCount() {
        return count;
    }

}
