Aim:TO implement queue operations
/*Algorithm:
Enqueue (Insert)

Check if queue is full → if full, stop.

If queue is empty, set front = 0.

Increase rear by 1.

Insert the new item at queue[rear].

2. Dequeue (Delete)

Check if queue is empty → if empty, stop.

Take the item from queue[front].

Increase front by 1.

If front > rear → reset both to -1 (queue becomes empty).

3. Peek (Front Element)

If queue empty → stop.

Return element at queue[front].

4. Display

If queue empty → stop.

Starting from front to rear, print each element.
*/

#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, size;
int *QUEUE; // Dynamic array for queue

void enqueue(int item)
{
    if (rear == size - 1)
    {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }

    if (front == -1) // First element insertion
        front = 0;

    rear++;
    QUEUE[rear] = item;
    printf("%d inserted into queue.\n", item);
}

void dequeue()
{

    if (front == -1)
    {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }

    int temp = QUEUE[front];
    front++;
    printf("Deleted element: %d\n", temp);

    // Reset queue when empty
    if (front > rear)
        front = rear = -1;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", QUEUE[i]);
    }
    printf("\n");
}

int main()
{
    int choice, data;

    printf("Enter size of Queue: ");
    scanf("%d", &size);

    QUEUE = (int *)malloc(size * sizeof(int));
    if (QUEUE == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }

    while (1)
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting...\n");
            free(QUEUE);
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
