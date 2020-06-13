package eshop;

public class Notebook extends Item{
    private int sections;
    private static int count = 0;

    Notebook(String name, double price, String description, int stock, int id, int sections){
        setName(name);
        setPrice(price);
        setDescription(description);
        setStock(stock);
        this.sections = sections;
        count++;
    }
    public String getDetails(){
        return "Sections: " + sections;
    }
    public static int getCount() {
        return count;
    }

}
