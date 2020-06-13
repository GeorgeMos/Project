package eshop;

public class BuyerNotFoundException extends Throwable {
    public BuyerNotFoundException(){};
    public String BuyerNotFoundException(String msg){return msg;}
    public String toString(){
        return "Buyer not found";
    }
}
