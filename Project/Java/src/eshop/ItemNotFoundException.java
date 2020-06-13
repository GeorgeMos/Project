package eshop;

public class ItemNotFoundException extends Throwable {
    public ItemNotFoundException(){};
    public String ItemNotFoundException(String msg){return msg;}
    public String toString(){
        return "Item not found";
    }
}
