#include <stdio.h>


int main() {
    char items[100][50];  // Stores the names of the items
    float prices[100];    // Stores the prices of the items
    float subtotal = 0.0, deliveryCost = 0.0, total = 0.0;
    int itemCount = 0;    // Counts how many items the customer adds
    int overnight;        // Indicates if overnight delivery is needed (1 for Yes, 0 for No)
    char choice;          // To check if the customer wants to add another item

    printf("Welcome to the Item Order System!\n");

    // Loop to add items
    do {
        printf("\nEnter the item name: ");
        scanf(" %[^\n]", items[itemCount]);  // Allows spaces in item titles

        printf("Enter the price of the item: ");
        scanf("%f", &prices[itemCount]);

        subtotal += prices[itemCount];  // Add the item price to the subtotal
        itemCount++;

        printf("Do you want to add another item? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');  // Continue adding items if user enters 'y'

    // Check if the customer ordered at least 2 items
    if (itemCount < 2) {
        printf("\nError: You must order at least 2 items.\n");
        return 1;  // Exit the program
    }

    // Ask if the customer needs overnight delivery
    printf("\nDo you need overnight delivery? (1 for Yes, 0 for No): ");
    scanf("%d", &overnight);

    // Calculate delivery cost
    for (int i = 0; i < itemCount; i++) {
        if (prices[i] < 10.0) {
            deliveryCost += 2.0;  // $2 for items under $10
        } else {
            deliveryCost += 3.0;  // $3 for items $10 or more
        }
    }
    if (overnight == 1) {
        deliveryCost += 5.0;  // Add $5 for overnight delivery
    }

    // Apply discount if the customer ordered more than 5 items
    if (itemCount > 5) {
        printf("\nYou get a 20%% discount for ordering more than 5 items!\n");
        subtotal *= 0.8;  // Apply 20% discount
    }

    // Calculate the total cost
    total = subtotal + deliveryCost;

    // Display the final receipt
    printf("\n----------------------------------\n");
    printf("           INVOICE                \n");
    printf("----------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item: %s, Price: $%.2f\n", items[i], prices[i]);
    }
    printf("----------------------------------\n");
    printf("Subtotal:       $%.2f\n", subtotal);
    printf("Delivery Cost:  $%.2f\n", deliveryCost);
    printf("Total Cost:     $%.2f\n", total);
    printf("----------------------------------\n");
    printf("Thank you for shopping with us!\n");

    return 0;
}
