package eshop;

public class ItemOrdered {
    private Item item;
    private int quantity;

    ItemOrdered(Item item, int quantity){
        this.item = item;
        this.quantity = quantity;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public Item getItem() {
        return item;
    }
}
