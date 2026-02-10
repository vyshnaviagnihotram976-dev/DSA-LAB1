// Aim:TO find Binary search in C
/*Algorithm:
1. start
2. input the sorted array A of size n
3. input the element to search, say key
set start = 0, end = n-1
 repeat while low<= high, do 
 find mid = (low + high)/2
 if A[mid] == key
 print "found at position mid"
 stop
 4. if A [mid]<key, set start = mid + 1
 else, set end = mid - 1
 if low > high , print "not found" */


#include <stdio.h>
int n, key;
printf("enter the size of array:");
scanf("%d", &n);
int arr[n];
printf("enter the elements of array in sorted order:\n");
for (int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
}  
printf("enter the value to be searched:");
scanf("%d", &key);
int start=0, end=n-1,mid;
while (start <= end)
{
    mid = (start + end)/2;
    if (arr[mid] == key) {
        printf("element found at position %d\n", mid);
        return 0;
    }
    else if(arr[mid] < key)
    {
        start = mid + 1;
    }
    else {
        end = mid - 1;
    }
    printf("required element not found\n");
} 
