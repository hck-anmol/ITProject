#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for menu and max orders
#define MAX_ITEMS 5
#define MAX_ORDERS 100

// Struct for menu items
typedef struct {
    char name[50];
    double price;
} MenuItem;

// Struct for order
typedef struct {
    MenuItem item;
    int quantity;
} Order;

// Function prototypes
void displayMenu(MenuItem menu[], int size);
void takeOrder(MenuItem menu[], int menuSize, Order orders[], int *orderCount);
void viewOrder(Order orders[], int orderCount);
void checkout(Order orders[], int orderCount);

// Main function
int main() {
    // Menu setup
    MenuItem menu[MAX_ITEMS] = {
        {"Burger", 5.99},
        {"Pizza", 8.49},
        {"Salad", 4.99},
        {"Soda", 1.99},
        {"Ice Cream", 2.99}
    };

    // Order storage
    Order orders[MAX_ORDERS];
    int orderCount = 0;
    
    int choice;

    while (1) {
        printf("\n===== Welcome to the Food Ordering Platform =====\n");
        printf("1. View Menu\n");
        printf("2. Place an Order\n");
        printf("3. View Your Order\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayMenu(menu, MAX_ITEMS);
                break;
            case 2:
                takeOrder(menu, MAX_ITEMS, orders, &orderCount);
                break;
            case 3:
                viewOrder(orders, orderCount);
                break;
            case 4:
                checkout(orders, orderCount);
                orderCount = 0;  // Reset order after checkout
                break;
            case 5:
                printf("Thank you for using the Food Ordering Platform!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Display the menu
void displayMenu(MenuItem menu[], int size) {
    printf("\n===== Menu =====\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Take order from the user
void takeOrder(MenuItem menu[], int menuSize, Order orders[], int *orderCount) {
    int itemNumber, quantity;
    printf("\nEnter the number of the item you want to order: ");
    scanf("%d", &itemNumber);
    
    if (itemNumber < 1 || itemNumber > menuSize) {
        printf("Invalid item number.\n");
        return;
    }
    
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    
    if (quantity <= 0) {
        printf("Quantity must be greater than zero.\n");
        return;
    }
    
    orders[*orderCount].item = menu[itemNumber - 1];
    orders[*orderCount].quantity = quantity;
    (*orderCount)++;
    
    printf("Added %d x %s to your order.\n", quantity, menu[itemNumber - 1].name);
}

// View current order
void viewOrder(Order orders[], int orderCount) {
    if (orderCount == 0) {
        printf("\nYour order is empty.\n");
        return;
    }
    
    printf("\n===== Your Order =====\n");
    for (int i = 0; i < orderCount; i++) {
        printf("%d x %s - $%.2f each\n", orders[i].quantity, orders[i].item.name, orders[i].item.price);
    }
}

// Checkout and calculate the total
void checkout(Order orders[], int orderCount) {
    if (orderCount == 0) {
        printf("\nYour order is empty. Add some items before checkout.\n");
        return;
    }
    
    double total = 0;
    printf("\n===== Checkout =====\n");
    for (int i = 0; i < orderCount; i++) {
        double itemTotal = orders[i].quantity * orders[i].item.price;
        total += itemTotal;
        printf("%d x %s - $%.2f (Total: $%.2f)\n", orders[i].quantity, orders[i].item.name, orders[i].item.price, itemTotal);
    }
    
    printf("Total Amount Due: $%.2f\n", total);
    printf("Thank you for your order!\n");
}
