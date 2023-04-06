#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int arr[], int size, int i) {
    int l = 2 * i + 1, r = 2 * i + 2, largest = i;
    
    if(l < size && arr[l] > arr[i])
        largest = l;
    
    if(r < size && arr[r] > arr[largest])
        largest = r;

    if(largest != i) {
        swap(arr+largest, arr+i);
        max_heapify(arr, size, largest);
    }
}

void build_max_heap(int arr[], int size) {
    for(int i = size / 2; i >= 0; --i)
        max_heapify(arr, size, i);
}

int extract_max(int arr[], int size) {
    if(size >= 1) {
        int max = arr[0];
        arr[0] = arr[size-1];
        size--;
        max_heapify(arr, size, 0);

        return max;
    }
}

void heap_sort(int arr[], int size) {
    build_max_heap(arr, size);
    for(int i = size-1; i > 0; --i) {
        swap(arr, arr+i);
        size--;
        max_heapify(arr, size, 0);
    }
}

int main() {
    printf("Enter the size of the array: ");
    int n; scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements in the array:\n", n);
    for(int i = 0; i < n; ++i)
        scanf("%d", arr+i);

    heap_sort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}