package eshop;

import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.List;

public class ShopingCart {
    private static List<ItemOrdered> orderList = new ArrayList<ItemOrdered>();
    private int buyerCategory;
    ShopingCart(int buyerCategory){
        this.buyerCategory = buyerCategory;
    }
    public static void addItemOrdered(Item item, int quantity) throws ItemOutOfStockException{
        if(item.getStock() < quantity){
            throw new ItemOutOfStockException();
        }else{
            if(!orderList.contains(item)) {
                orderList.add(new ItemOrdered(item, quantity));
                item.setStock(item.getStock() - quantity);
            }else{
                orderList.get(orderList.lastIndexOf(new ItemOrdered(item, quantity))).setQuantity(orderList.get(orderList.lastIndexOf(new ItemOrdered(item, quantity))).getQuantity() + quantity);
                item.setStock(item.getStock() - orderList.get(orderList.lastIndexOf(new ItemOrdered(item, quantity))).getQuantity());
            }
        }
    }

    public void setBuyerCategory(int buyerCategory) {
        this.buyerCategory = buyerCategory;
    }

    public static void removeItemOrdered(Item item){
        ItemOrdered itemOrd = orderList.get(0);
        for(int i = 0; i < orderList.size(); i++){
            if(orderList.get(i).getItem() == item){
                itemOrd  = orderList.get(i);
            }
        }
        itemOrd.getItem().setStock(itemOrd.getQuantity() + itemOrd.getItem().getStock());
        orderList.remove(itemOrd);
    }

    public void changeItemOrderedQuantity(Item item, int quantity) throws ItemOutOfStockException {
        ItemOrdered itemOrd = orderList.get(0);
        for(int i = 0; i < orderList.size(); i++){
            if(orderList.get(i).getItem() == item){
                itemOrd  = orderList.get(i);
            }
        }

        if(itemOrd.getItem().getStock() < quantity) {
            throw new ItemOutOfStockException();
        }else{
            itemOrd.setQuantity(quantity);
        }
    }

    public void showCart(){
        int contents = 0;
        for(int i = 0; i<orderList.size(); i++){
            System.out.println(i+1+":Name: "+orderList.get(i).getItem().getName()+ ", Id: " + orderList.get(i).getItem().getId() +", Price: " + orderList.get(i).getItem().getPrice()+"$" + " Quantity: " + orderList.get(i).getQuantity());
            contents++;
        }
        if(contents == 0){
            System.out.println("The cart is empty");
        }
        System.out.println("Total: " + calculateNet() + " $");
        System.out.println("Courier cost: " + calculateCourierCost(calculateNet()) + " $");
    }

    public void clearCart(){
        for(int i = 0; i<orderList.size(); i++){
            removeItemOrdered(orderList.get(i).getItem());
        }
    }

    public void checkout(boolean confirmation){
        showCart();
        if(confirmation){
            for(int i = 0; i<orderList.size(); i++){
                orderList.remove(i);
            }
        }else{
            System.out.println("Checkout canceled");
        }
    }

    public double calculateCourierCost(double cost){
        if(buyerCategory == 0){
            if(cost+cost*0.2 > 3){
                return cost+cost*0.2;
            }else{
                return 3;
            }
        }else if(buyerCategory == 1){
            return (cost+cost*0.2)/2;
        }else{
            return 0;
        }
    }

    public double calculateNet(){
        double net = 0;
        for(int i = 0; i<orderList.size(); i++){
            net+=(orderList.get(i).getItem().getPrice())*orderList.get(i).getQuantity();
        }
        return net;
    }

}
