
#include <stdio.h>
#include <stdlib.h>

#define TOTAL_SLOTS 10

void showAvailableSlots(int slots[]) {
    printf("\nAvailable Slots:\n");
    for (int i = 0; i < TOTAL_SLOTS; i++) {
        if (slots[i] == 0) {
            printf("Slot %d is available\n", i + 1);
        }
    }
}

void bookSlot(int slots[]) {
    int slotNumber;
    printf("\nEnter slot number to book (1-%d): ", TOTAL_SLOTS);
    scanf("%d", &slotNumber);

    if (slotNumber < 1 || slotNumber > TOTAL_SLOTS) {
        printf("Invalid slot number!\n");
        return;
    }

    if (slots[slotNumber - 1] == 0) {
        slots[slotNumber - 1] = 1;
        printf("Slot %d booked successfully!\n", slotNumber);
    } else {
        printf("Slot %d is already booked. Please choose another slot.\n", slotNumber);
    }
}

int main() {
    int slots[TOTAL_SLOTS] = {0}; // 0 means available, 1 means booked
    int choice;

    printf("Welcome to Vehicle Service Center Booking System!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Show Available Slots\n");
        printf("2. Book a Slot\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showAvailableSlots(slots);
                break;
            case 2:
                bookSlot(slots);
                break;
            case 3:
                printf("Thank you for using the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
