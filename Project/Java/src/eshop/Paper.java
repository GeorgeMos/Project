package eshop;

public class Paper extends Item{
    private int weight;
    private int pages;
    private static int count = 0;


    Paper(String name, double price, String description, int stock, int id, int weight, int pages){
        setName(name);
        setPrice(price);
        setDescription(description);
        setStock(stock);
        this.weight = weight;
        this.pages = pages;
        count++;
    }
    public String getDetails(){
        return "Weight: " + weight + ", Pages: " + pages;
    }

    public static int getCount() {
        return count;
    }
}