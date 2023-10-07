// wshakespear_Lab 3_8.c
// Written by ~Weston Shakespear~
// 10/6/2023

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structures
struct Node
{
    int value;
    struct Node* next;
};

// Prototypes
struct Node* create_node(int value);
void insert_node_begin(struct Node** head, struct Node* new);
void insert_node_end(struct Node** head, struct Node* new);
void remove_node_first(struct Node** head, struct Node* remove);
void remove_node_all(struct Node** head, struct Node* remove);
void remove_begin(struct Node** head);
void remove_end(struct Node** head);
void printll(struct Node** head);
void freell(struct Node** head);

void main()
{
    // Output assignment requirements
    printf("\nLinked List Operations: Implement basic operations on a");
    printf(" singly linked list using functions and pointers, including");
    printf(" insertion, deletion, and traversal.\n\n");

    // Declare variables
    struct Node* node_a = NULL;
    struct Node* node_b = NULL;
    struct Node* node_c = NULL;
    struct Node* node_d = NULL;
    struct Node* node_e = NULL;
    struct Node* node_f = NULL;
    struct Node* head = NULL;
    struct Node* head2 = NULL;


    // Test Node creation
        printf("Testing node creation: \n");
        node_a = create_node(0);
        node_b = create_node(1);
        node_c = create_node(2);
        node_d = create_node(3);


        if (node_a == NULL)
        {
            printf("    Error creating node_a");
        }
        else
        {
            printf("    Created node_a which has a value of %d\n", node_a->value);
        }
        if (node_b == NULL)
        {
            printf("    Error creating node_a");
        }
        else
        {
            printf("    Created node_b which has a value of %d\n", node_b->value);
        }
        if (node_c == NULL)
        {
            printf("    Error creating node_a");
        }
        else
        {
            printf("    Created node_c which has a value of %d\n", node_c->value);
        }
        if (node_d == NULL)
        {
            printf("    Error creating node_d");
        }
        else
        {
            printf("    Created node_d which has a value of %d\n", node_d->value);
        }



    // Test insertion at beginning
        printf("Test insertion at beginning: \n");

        insert_node_begin(&head, node_b);
        // Output the linkedlist
        printll(&head);

        insert_node_begin(&head, node_a);
        // Output the linkedlist
        printll(&head);

        // Test insertion at end
        printf("Test insertion at end: \n");

        insert_node_end(&head, node_c);
        // Output the linkedlist
        printll(&head);

        insert_node_end(&head, node_d);
        // Output the linkedlist
        printll(&head);

    // Test removing the first node encountered
        printf("Test removing the first node that matches: \n");
        remove_node_first(&head, node_c);
        // Output the linkedlist
        printll(&head);

        remove_node_first(&head, node_d);
        // Output the linkedlist
        printll(&head);

        remove_node_first(&head, node_a);
        // Output the linkedlist
        printll(&head);

        remove_node_first(&head, node_b);
        // Output the linkedlist
        printll(&head);


    // Test removing the all nodes that match

        printf("\nNew List: \n");
        node_a = create_node(0);
        node_b = create_node(2);
        node_c = create_node(1);
        node_d = create_node(1);
        node_e = create_node(4);
        node_f = create_node(5);

        insert_node_begin(&head2, node_a);
        insert_node_end(&head2, node_b);
        insert_node_end(&head2, node_c);
        insert_node_end(&head2, node_d);
        insert_node_end(&head2, node_e);
        insert_node_end(&head2, node_f);

        printll(&head2);

        printf("Removing all entries with a value of 1\n");
        remove_node_all(&head2, node_b);

        // Output the linkedlist
        printll(&head2);
    
    
    
    // Test removing the first
        printf("Remove the first: \n");
        remove_begin(&head2);
        // Output the linkedlist
        printll(&head2);

    
    // Test removing the last
        printf("Remove the last: \n");
        remove_end(&head2);
        // Output the linkedlist
        printll(&head2);

    // Free the list
    freell(&head);
    freell(&head2);

    printf("\n");
}

// Function to create a node
struct Node* create_node(int value)
{
    // Manually allocate the memory for one node
    struct Node* created = ((struct Node*) malloc(sizeof(struct Node)));

