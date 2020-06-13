package eshop;

public class Buyer extends User {
    public static final int BRONZE = 0;
    public static final int SILVER = 1;
    public static final int GOLD = 2;
    private int buyerPts = 0;
    private int buyerCategory;
    public ShopingCart cart = new ShopingCart(buyerCategory);

    Buyer(String name, String email, String address, int postalCode){
        setName(name);
        setEmail(email);
        setAddress(address);
        setPostalCode(postalCode);
        this.buyerCategory = BRONZE;
    }

    public int getbuyerCategory() {
        return buyerCategory;
    }

    public void setbuyerCategory() {
        if(buyerPts>=100){
            buyerCategory = SILVER;
        }else if(buyerPts>=200){
            buyerCategory = GOLD;
        }
        cart.setBuyerCategory(buyerCategory);
    }

    public int getBuyerPts() {
        return buyerPts;
    }

    public void awardBonus(double price){
        buyerPts+=(int)(price*0.1);
        setbuyerCategory();
    }
    public void placeOrder(Item item, int quantity){
        try {
            ShopingCart.addItemOrdered(item, quantity);
        } catch (ItemOutOfStockException e) {
            System.out.println("The item is out of stock");
        }
    }
}
