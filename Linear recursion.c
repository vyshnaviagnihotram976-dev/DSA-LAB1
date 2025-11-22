//Aim: To find linear search recursion in c.
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
#include <stdbool.h>

int LinearSearch(int dataSet[], int size, int elementToFind, int index)
{
    if (index >= size)
    {
        return -1;
    }
    if (dataSet[index] == elementToFind)
    {
        return index;
    }
    return LinearSearch(dataSet, size, elementToFind, index + 1);
}
int main()
{
    int size, elementToFind, i;
    printf("Enter the size of Data Set for Linear Search:");
    scanf("%d", &size);

    int searchSpace[size];
    for (i = 0; i < size; i++)
    {
        printf("Enter the %d out of %d element in data set: ", i + 1, size);
        scanf("%d", &searchSpace[i]);
    }

    printf("Given Dataset for Linear Search is: ");
    for (i = 0; i < size; i++)
    {
        printf("%d - ", searchSpace[i]);
    }

    printf("\nEnter the element to find in the dataset: ");
    scanf("%d", &elementToFind);

    int foundAt = LinearSearch(searchSpace, size, elementToFind, i = 0);

    if (foundAt >= 0)
        printf("Required element %d is found in the dataset at position %d or index %d", elementToFind, foundAt + 1, foundAt);
    else
        printf("Required element %d is NOT found in the dataset!!!", elementToFind);
}
