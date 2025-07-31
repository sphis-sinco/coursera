#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

// Linked list node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Append to the end of the list
void append(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* curr = *head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = newNode;
    }
}

// Bubble sort the linked list
void bubbleSortList(Node* head) {
    if (!head) return;
    int swapped;
    Node* ptr;
    Node* lastSorted = NULL;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != lastSorted) {
            if (ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lastSorted = ptr;
    } while (swapped);
}

// Print the list in rows of 5
void printList(Node* head) {
    int count = 0;
    while (head != NULL) {
        printf("%5d", head->data);
        count++;
        if (count % 5 == 0)
            printf("\n");
        head = head->next;
    }
    if (count % 5 != 0)
        printf("\n");
}

// Free the list memory
void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    srand((unsigned int)time(NULL));

    // Generate 100 random integers and store in list
    for (int i = 0; i < SIZE; i++) {
        int value = rand() % 1000; // values from 0 to 999
        append(&head, value);
    }

    printf("Original List:\n");
    printList(head);

    bubbleSortList(head);

    printf("\nSorted List:\n");
    printList(head);

    freeList(head);
    return 0;
}
