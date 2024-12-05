<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constants
#define MAX_ITEMS 5
#define MAX_ORDERS 100
#define DISCOUNT_MIN 50.0
#define DISCOUNT_RATE 0.1

// Structurs defined
typedef struct
{
    char name[50];
    int price;
} MenuItem;

typedef struct
{
    MenuItem item;
    int quantity;
} Order;

// Function prototypes defined
void displayMenu(MenuItem menu[], int size);
void takeOrder(MenuItem menu[], int menuSize, Order orders[], int *orderCount);
void addOrder(MenuItem menu[], int menuSize, Order orders[], int *orderCount);
void viewOrder(Order orders[], int orderCount);
void checkout(Order orders[], int orderCount);
void clearInputBuffer();

int main()
{
    // Menu List Setup
    MenuItem menu[MAX_ITEMS] = {
        {"Burger", 180},
        {"Pizza", 450},
        {"Salad", 250},
        {"Soda", 100},
        {"Ice Cream", 150}};

    // Order capacity
    Order orders[MAX_ORDERS];
    int orderCount = 0;

    int choice;
    while (1)
    {
        printf("\n===== Welcome to Olives~ E-menu =====\n");
        printf("1. View Menu\n");
        printf("2. Place an Order\n");
        printf("3. Add more to the Order\n");
        printf("4. View Your Order\n");
        printf("5. Checkout\n");
        printf("6. Exit\n");
        printf("Please enter your choice (1-6): ");

        // Input validation
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice)
        {
        case 1:
            displayMenu(menu, MAX_ITEMS);
            break;
        case 2:
            takeOrder(menu, MAX_ITEMS, orders, &orderCount);
            break;
        case 3:
            addOrder(menu, MAX_ITEMS, orders, &orderCount);
            break;
        case 4:
            viewOrder(orders, orderCount);
            break;
        case 5:
            checkout(orders, orderCount);
            orderCount = 0; // Reset order after checkout
            break;
        case 6:
            printf("Thank you for using the Food Ordering Platform!\n");
            exit(0);
        default:
            printf("Invalid choice. Please select a valid option.\n");
        }
    }
    return 0;
}

