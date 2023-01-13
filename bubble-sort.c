#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n) {
    for(int i = 0; i < n-1; ++i) 
        for(int j = 1; j < n-i; ++j) 
            if(arr[j-1] > arr[j]) 
                swap(arr+j, arr+j-1);
}

int main() {
    printf("Enter the size of the array: ");
    int n; scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; ++i)
        scanf("%d", arr+i);

    printf("Sorted array:\n");
    bubble_sort(arr, n);
    for(int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
