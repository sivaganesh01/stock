#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    char name[50];
    char quantity[20];  // Change the type to a string
    char prevQuantity[20];  // New field to store previous quantity
};

struct Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount < MAX_ITEMS) {
        printf("\nEnter the name of the item: ");
        scanf("%s", inventory[itemCount].name);

        printf("\nEnter the quantity: ");
        scanf("%s", inventory[itemCount].quantity);

        // Initialize prevQuantity to the same as quantity for the first time
        strcpy(inventory[itemCount].prevQuantity, inventory[itemCount].quantity);

        itemCount++;
        printf("\nItem added successfully!\n");
    } else {
        printf("\nInventory is full. Cannot add more items.\n");
    }
}

void updateQuantity() {
    char itemName[50];
    printf("\nEnter the name of the item to update quantity: ");
    scanf("%s", itemName);

    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(itemName, inventory[i].name) == 0) {
            // Save the previous quantity before updating
            strcpy(inventory[i].prevQuantity, inventory[i].quantity);

            printf("\nEnter the new quantity: ");
            scanf("%s", inventory[i].quantity);
            found = 1;
            printf("\nQuantity updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nItem not found in the inventory.\n");
    }
}

void removeItem() {
    char itemName[50];
    printf("\nEnter the name of the item to remove: ");
    scanf("%s", itemName);

    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(itemName, inventory[i].name) == 0) {
            // Shift items to fill the gap
            for (int j = i; j < itemCount - 1; j++) {
                strcpy(inventory[j].name, inventory[j + 1].name);
                strcpy(inventory[j].quantity, inventory[j + 1].quantity);
                strcpy(inventory[j].prevQuantity, inventory[j + 1].prevQuantity);
            }
            itemCount--;
            found = 1;
            printf("\nItem removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nItem not found in the inventory.\n");
    }
}

void displayInventory() {
    if (itemCount == 0) {
        printf("\nInventory is empty.\n");
    } else {
        printf("\nCurrent Inventory:\n");
        printf("%-20s | %-15s | %-15s\n", "Item Name", "Previous Quantity", "Current Quantity");
        printf("----------------------------------------------------\n");
        for (int i = 0; i < itemCount; i++) {
            printf("%-20s | %-15s | %-15s\n", inventory[i].name, inventory[i].prevQuantity, inventory[i].quantity);
        }
    }
}

int main() {
    int choice;

    do {
        printf("\nStock Management System\n");
        printf("1. Add Item\n");
        printf("2. Update Quantity\n");
        printf("3. Remove Item\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                updateQuantity();
                break;
            case 3:
                removeItem();
                break;
            case 4:
                displayInventory();
                break;
            case 5:
                printf("\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
