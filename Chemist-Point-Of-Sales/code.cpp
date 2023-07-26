#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

class Product {
private:
    int id;
    string name;
    string category;
    double price;
    int quantity;

public:
    Product(int id, string name, string category, double price, int quantity) {
        this->id = id;
        this->name = name;
        this->category = category;
        this->price = price;
        this->quantity = quantity;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    string getName() const {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getCategory() const {
        return category;
    }

    void setCategory(string category) {
        this->category = category;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        this->price = price;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }
};

class Client {
private:
    string name;
    string address;
    vector<Product> cart;
    double totalPrice;

public:
    Client(string name, string address) {
        this->name = name;
        this->address = address;
        totalPrice = 0.0;
    }

    string getName() const {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getAddress() const {
        return address;
    }

    void setAddress(string address) {
        this->address = address;
    }

    void addToCart(const Product& product) {
        cart.push_back(product);
        totalPrice += product.getPrice();
    }

    void viewCart() const {
        if (cart.empty()) {
            cout << "Cart is empty." << endl;
            cout << "--------------------------------------------------" << endl;
            return;
        }

        cout << "--------------------- Shopping Cart ---------------------" << endl;
        cout << "Client Name: " << name << endl;
        cout << "Client Address: " << address << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Cart Items:" << endl;
        for (const auto& product : cart) {
            cout << "Product Name: " << product.getName() << endl;
            cout << "Product Category: " << product.getCategory() << endl;
            cout << "Product Price: $" << product.getPrice() << endl;
            cout << "--------------------------------------------------" << endl;
        }
        cout << "Total Price: $" << totalPrice << endl;
        cout << "--------------------------------------------------" << endl;
    }

    void checkout() const {
        if (cart.empty()) {
            cout << "Cart is empty. Nothing to checkout." << endl;
            cout << "--------------------------------------------------" << endl;
            return;
        }

        cout << "--------------------- Checkout Receipt ---------------------" << endl;
        cout << "Client Name: " << name << endl;
        cout << "Client Address: " << address << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Cart Items:" << endl;
        for (const auto& product : cart) {
            cout << "Product Name: " << product.getName() << endl;
            cout << "Product Category: " << product.getCategory() << endl;
            cout << "Product Price: $" << product.getPrice() << endl;
            cout << "--------------------------------------------------" << endl;
        }
        cout << "Total Price: $" << totalPrice << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Thank you for your purchase!" << endl;
        cout << "--------------------------------------------------" << endl;
    }
};

class Inventory {
private:
    vector<Product> products;

    

public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void removeProduct(int id) {
        for (auto it = products.begin(); it != products.end(); ++it) {
            if (it->getId() == id) {
                products.erase(it);
                break;
            }
        }
    }

    void updateProduct(int id, const Product& newProduct) {
        for (auto& product : products) {
            if (product.getId() == id) {
                product = newProduct;
                break;
            }
        }
    }

    Product* findProduct(int id) {
        for (auto& product : products) {
            if (product.getId() == id) {
                return &product;
            }
        }
        return nullptr;
    }

void viewAllProducts() const {
    if (products.empty()) {
        cout << "No products in inventory." << endl;
        cout << "--------------------------------------------------" << endl;
        return;
    }

    cout << "--------------------- Inventory ---------------------" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << left << setw(4) << "ID" << " | ";
    cout << left << setw(16) << "Name" << " | ";
    cout << left << setw(16) << "Category" << " | ";
    cout << left << setw(8) << "Price" << " | ";
    cout << left << setw(8) << "Quantity" << endl;
    cout << "-----------------------------------------------------------" << endl;

    for (const auto& product : products)
    {
        cout << setw(4) << product.getId() << " | ";
        cout << setw(16) << product.getName() << " | ";
        cout << setw(16) << product.getCategory() << " | ";
        cout << setw(8) << fixed << setprecision(2) << product.getPrice() << " | ";
        cout << setw(8) << product.getQuantity() << endl;
    }
    cout << "--------------------------------------------------" << endl;
}
};

int main() {
    Inventory inventory;
    vector<Client> clients;

    // Hardcoding 30 initial products for the client side
    Product product1(1, "Painkiller", "Medicine", 5.99, 50);
    Product product2(2, "Band-Aids", "Medical Supplies", 2.49, 100);
    Product product3(3, "Thermometer", "Medical Devices", 12.99, 30);
    Product product4(4, "Antiseptic Cream", "Medicine", 7.25, 40);
    Product product5(5, "First Aid Kit", "Medical Supplies", 19.99, 20);
    Product product6(6, "Blood Monitor", "Medical Devices", 39.99, 15);
    Product product7(7, "Flu Medicine", "Medicine", 8.49, 60);
    Product product8(8, "Gauze Bandages", "Medical Supplies", 3.75, 80);
    Product product9(9, "Stethoscope", "Medical Devices", 29.99, 10);
    Product product10(10, "Allergy Tablets", "Medicine", 6.99, 70);
    Product product11(11, "Medical Gloves", "Medical Supplies", 4.25, 120);
    Product product12(12, "Oximeter", "Medical Devices", 22.99, 25);
    Product product13(13, "Cough Syrup", "Medicine", 7.99, 55);
    Product product14(14, "Medical Tape", "Medical Supplies", 2.99, 90);
    Product product15(15, "Thermometer", "Medical Devices", 15.99, 20);
    Product product16(16, "Antacid Tablets", "Medicine", 6.49, 40);
    Product product17(17, "Adhesive Bandages", "Medical Supplies", 1.99, 150);
    Product product18(18, "Glucose Monitor", "Medical Devices", 34.99, 12);
    Product product19(19, "Sinus Tablets", "Medicine", 9.49, 35);
    Product product20(20, "Cotton Swabs", "Medical Supplies", 2.25, 200);
    Product product21(21, "Face Masks", "Medical Devices", 11.99, 40);
    Product product22(22, "Headache Tablets", "Medicine", 5.49, 65);
    Product product23(23, "Elastic Bandages", "Medical Supplies", 4.75, 70);
    Product product24(24, "B.P Cuff", "Medical Devices", 27.99, 18);
    Product product25(25, "Supplements", "Medicine", 12.49, 30);
    Product product26(26, "Hydrogen Peroxide", "Medical Supplies", 3.25, 85);
    Product product27(27, "Pulse Oximeter", "Medical Devices", 19.99, 30);
    Product product28(28, "Antibiotics", "Medicine", 7.49, 50);
    Product product29(29, "Wound Dressing", "Medical Supplies", 2.99, 110);
    Product product30(30, "Medical Scissors", "Medical Devices", 8.99, 15);


    // Adding the hardcoded products to the inventory
    inventory.addProduct(product1);
    inventory.addProduct(product2);
    inventory.addProduct(product3);
    inventory.addProduct(product4);
    inventory.addProduct(product5);
    inventory.addProduct(product6);
    inventory.addProduct(product7);
    inventory.addProduct(product8);
    inventory.addProduct(product9);
    inventory.addProduct(product10);
    inventory.addProduct(product11);
    inventory.addProduct(product12);
    inventory.addProduct(product13);
    inventory.addProduct(product14);
    inventory.addProduct(product15);
    inventory.addProduct(product16);
    inventory.addProduct(product17);
    inventory.addProduct(product18);
    inventory.addProduct(product19);
    inventory.addProduct(product20);
    inventory.addProduct(product21);
    inventory.addProduct(product22);
    inventory.addProduct(product23);
    inventory.addProduct(product24);
    inventory.addProduct(product25);
    inventory.addProduct(product26);
    inventory.addProduct(product27);
    inventory.addProduct(product28);
    inventory.addProduct(product29);
    inventory.addProduct(product30);

    cout << "-----------------------------------------------------------" << endl;
    cout << "---------- Welcome to Dawa Inventory Management System! ----------" << endl;
    cout << "------------------- Your One-Stop Solution for ------------------" << endl;
    cout << "--------- Managing and Organizing Medical Inventory! ---------" << endl;
    cout << "-----------------------------------------------------------" << endl;

    char roleChoice;
    do {
        cout << "Please choose your role:" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Client" << endl;
        cout << "X. Exit" << endl;
        cout << "Choice: ";
        cin >> roleChoice;

        switch (roleChoice) {
            case '1': {
                // Admin Options
                char adminChoice;
                do {
                    cout << "Admin Options:" << endl;
                    cout << "1. Add a product to inventory" << endl;
                    cout << "2. Remove a product from inventory" << endl;
                    cout << "3. Find a product in inventory" << endl;
                    cout << "4. Update a product in inventory" << endl;
                    cout << "5. View all products in inventory" << endl;
                    cout << "X. Go back" << endl;
                    cout << "Choice: ";
                    cin >> adminChoice;

                    switch (adminChoice) {
                        case '1': {
                            // Add a product to inventory
                            int id;
                            string name;
                            string category;
                            double price;
                            int quantity;

                            cout << "Enter the product ID: ";
                            cin >> id;
                            cin.ignore();

                            cout << "Enter the product name: ";
                            getline(cin, name);

                            cout << "Enter the product category: ";
                            getline(cin, category);

                            cout << "Enter the product price: $";
                            cin >> price;

                            cout << "Enter the product quantity: ";
                            cin >> quantity;

                            Product product(id, name, category, price, quantity);
                            inventory.addProduct(product);
                            cout << "Product added to inventory." << endl;
                            cout << "--------------------------------------------------" << endl;
                            break;
                        }
                        case '2': {
                            // Remove a product from inventory
                            int id;
                            cout << "Enter the product ID: ";
                            cin >> id;
                            inventory.removeProduct(id);
                            cout << "Product removed from inventory." << endl;
                            cout << "--------------------------------------------------" << endl;
                            break;
                        }
                        case '3': {
                            // Find a product in inventory
                            int id;
                            cout << "Enter the product ID: ";
                            cin >> id;
                            Product* product = inventory.findProduct(id);
                            if (product != nullptr) {
                                cout << "Product found in inventory." << endl;
                                cout << "Product Name: " << product->getName() << endl;
                                cout << "Product Category: " << product->getCategory() << endl;
                                cout << "Product Price: $" << product->getPrice() << endl;
                                cout << "Product Quantity: " << product->getQuantity() << endl;
                            } else {
                                cout << "Product not found in inventory." << endl;
                            }
                            cout << "--------------------------------------------------" << endl;
                            break;
                        }
                        case '4': {
                            // Update a product in inventory
                            int id;
                            string name;
                            string category;
                            double price;
                            int quantity;

                            cout << "Enter the product ID: ";
                            cin >> id;
                            cin.ignore();

                            cout << "Enter the updated product name: ";
                            getline(cin, name);

                            cout << "Enter the updated product category: ";
                            getline(cin, category);

                            cout << "Enter the updated product price: $";
                            cin >> price;

                            cout << "Enter the updated product quantity: ";
                            cin >> quantity;

                            Product newProduct(id, name, category, price, quantity);
                            inventory.updateProduct(id, newProduct);
                            cout << "Product updated in inventory." << endl;
                            cout << "--------------------------------------------------" << endl;
                            break;
                        }
                        case '5': {
                            // View all products in inventory
                            inventory.viewAllProducts();
                            cout << "--------------------------------------------------" << endl;
                            break;
                        }
                        case 'X':
                        case 'x':
                            // Go back to role selection
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            cout << "--------------------------------------------------" << endl;
                    }
                } while (adminChoice != 'X' && adminChoice != 'x');
                break;
            }
            case '2': {
                // Client Options
                string clientName;
                string clientAddress;

                cout << "Enter your name: ";
                cin.ignore();
                getline(cin, clientName);

                cout << "Enter your address: ";
                getline(cin, clientAddress);

                Client client(clientName, clientAddress);

                char clientChoice;
                do {
                    cout << "Client Options:" << endl;
                    cout << "1. View all products in inventory" << endl;
                    cout << "2. Add a product to shopping cart" << endl;
                    cout << "3. View shopping cart" << endl;
                    cout << "4. Checkout" << endl;
                    cout << "X. Go back" << endl;
                    cout << "Choice: ";
                    cin >> clientChoice;

                    switch (clientChoice) {
                        case '1': {
                            // View all products in inventory
                            inventory.viewAllProducts();
                            cout << "--------------------------------------------------" << endl;
                            break;
                        }
                        case '2': {
                            // Add a product to shopping cart
                            int productId;
                            cout << "Enter the product ID: ";
                            cin >> productId;

                            Product* product = inventory.findProduct(productId);
                            if (product != nullptr) {
                                client.addToCart(*product);
                                cout << "Product added to shopping cart." << endl;
                            } else {
                                cout << "Product not found in inventory." << endl;
                            }
                            cout << "--------------------------------------------------" << endl;
                            break;
                        }
                        case '3': {
                            // View shopping cart
                            client.viewCart();
                            cout << "--------------------------------------------------" << endl;
                            break;
                        }
                        case '4': {
                            // Checkout
                            client.checkout();
                            cout << "--------------------------------------------------" << endl;
                            break;
                        }
                        case 'X':
                        case 'x':
                            // Go back to role selection
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            cout << "--------------------------------------------------" << endl;
                    }
                } while (clientChoice != 'X' && clientChoice != 'x');
                clients.push_back(client); // Store client object after interactions
                break;
            }
            case 'X':
            case 'x':
                // Exit the program
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                cout << "--------------------------------------------------" << endl;
        }
    } while (roleChoice != 'X' && roleChoice != 'x');

    return 0;
}
