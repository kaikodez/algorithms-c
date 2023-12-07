/*
 *
 * Reverse a linked list iteratively.
 *
 * Note: First time writing this function
 * iteratively from scratch with no help.
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

node* reverseLinkedList(node*);

// Helper Function(s)
node* createList();
void printList(node*);
void deleteList(node*);

int main() {
    // Create and print a new linked list
    node* list = createList();
    printList(list);

    // Reverse and print the linked list
    list = reverseLinkedList(list);
    printList(list);

    // Free memory
    deleteList(list);
}

/// Reverses a linked list.
/// \param a_node
/// \return the new head node of the list
node* reverseLinkedList(node* a_node) {
    if (a_node == NULL || a_node->next == NULL)
        return a_node;

    // Get the next node
    node* next_node = a_node->next;

    // The first node is now at the
    // end, so point it to NULL.
    a_node->next = NULL;

    node* temp = NULL;
    while(next_node != NULL) {
        // Save this because we need
        // it to move forward and are
        // about to lose it by
        // pointing backwards.
        temp = next_node->next;

        // Point backwards now.
        next_node->next = a_node;

        // Move Forward
        a_node = next_node;
        next_node = temp;
    }

    return a_node;
}

/*
 *
 * Helper Function(s)
 *
 */

/// Creates a linked list with values 1 through 10.
/// \return the head of the new linked list
node* createList() {
    node* first_node = calloc(1, sizeof(node));
    first_node->value = 1;

    node* current_node = first_node;
    for(int i = 2; i < 11; i++) {
        current_node->next = calloc(1, sizeof(node));
        current_node->next->value = i;
        current_node = current_node->next;
    }
    current_node->next = NULL;

    return first_node;
}

/// Prints a linked list.
/// \param a_node
void printList(node* a_node) {
    printf("List: ");
    while (a_node != NULL) {
        printf("%4d", a_node->value);
        a_node = a_node->next;
    }
    printf("\n");
}

/// Deletes and frees the list from memory.
/// \param a_node
void deleteList(node* a_node) {
    node* current_node = a_node;
    node* next_node = NULL;

    while(current_node != NULL) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    a_node = NULL;
}
