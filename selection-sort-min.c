#include <stdio.h>

int find_min_idx(int arr[], int start, int end) {
    int min = start;
    for(int i = start+1; i <= end; ++i) 
        if(arr[i] < arr[min])
            min = i;
    return min;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int n) {
    int idx;
    for(int i = 0; i < n-1; ++i) {
        idx = find_min_idx(arr, i, n-1);
        if(i < idx)
            swap(arr+i, arr+idx);
    }
}

int main() {
    printf("Enter the size of the array: ");
    int n; scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; ++i)
        scanf("%d", arr+i);

    selection_sort(arr, n);
    printf("Sorted array:\n");
    for(int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
