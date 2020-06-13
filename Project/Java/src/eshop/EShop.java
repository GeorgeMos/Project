package eshop;

import java.util.ArrayList;
import java.util.List;

public class EShop {
    private String name;
    private Owner owner;
    private List<Buyer> buyersList = new ArrayList<Buyer>();
    private List<Item> itemsList = new ArrayList<Item>();

    EShop(Owner owner){
        this.owner = owner;
    }

    public User checkBuyer(String email)throws BuyerNotFoundException{
        boolean pass = false;
        int saveI = 0;
        for(int i = 0; i<buyersList.size(); i++){
            if((buyersList.get(i).getEmail()).equals(email)){
                pass = true;
                saveI = i;
            }
        }

        if(owner.getEmail().equals(email) && !pass){
            return owner;
        }

        if(pass){
            return buyersList.get(saveI);
        }else{
            throw new BuyerNotFoundException();
        }
    }

    public void addItem(Item item){
        if(!itemsList.contains(item)){
            itemsList.add(item);
        }
    }

    public Item getItemByld(int id) throws ItemNotFoundException{
        for(int i = 0; i < itemsList.size(); i++){
            if(itemsList.get(i).getId() == id){
                return itemsList.get(i);
            }
        }
        throw new ItemNotFoundException();
    }

    public void removeItem(Item item) throws ItemNotFoundException{

        itemsList.remove(item);
    }

    public void addBuyer(Buyer buyer)throws BuyerAlreadyExistsException{
        if(buyersList.contains(buyer)){
            throw new BuyerAlreadyExistsException();
        }else{
            buyersList.add(buyer);
        }
    }

    public void removeBuyer(Buyer buyer) throws BuyerNotFoundException{
        buyer.cart.clearCart();
        buyersList.remove(buyer);
    }

    public void updateItemStock(Item item, int stock){
        item.setStock(stock);

    }

    public void showCategories(){
        System.out.println("1:Pen("+Pen.getCount()+")" + "\n2:Notebook("+Notebook.getCount() + ")" + "\n3:Paper("+Paper.getCount()+")" + "\n4:Pencil("+Pencil.getCount()+")");
    }

    public List<Item> showProductsInCategory(Class cat){
        List<Item> products = new ArrayList<Item>();
       for(int i = 0; i<itemsList.size(); i++){
           if(itemsList.get(i).getClass() == cat){
               products.add(itemsList.get(i));
               System.out.println(i+1 + ":"+itemsList.get(i).toString());
           }
       }
       return products;
    }

    public void showProduct(Item item) throws ItemNotFoundException{
        System.out.println(item.toString());
        throw new ItemNotFoundException();
    }

    public void checkStatus(){
        for(int i = 0; i<buyersList.size(); i++){
            System.out.print("Name: " + buyersList.get(i).getName() + " Email: " + buyersList.get(i).getEmail() + " Points: " + buyersList.get(i).getBuyerPts() + " Category: ");
            if(buyersList.get(i).getbuyerCategory() == 0){
                System.out.println("Bronze");
            }else if(buyersList.get(i).getbuyerCategory() == 1){
                System.out.println("Silver");
            }else{
                System.out.println("Gold");
            }
        }
    }
}
