#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, sum = 0;
    
    // Read the size of the array
    scanf("%d", &n);
    
    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    
    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Read the array elements and calculate the sum
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    // Output the sum of the array
    printf("%d\n", sum);
    
    // Free the dynamically allocated memory
    free(arr);
    
    return 0;
}
