package eshop;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;

public class Menu {
    private User loggedUser;
    private EShop shop;

    Menu(EShop shop){
        this.shop = shop;
    }

    public void logIn() throws IOException{
        String email = null;
        String choice;
        BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("\tWelcome to PaperWorks!");
        do {
            try {
                System.out.print("Enter your Email: ");
                email = keyboard.readLine();
                loggedUser = shop.checkBuyer(email);
            } catch (BuyerNotFoundException e) {
                System.out.println("Your email does not exist. Would you like to sign up? [yes/no]");
                choice = keyboard.readLine();
                if (choice.equals("yes")) {
                    String name;
                    String address;
                    int postalCode;
                    System.out.print("Enter your name: ");
                    name = keyboard.readLine();
                    System.out.print("\nEnter your address: ");
                    address = keyboard.readLine();
                    System.out.print("\nEnter your postal code: ");
                    postalCode = Integer.parseInt(keyboard.readLine());
                    Buyer newBuyer = new Buyer(name, email, address, postalCode);
                    loggedUser = newBuyer;
                    try {
                        shop.addBuyer(newBuyer);
                    }catch(BuyerAlreadyExistsException e1){
                        //This will never happen
                        e1.toString();
                    }
                    }else if(choice.equals("no")){
                        email = null;
                    }else{
                        System.out.println("Please enter a valid answer");
                        email = null;
                    }

                }

        }while (email == null) ;
        System.out.flush();
        mainMenu();
    }

