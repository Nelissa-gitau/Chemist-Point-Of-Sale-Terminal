# Chemist-Point-Of-Sale-Terminal#
# Dawa Inventory Management System

The "Dawa Inventory Management System" is a C++ program designed to manage and organize medical inventory. It allows users to interact with the inventory as either an Admin or a Client. The Admin can perform various actions such as adding, updating, and removing products from the inventory, while the Client can view the available products, add them to their shopping cart, view the cart, and proceed with the checkout.

## Features

1. **Admin Options**
   - Add a product to inventory: Allows the admin to add new products with details like ID, name, category, price, and quantity.
   - Remove a product from inventory: Enables the admin to remove a product from the inventory based on its ID.
   - Find a product in inventory: Helps the admin to search for a product by its ID and view its details.
   - Update a product in inventory: Allows the admin to modify the details of a product in the inventory based on its ID.
   - View all products in inventory: Displays a tabulated list of all the products currently available in the inventory.

2. **Client Options**
   - View all products in inventory: Displays a tabulated list of all the products available in the inventory for the clients to browse.
   - Add a product to shopping cart: Allows clients to add a specific product to their shopping cart by providing its ID.
   - View shopping cart: Displays the products in the client's shopping cart along with their details and the total price.
   - Checkout: Proceeds with the checkout process for the items in the shopping cart, generating a receipt for the client's purchase.

## Usage

1. The program starts by displaying a welcome message and offers two role options: "Admin" or "Client."
2. If the user selects "Admin," they can perform various actions to manage the inventory.
3. If the user selects "Client," they will be asked to provide their name and address. Afterward, they can interact with the inventory by viewing products, adding them to the cart, viewing the cart, and checking out.
4. Users can navigate back to the role selection menu by choosing "Go back" when they are finished with their current role.
5. To exit the program, the user can select "Exit."

## Important Notes

- The program hardcodes an initial set of 30 products into the inventory, but you can expand this list as needed.
- The program uses the `Product`, `Client`, and `Inventory` classes to manage the data and interactions.

Please feel free to modify, extend, or improve the program according to your specific needs. Happy coding!
