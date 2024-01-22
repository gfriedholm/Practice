#include <stdio.h>
#include <stdlib.h>
#include <string.h>

     // Returns < 0 if a < b    0 if a == b   > 0 if a > b
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);  

} 

// rev by negating strcmps result
int lexicographic_sort_reverse(const char* a, const char* b) {
    return -strcmp(a ,b);    

}

// Counts the number of dist char within the strings 
int total_distinct_char(const char *str) {
    int total = 0;
    int char_instr[26] = {0};
    
    while (*str) {
        if (!char_instr[*str - 'a']) {
            char_instr[*str - 'a'] = 1;
            total++;
        }
        str++;
    }
    
    return total;
}

// Sorts based on dist char within the strings
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int total_a = total_distinct_char(a);
    int total_b = total_distinct_char(b);
    if (total_a == total_b) {
        return strcmp(a, b); // count are ==, sort lex
    }
    return total_a - total_b;  // counts != sort 

}

// Sorts strings by their length in case of eq len, strcmp is used for sorting
int sort_by_length(const char* a, const char* b) {
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);
    if (len_a == len_b) {
        return strcmp(a, b);
    }
    return len_a - len_b;
}

/*  
Function Name: string_sort 
Return type: void  (purpose is to preform operation insted of cal a val)
First Parameter: const char **arr  pointer to a pointer to a char i.e array of strings .. const (do not mod strings)
Second Parameter: const int cnt  represents the count (#) of strings in the array arr .. const means do not mod cnt
Third Parameter: int (*cmp_func)(const char* a, const char* b) parameter is a pointer to the function cmp_func  takes 2 const char* args i.e strings
uses a bubbles sort 
*/
void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int change;
    for (int i = 0; i < len - 1; i++) {
        change = 0;
        for (int j = 0; j < len - i - 1; j++) {
            if (cmp_func(arr[j], arr[j + 1]) > 0){
                // Change arr[j] and arr[j + 1]
                char *tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j +1] = tmp;
                change = 1;
            }
        }
        
        if (!change) {
            break;
        }
    }
}

/*
uses string_sort with diffrent comparison functions
starts by reading the number of strings 'n' and allocates memory for the strings
they are then sorted in various orders and printed out

*/
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