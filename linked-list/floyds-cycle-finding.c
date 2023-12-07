/*
 *
 * Use Floyd's Cycle Finding Algorithm to
 * detect a cycle in a linked list.
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

node* findCycle(node*);

// Helper Function(s)
node* createList(int nodes, int cycleValue);

int main() {
    node* list = createList(10, 6);

    node* result = findCycle(list);
    if (result == NULL)
        printf("There is no cycle.\n");
    else
        printf("There is a cycle at %d.\n", result->value);
}

/// Finds a cycle in linked list.
/// \param head
/// \return node where cycle occurs, otherwise NULL
node* findCycle(node* head) {
    if (head == NULL || head->next == NULL)
        return NULL;

    node* ptr_slow = head;
    node* ptr_fast = head;

    // ptr_fast travels through list twice
    // as fast as ptr_slow. If they become
    // equal, there is a cycle in the list.
    while (ptr_slow != NULL & ptr_fast != NULL
        && ptr_fast->next != NULL)
    {
        ptr_slow = ptr_slow->next;
        ptr_fast = ptr_fast->next->next;
        if (ptr_slow == ptr_fast)
            break;
    }

    // There is no cycle.
    if (ptr_slow != ptr_fast)
        return NULL;

    // There is a cycle. Find the node
    // where it occurs in the list.
    ptr_slow = head;
    while (ptr_slow != ptr_fast) {
        ptr_slow = ptr_slow->next;
        ptr_fast = ptr_fast->next;
    }

    return ptr_slow;
}

/*
 *
 * Helper Function(s)
 *
 */

/// Creates a linked list. If you want a cycle,
/// pass an integer between 1 and nodes as
/// cycleValue. Otherwise, pass 0.
/// \param nodes number of nodes to create in list.
/// \param cycleValue an integer between 0 and nodes.
/// \return the head of the new linked list
node* createList(int nodes, int cycleValue) {
    if (nodes < 1)
        return NULL;

    node* head = calloc(1, sizeof(node));
    head->value = 1;

    node* current_node = head;
    node* cycle_node = cycleValue == 1 ? head : NULL;
    for(int i = 2; i < nodes + 1; i++) {
        current_node->next = calloc(1, sizeof(node));
        current_node->next->value = i;

        if (cycleValue == i)
            cycle_node = current_node->next;

        current_node = current_node->next;
    }

    current_node->next = NULL;

    // If requested, add a cycle.
    if (cycle_node != NULL && cycleValue == cycle_node->value)
        current_node->next = cycle_node;

    return head;
}