// Display menu
void displayMenu(MenuItem menu[], int size)
{
    printf("\n===== Menu =====\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d. %s - Rs%d\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Take order from user
void takeOrder(MenuItem menu[], int menuSize, Order orders[], int *orderCount)
{
    int itemNumber, quantity;

    // Check if max orders reached
    if (*orderCount >= MAX_ORDERS)
    {
        printf("Sorry, you've reached the maximum order limit.\n");
        return;
    }

    displayMenu(menu, menuSize);
    printf("Enter the serial number of the item you want to order: ");

    // Input validation
    if (scanf("%d", &itemNumber) != 1 || itemNumber < 1 || itemNumber > menuSize)
    {
        printf("Invalid item number. Please try again.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter quantity: ");

    // Input validation
    if (scanf("%d", &quantity) != 1 || quantity <= 0)
    {
        printf("Invalid quantity. Please enter a positive number.\n");
        clearInputBuffer();
        return;
    }

    orders[*orderCount].item = menu[itemNumber - 1];
    orders[*orderCount].quantity = quantity;
    (*orderCount)++;

    printf("Added %d x %s to your order.\n", quantity, menu[itemNumber - 1].name);
}
void addOrder(MenuItem menu[], int menuSize, Order orders[], int *orderCount)
{
    int itemNumber, quantity;

    // Check if max orders reached
    if (*orderCount >= MAX_ORDERS)
    {
        printf("Sorry, you've reached the maximum order limit.\n");
        return;
    }

    displayMenu(menu, menuSize);
    printf("Enter the serial number of the item you want to order: ");

    // Input validation
    if (scanf("%d", &itemNumber) != 1 || itemNumber < 1 || itemNumber > menuSize)
    {
        printf("Invalid item number. Please try again.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter quantity: ");

    // Input validation
    if (scanf("%d", &quantity) != 1 || quantity <= 0)
    {
        printf("Invalid quantity. Please enter a positive number.\n");
        clearInputBuffer();
        return;
    }

    orders[*orderCount].item = menu[itemNumber - 1];
    orders[*orderCount].quantity = quantity;
    (*orderCount)++;

    printf("Added %d x %s to your order.\n", quantity, menu[itemNumber - 1].name);
}
// View current order
void viewOrder(Order orders[], int orderCount)
{
    if (orderCount == 0)
    {
        printf("\nYour order is currently empty.\n");
        return;
    }

    printf("\n===== Your Order =====\n");
    for (int i = 0; i < orderCount; i++)
    {
        printf("%d x %s - Rs%d each\n", orders[i].quantity, orders[i].item.name, orders[i].item.price);
    }
}

// Checkout and calculate total
void checkout(Order orders[], int orderCount)
{
    if (orderCount == 0)
    {
        printf("\nYour order is empty. Add some items before checking out.\n");
        return;
    }

    int total = 0;
    printf("\n===== Checkout =====\n");
    for (int i = 0; i < orderCount; i++)
    {
        int itemTotal = orders[i].quantity * orders[i].item.price;
        total += itemTotal;
        printf("%d x %s - Rs%d (Total: Rs%d)\n", orders[i].quantity, orders[i].item.name, orders[i].item.price, itemTotal);
    }

    if (total >= DISCOUNT_MIN)
    {
        int discount = total * DISCOUNT_RATE;
        total -= discount;
        printf("Congratulations! You received a 10%% discount of Rs%d.\n", discount);
    }

    printf("Total Amount Due: %d\n", total);
    printf("Thank you for your order! Have a great day!\n");
}

// Clear input buffer
void clearInputBuffer()
{
    while (getchar() != '\n')
        ;
}
=======
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constants
#define MAX_ITEMS 5
#define MAX_ORDERS 100
#define DISCOUNT_MIN 50.0
#define DISCOUNT_RATE 0.1

// Structurs defined
typedef struct
{
    char name[50];
    int price;
} MenuItem;

typedef struct
{
    MenuItem item;
    int quantity;
} Order;

// Function prototypes
void displayMenu(MenuItem menu[], int size);
void takeOrder(MenuItem menu[], int menuSize, Order orders[], int *orderCount);
void addOrder(MenuItem menu[], int menuSize, Order orders[], int *orderCount);
void viewOrder(Order orders[], int orderCount);
void checkout(Order orders[], int orderCount);
void clearInputBuffer();

int main()
{
    // Menu List Setup
    MenuItem menu[MAX_ITEMS] = {
        {"Burger", 180},
        {"Pizza", 450},
        {"Salad", 250},
        {"Soda", 100},
        {"Ice Cream", 150}};

    // Order capacity
    Order orders[MAX_ORDERS];
    int orderCount = 0;

    int choice;
    while (1)
    {
        printf("\n===== Welcome to Olives~ E-menu =====\n");
        printf("1. View Menu\n");
        printf("2. Place an Order\n");
        printf("3. Add more to the Order\n");
        printf("4. View Your Order\n");
        printf("5. Checkout\n");
        printf("6. Exit\n");
        printf("Please enter your choice (1-6): ");

        // Input validation
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice)
        {
        case 1:
            displayMenu(menu, MAX_ITEMS);
            break;
        case 2:
            takeOrder(menu, MAX_ITEMS, orders, &orderCount);
            break;
        case 3:
            addOrder(menu, MAX_ITEMS, orders, &orderCount);
            break;
        case 4:
            viewOrder(orders, orderCount);
            break;
        case 5:
            checkout(orders, orderCount);
            orderCount = 0; // Reset order after checkout
            break;
        case 6:
            printf("Thank you for using the Food Ordering Platform!\n");
            exit(0);
        default:
            printf("Invalid choice. Please select a valid option.\n");
        }
    }
    return 0;
}

// Display menu
void displayMenu(MenuItem menu[], int size)
{
    printf("\n===== Menu =====\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d. %s - Rs%d\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Take order from user
void takeOrder(MenuItem menu[], int menuSize, Order orders[], int *orderCount)
{
    int itemNumber, quantity;

    // Check if max orders reached
    if (*orderCount >= MAX_ORDERS)
    {
        printf("Sorry, you've reached the maximum order limit.\n");
        return;
    }

    displayMenu(menu, menuSize);
    printf("Enter the serial number of the item you want to order: ");

    // Input validation
    if (scanf("%d", &itemNumber) != 1 || itemNumber < 1 || itemNumber > menuSize)
    {
        printf("Invalid item number. Please try again.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter quantity: ");

    // Input validation
    if (scanf("%d", &quantity) != 1 || quantity <= 0)
    {
        printf("Invalid quantity. Please enter a positive number.\n");
        clearInputBuffer();
        return;
    }

    orders[*orderCount].item = menu[itemNumber - 1];
    orders[*orderCount].quantity = quantity;
    (*orderCount)++;

    printf("Added %d x %s to your order.\n", quantity, menu[itemNumber - 1].name);
}
void addOrder(MenuItem menu[], int menuSize, Order orders[], int *orderCount)
{
    int itemNumber, quantity;

    // Check if max orders reached
    if (*orderCount >= MAX_ORDERS)
    {
        printf("Sorry, you've reached the maximum order limit.\n");
        return;
    }

    displayMenu(menu, menuSize);
    printf("Enter the serial number of the item you want to order: ");

    // Input validation
    if (scanf("%d", &itemNumber) != 1 || itemNumber < 1 || itemNumber > menuSize)
    {
        printf("Invalid item number. Please try again.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter quantity: ");

    // Input validation
    if (scanf("%d", &quantity) != 1 || quantity <= 0)
    {
        printf("Invalid quantity. Please enter a positive number.\n");
        clearInputBuffer();
        return;
    }

    orders[*orderCount].item = menu[itemNumber - 1];
    orders[*orderCount].quantity = quantity;
    (*orderCount)++;

    printf("Added %d x %s to your order.\n", quantity, menu[itemNumber - 1].name);
}
// View current order
void viewOrder(Order orders[], int orderCount)
{
    if (orderCount == 0)
    {
        printf("\nYour order is currently empty.\n");
        return;
    }

    printf("\n===== Your Order =====\n");
    for (int i = 0; i < orderCount; i++)
    {
        printf("%d x %s - Rs%d each\n", orders[i].quantity, orders[i].item.name, orders[i].item.price);
    }
}

// Checkout and calculate total
void checkout(Order orders[], int orderCount)
{
    if (orderCount == 0)
    {
        printf("\nYour order is empty. Add some items before checking out.\n");
        return;
    }

    int total = 0;
    printf("\n===== Checkout =====\n");
    for (int i = 0; i < orderCount; i++)
    {
        int itemTotal = orders[i].quantity * orders[i].item.price;
        total += itemTotal;
        printf("%d x %s - Rs%d (Total: Rs%d)\n", orders[i].quantity, orders[i].item.name, orders[i].item.price, itemTotal);
    }

    if (total >= DISCOUNT_MIN)
    {
        int discount = total * DISCOUNT_RATE;
        total -= discount;
        printf("Congratulations! You received a 10%% discount of Rs%d.\n", discount);
    }

    printf("Total Amount Due: %d\n", total);
    printf("Thank you for your order! Have a great day!\n");
}

// Clear input buffer
void clearInputBuffer()
{
    while (getchar() != '\n')
        ;
}
>>>>>>> 91b7e80d6e7dc61b664f6d123aff8a726adf0e90
