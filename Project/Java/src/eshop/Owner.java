package eshop;

public class Owner extends User {
    private final boolean isAdmin = true;

    Owner(String name, String email, String address, int postalCode){
        setAddress(address);
        setEmail(email);
        setName(name);
        setPostalCode(postalCode);
    }
}
