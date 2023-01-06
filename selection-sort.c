#include <stdio.h>

int find_index_of_maximum(int array[], int size) {
    int index_of_max = 0;
    for(int i = 1; i < size; ++i)
        if(array[index_of_max] < array[i])
            index_of_max = i;
    return index_of_max;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int array[], int size) {
    for(int i = 0; i < size; ++i) {
        int idx_of_max = find_index_of_maximum(array, size-i);
        swap(array+size-i-1, array+idx_of_max);
    }
}

int main() {
    printf("Enter size of the array: ");
    int size;
    scanf("%d", &size);

    printf("Enter elements of the array: ");
    int arr[size];
    for(int i = 0; i < size; ++i)
        scanf("%d", arr+i);

    sort(arr, size);

    printf("Sorted array:\n");
    for(int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
