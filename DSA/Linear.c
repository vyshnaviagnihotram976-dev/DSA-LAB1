//Aim: To find linear search in c
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
#include<stdbool.h>
int main() 
{ 
  int i,n,key;
  printf("enter the size of the array\n");
  scanf("%d", &n);
    int arr[n];
  printf("Enter the element in array\n");
  for (i=0; i<n; i++)
    {
      scanf("%d", & key)
        }
  printf("enter the value to be searched\n");
  bool flag;
  flag = false;
  for (i=0; i<n; i++)
    {
      if (arr[i] = key)
      {
        printf("elements found at position %d, %d\n",arr[i]);
        flag = true;
        break;
      }
    }
  if(flag)
  {
    printf("enter element not found");
  }
  return 0;
}
