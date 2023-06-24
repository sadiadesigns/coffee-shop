# Sadia's Coffee Shop

Sadia's Coffee Shop is a command-line application that allows users to manage a coffee inventory, sell coffee, track sales balance, and perform various other operations. This README provides an overview of the application and instructions for setting it up and running it on your local machine.

## Features

- **Add Coffee**: Add a new coffee to the inventory by providing its name, price, and quantity.
- **Sell Coffee**: Sell a coffee from the inventory by specifying its ID and the quantity to be sold. Updates the inventory and tracks sales balance.
- **Show Inventory**: Display the current inventory, including coffee ID, name, price, and quantity.
- **Show Balance**: Display the total sales balance accumulated from coffee sales.
- **Remove Coffee**: Remove a coffee from the inventory by specifying its ID. Updates the inventory accordingly.

## Prerequisites

To run Sadia's Coffee Shop on your machine, you need to have the following installed:

- C compiler (e.g., GCC)
- Standard C libraries

## Getting Started

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/your-username/sadias-coffee-shop.git
   ```

2. Navigate to the project directory:

   ```bash
   cd sadias-coffee-shop
   ```

3. Compile the code using the C compiler:

   ```bash
   gcc -o coffee_shop main.c login.c menu.c splash.c features.c utils.c
   ```

4. Run the application:

   ```bash
   ./coffee_shop
   ```

## Usage

Upon running the application, you will be presented with a login panel. Use the following credentials to log in as an admin:

- Username: admin
- Password: admin

After successful login, the main menu will be displayed, offering various options for managing the coffee inventory and performing operations.

Choose an option by entering the corresponding number and following the prompts to add coffee, sell coffee, view inventory, check sales balance, or remove coffee from the inventory.

## Contributing

Contributions to Sadia's Coffee Shop are welcome! If you have any suggestions, improvements, or bug fixes, please submit a pull request. Before submitting a pull request, ensure that your code adheres to the existing code style and that all tests pass successfully.

## License

This project is licensed under the [MIT License](LICENSE). Feel free to modify and distribute it according to your needs.

## Acknowledgments

- The Sadia's Coffee Shop project was developed as a learning exercise and does not represent a real-world coffee shop application.
- The code structure and organization were inspired by best practices and modular design principles.

## Contact

If you have any questions or suggestions regarding Sadia's Coffee Shop, please feel free to contact me at [your-email@example.com](mailto:sadia.ahmed05@northsouth.edu).
