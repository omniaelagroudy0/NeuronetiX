#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_ITEMS = 10;  // Maximum number of products allowed in the cart

class Product {
private:
    string name;
    string description;
    double price;
    int stockQuantity;

public:
    // Constructors
    Product() : name(""), description(""), price(0.0), stockQuantity(0) {}
    Product(string n, string des, double p, int s) : name(n), description(des), price(p), stockQuantity(s) {}

    // Getters
    string getName() const { return name; }
    string getDescription() const { return description; }
    double getPrice() const { return price; }
    int getStockQuantity() const { return stockQuantity; }

    // Method to reduce stock quantity
    void reduceStock(int quantity) { stockQuantity -= quantity; }
    
    // Method to increase stock quantity
    void increaseStock(int quantity) { stockQuantity += quantity; }
    
    // Display product details
    void displayProduct() const {
        cout << "Product: " << name << "\n"
             << "Description: " << description << "\n"
             << "Price: $" << fixed << setprecision(2) << price << "\n"
             << "In Stock: " << stockQuantity << "\n";
    }
};

class Cart {
private:
    // Struct to store each item in the cart
    struct CartItem {
        Product product;  // Product object
        int quantity;     // Quantity of the product
    };

    CartItem items[MAX_ITEMS];  // Array to store products in the cart
    int itemCount;              // Number of items in the cart

public:
    // Constructor
    Cart() : itemCount(0) {}

    // Add a product to the cart
    void addItem(const Product& product, int qty) {
        if (itemCount < MAX_ITEMS) {  // Check if cart is not full
            items[itemCount].product = product;  // Add product to cart
            items[itemCount].quantity = qty;     // Set the quantity
            itemCount++;  // Increase the item count
        } else {
            cout << "The cart is full. Cannot add more items\n";
        }
    }

    // Remove a product from the cart
    void removeItem(const string& productName) {
        for (int i = 0; i < itemCount; ++i) {
            if (items[i].product.getName() == productName) {
                for (int j = i; j < itemCount - 1; ++j) {
                    items[j] = items[j + 1];  // Shift items to fill the gap
                }
                itemCount--;  // Decrease the item count
                break;
            }
        }
    }

    // Update quantity of a product in the cart
    void updateQuantity(const string& productName, int qty) {
        for (int i = 0; i < itemCount; ++i) {
            if (items[i].product.getName() == productName) {
                items[i].quantity = qty;  // Update the quantity
                break;
            }
        }
    }

    // Calculate total price of the cart
    double calculateTotal() const {
        double total = 0;
        for (int i = 0; i < itemCount; ++i) {
            total += items[i].product.getPrice() * items[i].quantity;
        }
        return total;
    }

    // Display cart
    void displayCart() const {
        cout << "Shopping Cart:\n";
        for (int i = 0; i < itemCount; ++i) {
            cout << items[i].product.getName() << " x" << items[i].quantity
                 << " - $" << fixed << setprecision(2) << items[i].product.getPrice() * items[i].quantity << "\n";
        }
        cout << "Total Price: $" << fixed << setprecision(2) << calculateTotal() << "\n";
    }

    // Get the number of items in the cart
    int getItemCount() const { return itemCount; }
};

class User {
public:
    string userInfo;
    Cart cart;

    User(string info) : userInfo(info) {}
};

class Order {
public:
    string orderSummary;
    string paymentStatus;
    string shippingDetails;

    Order(string summary, string payment, string shipping)
        : orderSummary(summary), paymentStatus(payment), shippingDetails(shipping) {}
};

int main() {
    // Sample products
    Product product1("Laptop", "High performance laptop", 1200.0, 10);
    Product product2("Smartphone", "Latest model smartphone", 800.0, 5);
    
    // Creating user and adding products to the cart
    User user("John Doe");
    user.cart.addItem(product1, 1);  // Add 1 laptop
    user.cart.addItem(product2, 2);  // Add 2 smartphones

    // Display cart contents
    user.cart.displayCart();

    // Update quantity and remove an item
    user.cart.updateQuantity("Smartphone", 1);  // Update smartphone quantity to 1
    user.cart.removeItem("Laptop");  // Remove laptop

    // Display updated cart contents
    user.cart.displayCart();

    return 0;
}
