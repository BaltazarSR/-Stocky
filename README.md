# Stocky Inventory Management System

**Stocky** is a simple command-line inventory management system built in C++. It allows users to create and manage inventories, handle product sales, and track customer shipping details. This project simulates a basic inventory system for small businesses.

## Features

- Create an inventory for a business.
- Add or modify products in the inventory.
- Display inventory details, including product names, available units, and prices.
- Sell products and track quantities.
- Enter and store shipping information for product delivery.
- Calculate total sales revenue for a specified product quantity.

## Getting Started

### Prerequisites

To run the program, you need:

- A C++ compiler (e.g., GCC, Clang, etc.)
- A terminal or IDE that supports C++.

### Installing

1. Clone the repository to your local machine:
    ```bash
    git clone https://github.com/your-username/stocky.git
    ```

2. Navigate to the project directory:
    ```bash
    cd stocky
    ```

3. Compile the C++ source file:
    ```bash
    g++ main.cpp -o stocky
    ```

4. Run the program:
    ```bash
    ./stocky
    ```

## How to Use

1. **Create Inventory:**
    - Enter the business name and add products with their respective names, prices, and quantities.

2. **View Inventory:**
    - Displays all available products in the inventory along with their details.

3. **Sell Products:**
    - Select a product, enter the number of units to sell, and the program calculates the total revenue and adjusts inventory.

4. **Modify Inventory:**
    - You can replace existing products with new ones or modify their quantities and prices.

5. **Exit:**
    - Exits the application.

## Example

```text
Bienvenido a Stocky

    1.- Crear inventario
    2.- Revisar inventario
    3.- Vender
    4.- Salir
Escoja una opcion: 1

Ingrese el nombre de su negocio: TechStore

Ingrese el nombre de su producto: Laptop
Ingrese el numero de unidades de su producto: 10
Ingrese el precio de su producto: 599.99

Inventario de TechStore
---------------------------------------------
     Producto: Laptop
     Precio: $599.99
     Unidades disponibles: 10
---------------------------------------------
