//Aim: to implement stack operations in c

/*
Algorithm:
Step 1: Start
Step 2: Input the array elements and the target element to search
Step 3: Set a flag variable found = 0
Step 4: Loop through the array from i = 0 to n - 1
  • If arr[i] == target, set found = 1 and break the loop
Step 5: If found == 1, print “Element found at position i”
  Else, print “Element not found”
Step 6: Stop

*/

#include <stdio.h>
#include <stdlib.h>

int top = -1;
int size;
char *STACK; // Dynamic Array

void push(char item)
{
    if (top == (size - 1))
    {
        printf("Stack is already full, no additional push allowed - Overflow");
    }
    else
    {
        top = top + 1;
        STACK[top] = item;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is underflow");
    }
    else
    {
        char temp = STACK[top];
        top = top - 1;
        printf("Element popped %c", temp);
    }
}

void DisplayStack()
{
    if (top == -1)
    {
        printf("Stack is underflow");
        return;
    }
    printf("[Top] \n");
    for (int i = top; i >= 0; i--)
    {
        printf("%c \n", STACK[i]);
    }
}

int main()
{
    int choice;
    char data;

    printf("Enter size of stack: ");
    scanf("%d", &size);
    STACK = (char *)malloc(size * sizeof(char));

    while (1)
    {
        printf("\n--- Stack Menu ---\n");
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
            scanf(" %c", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            DisplayStack();
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
