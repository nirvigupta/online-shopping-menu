#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Product class that represents a product in the system
class Product
{
private:
    int id;
    string name;
    double price;

public:
    // Constructor
    Product(int pid, string pname, double pprice) : id(pid), name(pname), price(pprice) {}

    // Getters for product attributes
    int getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }

    // Display product details
    void display() const
    {
        cout << left << setw(10) << id
             << setw(20) << name
             << setw(10) << price << endl;
    }
};

// CartItem class that represents an item in the shopping cart
class CartItem
{
private:
    Product product;
    int quantity;

public:
    // Constructor
    CartItem(Product p, int q) : product(p), quantity(q) {}

    // Getters
    Product getProduct() const { return product; }
    int getQuantity() const { return quantity; }

    // Calculate total price for this item
    double getTotalPrice() const { return product.getPrice() * quantity; }

    // Display cart item details
    void display() const
    {
        cout << left << setw(10) << product.getId()
             << setw(20) << product.getName()
             << setw(10) << product.getPrice()
             << setw(10) << quantity
             << setw(10) << getTotalPrice() << endl;
    }
};

// ShoppingCart class to manage a user's shopping cart
class ShoppingCart
{
private:
    vector<CartItem> cartItems;

public:
    // Add a product to the cart
    void addProduct(Product p, int quantity)
    {
        cartItems.push_back(CartItem(p, quantity));
        cout << "Added " << quantity << " of " << p.getName() << " to your cart." << endl;
    }

    // View the cart contents
    void viewCart() const
    {
        if (cartItems.empty())
        {
            cout << "Your cart is empty." << endl;
            return;
        }

        cout << left << setw(10) << "ID"
             << setw(20) << "Product Name"
             << setw(10) << "Price"
             << setw(10) << "Quantity"
             << setw(10) << "Total" << endl;
        cout << "---------------------------------------------------------" << endl;

        for (const auto &item : cartItems)
        {
            item.display();
        }
    }

    // Checkout and display the total price
    void checkout()
    {
        if (cartItems.empty())
        {
            cout << "Your cart is empty. Nothing to checkout." << endl;
            return;
        }

        double totalPrice = 0;
        for (const auto &item : cartItems)
        {
            totalPrice += item.getTotalPrice();
        }

        cout << "Your total amount is: $" << totalPrice << endl;
        cartItems.clear();
        cout << "Thank you for shopping with us!" << endl;
    }
};

// OnlineShop class to handle the product catalog and shopping process
class OnlineShop
{
private:
    vector<Product> products;
    ShoppingCart cart;

public:
    // Constructor to add sample products to the catalog
    OnlineShop()
    {
        products.push_back(Product(1, "Laptop", 800.00));
        products.push_back(Product(2, "Smartphone", 500.00));
        products.push_back(Product(3, "Headphones", 50.00));
        products.push_back(Product(4, "Smartwatch", 150.00));
        products.push_back(Product(5, "Camera", 300.00));
    }

    // Display the available products
    void displayProducts() const
    {
        cout << "Available Products:" << endl;
        cout << left << setw(10) << "ID"
             << setw(20) << "Product Name"
             << setw(10) << "Price" << endl;
        cout << "----------------------------------------" << endl;
        for (const auto &product : products)
        {
            product.display();
        }
    }

    // Add a product to the cart by product ID
    void addToCart(int productId, int quantity)
    {
        for (const auto &product : products)
        {
            if (product.getId() == productId)
            {
                cart.addProduct(product, quantity);
                return;
            }
        }
        cout << "Invalid product ID." << endl;
    }

    // View the items in the cart
    void viewCart() const
    {
        cart.viewCart();
    }

    // Checkout the cart
    void checkout()
    {
        cart.checkout();
    }
};

// Display the main menu
void displayMenu()
{
    cout << "Online Shopping Menu:" << endl;
    cout << "1. View Products" << endl;
    cout << "2. Add to Cart" << endl;
    cout << "3. View Cart" << endl;
    cout << "4. Checkout" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    OnlineShop shop;
    int choice, productId, quantity;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            shop.displayProducts();
            break;

        case 2:
            cout << "Enter the product ID to add to cart: ";
            cin >> productId;
            cout << "Enter the quantity: ";
            cin >> quantity;
            shop.addToCart(productId, quantity);
            break;

        case 3:
            shop.viewCart();
            break;

        case 4:
            shop.checkout();
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
