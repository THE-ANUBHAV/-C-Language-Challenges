#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

// Lexicographically non-increasing order
int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}
// Count distinct characters in a string
int characters_count(const char *s) {
    int count[128] = {0};  // ASCII table size for lowercase characters
    int distinct = 0;
    
    while (*s) {
        if (!count[(unsigned char)*s]) {
            count[(unsigned char)*s] = 1;
            distinct++;
        }
        s++;
    }
    return distinct;
}

// Sort by number of distinct characters
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int distinct_a = characters_count(a);
    int distinct_b = characters_count(b);
    
    if (distinct_a != distinct_b) {
        return distinct_a - distinct_b;
    }
    // If distinct counts are equal, use lexicographic sort
    return lexicographic_sort(a, b);
}

// Sort by string length
int sort_by_length(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    
    if (len_a != len_b) {
        return len_a - len_b;
    }
    // If lengths are equal, use lexicographic sort
    return lexicographic_sort(a, b);
}

// Custom string sort function
void string_sort(const char **arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
	int i;
    for (i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (cmp_func(arr[j], arr[j + 1]) > 0) {
                const char *temp = arr[j];  // const type since arr is const
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
