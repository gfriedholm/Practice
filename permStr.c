#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// swaps 2 str takes pointers char** as args
void swap(char **a, char **b) {
    char *tmp = *a;  // hold the str while swap
    *a = *b;
    *b = tmp;
}


//reverses a part of the array from start to end
void reverse(char **s, int start, int end) {
    while (start < end) {
        swap(&s[start], &s[end]);
        start++;
        end--;
    }
            
}

int next_permutation(int n, char **s) {
    int i = n - 2;
    
    while (i >= 0 && strcmp(s[i], s[i + 1]) >= 0) {  // look for first pair 
        i--;
    } 
    
    if (i < 0) {
        return 0;
    }
    
    int j = n - 1;
    while (strcmp(s[i], s[j]) >= 0) {
        j--;
    }
    
    swap(&s[i], &s[j]); // find smallest ele > arr  and swaps then creates next perm
    reverse(s, i +1, n - 1);
    return 1;
}




int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}