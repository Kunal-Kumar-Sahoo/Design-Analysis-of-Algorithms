#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int **arr, int n) {
    int *sorted = (int *)malloc(sizeof(int) * n);
    int i, j, k;
    for(i = 0, j = 0; i < n; ++i) {
        *(sorted + (j++)) = *(*arr + i);
        for(k = j-1; k > 0; --k) {
            if(*(sorted + k) < *(sorted + k - 1))
                swap(sorted+k, sorted+k-1);
        }
    }
    *arr = sorted;
}

int main() {
    printf("Enter the size of the array: ");
    int n; scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; ++i)
        scanf("%d", arr+i);

    printf("Sorted array:\n");
    insertion_sort(&arr, n);

    for(int i = 0; i < n; ++i)
        printf("%d ", *(arr+i));
    printf("\n");

    free(arr);

    return 0;
}
