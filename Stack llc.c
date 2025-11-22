// AIM: To implement a Stack data structure using a Linked List
/*Algorithm:
Structure of a Node:
Structure Node
    data
    next → pointer to next node
End Structure
TOP ← NULL
PUSH(item):
    Create a new node NEW
    NEW.data ← item
    NEW.next ← TOP
    TOP ← NEW
End PUSH
POP():
    If TOP = NULL
        Print "Stack Underflow"
        Return
    End If
    
    TEMP ← TOP
    item ← TEMP.data
    TOP ← TOP.next
    Free TEMP
    Return item
End POP

#include <stdio.h>
#include <stdlib.h>

// Create node for linked list
struct Node
{
    int data;
    struct Node *next; // To hold the address of next node
};

// To create a node and it returns address of newly created node
struct Node *CreateNode(int data)
{
    // STACK = (char *)malloc(MAX * sizeof(char));
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node **top, int data)
{
    struct Node *newElement = CreateNode(data);
    newElement->next = *top;
    *top = newElement;
    printf("Node with data %d pushed successfully  .\n", data);
}

void pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack is empty/underflow, pop operation can't be performed");
        return;
    }

    struct Node *temp = *top;
    *top = temp->next;
    printf("Element %d popped from stack.\n", temp->data);
    free(temp);
    return;
}

void DisplayStack(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    struct Node *temp;
    temp = top;
    printf("\nElements In Stack: [Top] ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

// Main function
int main()
{
    struct Node *top = NULL;
    int choice, data, pos;

    while (1)
    {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            push(&top, data);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            DisplayStack(top);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
