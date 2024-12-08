# Inventory Management System with Notification

## Overview

This project implements an **Inventory Management System** for a retail organization. It manages product inventories, notifies suppliers when stock levels fall below the reorder threshold, and generates reports on inventory status. The system is implemented using **C++ Object-Oriented Programming (OOP)** concepts such as **composition**, **inheritance**, **abstract classes**, and **polymorphism**.

---

## Design Choices Made

### 1. Object-Oriented Design:

- **Composition** was used to model the relationship between the `Organization` class and the `Product` class. The `Organization` class holds a collection of `Product` objects, reflecting the fact that an organization owns and manages multiple products.
- **Inheritance and Abstract Classes** were utilized for the supplier system. The `Supplier` class is abstract, and concrete subclasses (`LocalSupplier` and `GlobalSupplier`) implement the restock notification logic.
- The system separates concerns:
  - **Product** handles product-specific information (ID, name, price, stock, etc.).
  - **Supplier** deals with supplier-related functionality (notification handling).
  - **Organization** manages the overall inventory, performs operations (adding/removing products), and sends restocking notifications to suppliers when necessary.

### 2. Notification System:

- When a product’s stock falls below the reorder threshold, the **Organization** class automatically notifies all subscribed suppliers.
- The system uses the **Observer** pattern-like behavior where suppliers are "subscribed" to the organization and receive notifications for restocking.

### 3. Encapsulation and Data Integrity:

- Private attributes are used in all classes, and access is provided through public getter/setter methods, ensuring data integrity.

### 4. Extensibility:

- The design allows for easy addition of new features such as additional supplier types or enhanced product details.
- The supplier system is flexible and can be expanded with more specific types of suppliers if needed in the future.

---

## Instructions for Running and Testing the System

### Prerequisites

Ensure you have the **g++** compiler installed. You can check by running:

```bash
g++ --version
```

### Running the Program

- **Clone or Set Up the Project**: Download or clone the project and navigate to the folder that contains the source code.
- **Compile the Code**:

  - If using g++: In the terminal, navigate to the src/ directory and run:

  ```bash
  g++ main.cpp -o my_program
  ```

- **Run the Program**:

  - On **Linux/macOS**, run

  ```bash
  ./my_program
  ```

  - On **Linux/macOS**, run

  ```bash
  ./my_program.exe
  ```

# Additional Features and Challenges

## Features:

- **Supplier Notification**:
  When a product's stock level falls below the reorder threshold, the system notifies all subscribed suppliers (e.g., LocalSupplier, GlobalSupplier).

- **Inventory Report Generation**:
  The system can generate reports of the current stock levels and products that need restocking.

- **Multiple Supplier Types**:
  You can easily add more supplier types by creating new classes that inherit from the Supplier class.

## Challenges Faced:

- **Handling Dynamic Stock Levels**:
  Updating stock levels and triggering notifications when thresholds are crossed required careful management of product data.

- **Supplier Notification System**:
  Managing multiple suppliers and ensuring they are notified when stock falls below the reorder threshold added complexity, which was handled using a simple subscription model.

- **Scalability**:
  While the system is flexible, ensuring it is scalable and easy to extend with new product types, supplier types, and notification methods required planning and careful structuring of the code.
