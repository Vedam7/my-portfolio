#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    int seatNumber;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void bookTicket(char name[], int seat) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->seatNumber = seat;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Ticket booked successfully for %s (Seat No: %d)\n", name, seat);
}

void cancelTicket() {
    if (front == NULL) {
        printf("No tickets to cancel.\n");
        return;
    }
    struct Node* temp = front;
    front = front->next;
    printf("Ticket for %s (Seat No: %d) cancelled.\n", temp->name, temp->seatNumber);
    free(temp);

    if (front == NULL)
        rear = NULL;
}

void displayBookings() {
    if (front == NULL) {
        printf("No tickets booked.\n");
        return;
    }
    struct Node* temp = front;
    printf("Booked Tickets:\n");
    while (temp != NULL) {
        printf("Name: %s, Seat No: %d\n", temp->name, temp->seatNumber);
        temp = temp->next;
    }
}

int main() {
    int choice, seat;
    char name[50];

    do {
        printf("\nMovie Ticket Booking System\n");
        printf("1. Book Ticket\n2. Cancel Ticket\n3. View Bookings\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                gets(name);
                printf("Enter Seat Number: ");
                scanf("%d", &seat);
                bookTicket(name, seat);
                break;
            case 2:
                cancelTicket();
                break;
            case 3:
                displayBookings();
                break;
        }
    } while (choice != 4);

    return 0;
}
