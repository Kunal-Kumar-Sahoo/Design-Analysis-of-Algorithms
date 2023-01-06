#include <stdio.h>

int binary_search(int array[], int size, int key, int start, int end) {
    if(start > end)
        return -1;
    int mid = (start + end) / 2;
    if(array[mid] == key)
        return mid;
    else if(array[mid] > key)
        binary_search(array, size, key, start, mid - 1);
    else
        binary_search(array, size, key, mid + 1, end);
}

int main() {
    printf("Enter size of the array: ");
    int size;
    scanf("%d", &size);

    printf("Enter elements of the sorted array:\n");
    int arr[size];
    for(int i = 0; i < size; ++i)
        scanf("%d", arr+i);

    printf("Enter element to be searched: ");
    int key;
    scanf("%d", &key);

    int index = binary_search(arr, size, key, 0, size - 1);

    if(index >= 0)
        printf("%d found at index %d\n", key, index);
    else
        printf("%d not found in array\n", key);

    return 0;
}
