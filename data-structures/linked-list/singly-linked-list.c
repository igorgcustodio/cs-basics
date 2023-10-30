#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

/// @brief Append a value after the provided node
/// @param value int - the value to be added
/// @param previousNode node** - the previous node
void appendAfter(int value, node** previousNode) {
    node* newNode = (node*)malloc(sizeof(node));

    // newNode can be NULL if the memory allocation fails
    if (newNode == NULL) {
        printf("Failed to push the value");
        return;
    }

    // Assign the values
    newNode->value = value;
    newNode->next = NULL;

    // If the previousNode is NULL, we assign the new value to it
    // If not, we assign the newNode to previousNode->next 
    if (*previousNode == NULL) {
        printf("previousNode is empty, assigning new value to the previousNode\n");
        *previousNode = newNode;
    } else {
        if ((*previousNode)->next == NULL) {
            (*previousNode)->next = newNode;
        }
    }
}

/// @brief Append a value after the provided node
/// @param value int - the value to be added
/// @param previousNode node** - the head node
void appendLast(int value, node** head) {
    node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    appendAfter(value, &current);
}

/// @brief List all the nodes
/// @param head the head node
void list(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("Node -> %d\n", current->value);
        current = current->next;
    }
}

int main() {
    node* head = NULL;

    // Insert values
    appendAfter(1, &head);
    appendLast(2, &head);
    appendLast(3, &head);
    
    list(head);

    return 0;
}