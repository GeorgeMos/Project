package eshop;

public class ItemOutOfStockException extends Throwable{
    public ItemOutOfStockException(){};
    public String ItemOutOfStockException(String msg){return msg;}
    public String toString(){
        return "Item out of stock";
    }
}
