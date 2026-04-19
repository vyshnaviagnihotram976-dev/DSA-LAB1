 #include <stdio.h>
void firstFit(int items[], int n, int capacity) 
 { 
     int bin[n];       // Available capacity of bins 
     int binCount = 0; // Number of bins used / active bins 
  
     // Initialize all bins with full capacity 
     for (int i = 0; i < n; i++) 
         bin[i] = capacity; 
  
     // Process each item 
     for (int i = 0; i < n; i++) 
     { 
         int placed = 0; // flag to check if item is placed 
  
         // Check existing bins 
         for (int j = 0; j < binCount; j++) 
         { 
             // items fits in the current bin 
             if (bin[j] >= items[i]) 
             { 
                 bin[j] -= items[i]; // Reduce bin capacity by item size 
                 printf("Item %d placed in Bin %d\n", items[i], j + 1); 
                 placed = 1; 
                 break; // First Fit: stop at first match 
             } 
         } 
         // Create new bin if item is not fitted in any existing bin 
         if (!placed) 
         { 
             bin[binCount] -= items[i]; 
             printf("Item %d placed in Bin %d\n", items[i], binCount + 1); 
             binCount++; 
         } 
     } 
     printf("Total bins used = %d\n", binCount);
 } 
  
 int main() 
 { 
     int n, capacity; 
     printf("Enter number of items: "); 
     scanf("%d", &n); 
  
     printf("Enter bin capacity: "); 
     scanf("%d", &capacity); 
     int items[n]; 
  
     printf("Enter item sizes:\n"); 
     for (int i = 0; i < n; i++) 
     { 
         int itemSize; 
         printf("Item %d: ", i + 1); 
         scanf("%d", &itemSize); 
  
         if (itemSize <= capacity) 
         { 
             items[i] = itemSize; 
         } 
         else 
         { 
             printf("Item size exceeds bin capacity. Please enter a valid size.\n"); 
             i--; 
         } 
     } 
  
     firstFit(items, n, capacity); 
     return 0; 
 }