    // Check to make sure the memory was successfully allocated
    if (created == NULL)
    {
        // Output an error and return if it wasn't
        printf("Error allocating memory\n");
        return NULL;
    }

    // Setup the value and next for the new node
    created->value = value;
    created->next = NULL;

    // Return the newly created node
    return created;
}

// Function to insert node at beginning
void insert_node_begin(struct Node** head, struct Node* new)
{
    // Attach the list to the next variable of the new node
    new->next = *head;

    // Set the head of the list to the new node
    *head = new;
}

// Function to insert node at the end of the list
void insert_node_end(struct Node** head, struct Node* new)
{
    // This is the current node in the loop
    struct Node* current = ((struct Node*) *head);

    // Loop through to the end of the list
    while (current != NULL)
    {
        // Break if we reached the end
        if (current->next == NULL)
        {
            break;
        }
        current = ((struct Node*) current->next);
    }
    // Attached the new node at the end
    current->next = new;
}

// Function to remove the node that's first found with a matching value
void remove_node_first(struct Node** head, struct Node* remove)
{
    // This is the value we are searching for
    int value = remove->value;
    // This will be the last node accessed in the loop
    struct Node* last = NULL;
    // This is the current node in the loop
    struct Node* current = ((struct Node*) *head);
    // Have we found a node that matches?
    bool found = false;

    // Loop through to the end of the list
    while (current != NULL)
    {
        if (current->value == value)
        {
            found = true;
            break;
        }
        last = current;
        current = ((struct Node*) current->next);
    }

    if (found == true)
    {
        // This is the first node in the list
        if (last == NULL)
        {
            *head = current->next;
            free(current);

            return;
        }

        // This is the last node in the list
        if (current->next == NULL)
        {
            free(last->next);
            last->next = NULL;
        }

        // The last node's next is now the current nodes next
        else
        {
            last->next = current->next;
            free(current);
        }
    }
}

void remove_node_all(struct Node** head, struct Node* remove)
{
    int value = remove->value;

    // This will be the last node accessed in the loop
    struct Node* last = NULL;
    // This is the current node in the loop
    struct Node* current = ((struct Node*) *head);

    // Loop through to the end of the list
    while (current != NULL)
    {
        if (current->value == value)
        {
            // This is the first
            if (last == NULL)
            {
                // Remove the current node
                last = current;
                current = last->next;
                free(last);
                last = NULL;
            }
            else
            {
                struct Node* buf = current->next;
                free(current);

                last->next = buf;
                current = buf;
            }
        }
        else
        {
            last = current;
            current = ((struct Node*) current->next);
        }
    }
}

// Function to remove the beginning of the list
void remove_begin(struct Node** head)
{
    // This is the current node
    struct Node* current = ((struct Node*) *head);

    // This is the next node
    struct Node* next = current->next;

    // Make the head of the list the next node
    *head = next;
}

// Function to remove the end of the list
void remove_end(struct Node** head)
{
    // This will be the last node accessed in the loop
    struct Node* last = NULL;
    // This is the current node in the loop
    struct Node* current = ((struct Node*) *head);

    // Loop through to the end of the list
    while (current != NULL)
    {
        // Break if we reached the end
        if (current->next == NULL)
        {
            break;
        }
        // Move the current node to the last node
        last = current;
        // Make the current node the next one
        current = ((struct Node*) current->next);
    }
    // Make the second to last node the end
    last->next = NULL;
}

// Function to print out the linked list
void printll(struct Node** head)
{
    // This is the current node in the loop
    struct Node* current = ((struct Node*) *head);

    // Loop through to the end of the list
    while (current != NULL)
    {
        // Output the current value
        printf("%4d -> ", current->value);

        // Move to the next value
        current = ((struct Node*) current->next);
    }
    printf("\n");
}

// Function to free all manually allocated memory
void freell(struct Node** head)
{
    // This will be the last node accessed in the loop
    struct Node* last = NULL;
    // This is the current node in the loop
    struct Node* current = ((struct Node*) *head);

    // Loop through to the end of the list
    while (current != NULL)
    {
        // Move the current node to the last node
        last = current;

        // Make the current node the next one
        current = ((struct Node*) current->next);

        // Free the last node
        free(last);
    }
}


