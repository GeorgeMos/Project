package eshop;

public class BuyerAlreadyExistsException extends Throwable {
    public BuyerAlreadyExistsException(){};
    public String BuyerAlreadyExistsException(String msg){return msg;}
    public String toString(){
        return "Buyer already exists";
    }
}