    public void mainMenu() throws IOException{
        System.out.println("Hi " + loggedUser.getName());
        String choice = "";
        BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in));
        do {
            if (loggedUser.getClass() == Owner.class) {
                Owner loggedOwner = (Owner) loggedUser;
                System.out.println("Name: " + loggedUser.getName() + "\nEmail: " + loggedUser.getEmail() + "\nAddress: " + loggedUser.getAddress() + "\nPostal Code: " + loggedUser.getPostalCode());
                System.out.println("Choose an option: ");
                System.out.println("1:Browse Store");
                System.out.println("2:Check Status");
                System.out.println("3:Log out");
                System.out.println("4:Quit");
                choice = keyboard.readLine();
                if (choice.equals("1")) {
                    browseStore(true);
                } else if (choice.equals("2")) {
                    String ch_choice;
                    do {
                        shop.checkStatus();
                        System.out.println("1: Delete User\n2: Back");
                        ch_choice = keyboard.readLine();
                        if(ch_choice.equals("1")){
                            String email;
                            System.out.println("Enter users Email");
                            email = keyboard.readLine();
                            try {
                                shop.removeBuyer((Buyer)shop.checkBuyer(email));
                            } catch (BuyerNotFoundException e) {
                                System.out.println("The user was not found");
                            }
                        }
                    }while(!ch_choice.equals("2"));
                } else if (choice.equals("3")) {
                    logIn();
                } else if (choice.equals("4")) {
                    System.exit(0);
                }

            } else if (loggedUser.getClass() == Buyer.class) {
                Buyer loggedBuyer = (Buyer) loggedUser;
                System.out.println("Name: " + loggedUser.getName() + "\nEmail: " + loggedUser.getEmail() + "\nAddress: " + loggedUser.getAddress() + "\nPostal Code: " + loggedUser.getPostalCode() + "\nPoints: " + loggedBuyer.getBuyerPts() + "\nCategory: " + loggedBuyer.getbuyerCategory());
                System.out.println("Choose an option: ");
                System.out.println("1:Browse Store");
                System.out.println("2:View Cart");
                System.out.println("3: Checkout");
                System.out.println("4:Log out");
                System.out.println("5:Quit");

                choice = keyboard.readLine();
                if (choice.equals("1")) {
                    browseStore(false);
                } else if (choice.equals("2")) {
                    String cartChoice = "";
                    do {
                        String item;
                        String quantity;
                        ((Buyer) loggedUser).cart.showCart();
                        System.out.println("1:Remove item\n2:Change item quantity\n3:Clear cart\n4:Checkout\n5:Back");
                        cartChoice = keyboard.readLine();
                        if(cartChoice.equals("1")){
                            System.out.println("Enter item id");
                            item = keyboard.readLine();
                            try {
                                ((Buyer)loggedUser).cart.removeItemOrdered(shop.getItemByld(Integer.parseInt(item)));
                            } catch (ItemNotFoundException e) {
                                System.out.println("Item not found");
                            }
                        }else if(cartChoice.equals("2")){
                            System.out.println("Enter id");
                            item = keyboard.readLine();
                            System.out.print("Enter new quantity");
                            quantity = keyboard.readLine();
                            try {
                                ((Buyer)loggedUser).cart.changeItemOrderedQuantity(shop.getItemByld(Integer.parseInt(item)), Integer.parseInt(quantity));
                            } catch (ItemOutOfStockException e) {
                                System.out.println("Item out of stock");
                            } catch (ItemNotFoundException e) {
                                System.out.println("Item not found");
                            }
                        }else if(cartChoice.equals("3")) {
                            ((Buyer) loggedUser).cart.clearCart();
                        }else if(cartChoice.equals("4")) {
                            String confirmation;
                            System.out.println("Confirm checkout (yes/no)");
                            confirmation = keyboard.readLine();
                            if (confirmation.equals("yes")) {
                                ((Buyer) loggedUser).awardBonus(((Buyer) loggedUser).cart.calculateNet());
                                ((Buyer) loggedUser).cart.checkout(true);
                            } else {
                                ((Buyer) loggedUser).cart.checkout(false);
                            }
                        }else{
                            System.out.println("Invalid option");
                        }
                    }while(!cartChoice.equals("5"));
                } else if (choice.equals("4")) {
                    logIn();
                } else if (choice.equals("5")) {
                    System.exit(0);
                }else if(choice.equals("3")){
                    String confirmation;
                    System.out.println("Confirm checkout (yes/no)");
                    confirmation = keyboard.readLine();
                    if (confirmation.equals("yes")) {
                        ((Buyer) loggedUser).awardBonus(((Buyer) loggedUser).cart.calculateNet());
                        ((Buyer) loggedUser).cart.checkout(true);
                    } else {
                        ((Buyer) loggedUser).cart.checkout(false);
                    }
                }
            }

        }while(Integer.parseInt(choice) != 4);
    }


    public void browseStore(boolean isOwner) throws IOException{
        List<Item> products = new ArrayList<Item>();
        System.out.println("PaperWorks");
        shop.showCategories();
        boolean pass = true;
        BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in));
        do {
            if (keyboard.readLine().equals("1")) {
                products = shop.showProductsInCategory(Pen.class);
            } else if (keyboard.readLine().equals("2")) {
                products = shop.showProductsInCategory(Notebook.class);
            } else if (keyboard.readLine().equals("3")) {
               products = shop.showProductsInCategory(Paper.class);
            } else if (keyboard.readLine().equals("4")) {
                products = shop.showProductsInCategory(Pencil.class);
            } else {
                System.out.println("This option is not valid. Please select one of the above");
                pass = false;
            }
        }while(!pass);
        String bsChoice = "";
        String item;
        String stock;
        if(isOwner){
            do{
                System.out.println("1:Modify item\n2:Back");
                bsChoice = keyboard.readLine();
                if(bsChoice.equals("1")) {
                    System.out.println("Enter item id");
                    item  = keyboard.readLine();
                    System.out.println("Enter new stock");
                    stock = keyboard.readLine();
                    try {
                        shop.updateItemStock(shop.getItemByld(Integer.parseInt(item)), Integer.parseInt(stock));
                    }catch(ItemNotFoundException e){
                        System.out.println("Item not found");
                    }
                }
            }while(!bsChoice.equals("2"));
        }else{
            do{
                System.out.println("1:Add item to cart\n2:Back");
                bsChoice = keyboard.readLine();
                if(bsChoice.equals("1")){
                    System.out.println("Enter item id");
                    item  = keyboard.readLine();
                    System.out.println("Enter quantity");
                    stock = keyboard.readLine();
                    try {
                        ((Buyer)loggedUser).placeOrder(shop.getItemByld(Integer.parseInt(item)), Integer.parseInt(stock));
                    }catch(ItemNotFoundException e){
                        System.out.println("Item not found");
                    }
                }
            }while(!bsChoice.equals("2"));
        }
    }


}
