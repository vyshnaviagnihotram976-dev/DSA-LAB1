 #include <stdio.h> 
 void bestFit(int items[], int n, int capacity) 
 { 
     printf("\nBest Fit Algorithm\n"); 
  
     int bin[n]; 
     int binCount = 0; 
  
     // Initialize bins with full capacity 
     for (int i = 0; i < n; i++) 
         bin[i] = capacity; 
  
     // Process each item 
     for (int i = 0; i < n; i++) 
       { 
         int bestIndex = -1; 
         int minSpace = capacity + 1; 
                  // Find bin with least remaining space after placement 
         for (int j = 0; j < binCount; j++) 
        { 
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace) 
            { 
                 bestIndex = j; 
                 minSpace = bin[j] - items[i]; 
             } 
         } 
  
         // Identified the best bin for the current item 
         if (bestIndex != -1) 
         { 
             bin[bestIndex] -= items[i]; 
             printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], bestIndex + 1);
} 
         else // New bin needed 
         { 
             bin[binCount++] -= items[i]; 
             printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], binCount); 
        } 
     } 
     printf("Total bins used = %d\n", binCount); 
 } 
  
 int main() 
 { 
     int n, capacity; 
      printf("Enter number of items: "); 
     scanf("%d", &n); 
  
     /* Define an array to hold item sizes 
     1. Only after we know the number of items or 
    2. Define a large array and waste memory or 
     3. Use dynamic allocation 
     if this is not taken care then random values will be in the array */ 
     int items[n]; 
  
     printf("Enter bin capacity: "); 
     scanf("%d", &capacity); // FIXED: %d instead of %f 
  
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
  
     bestFit(items, n, capacity); 
  
     return 0; 
 } 
