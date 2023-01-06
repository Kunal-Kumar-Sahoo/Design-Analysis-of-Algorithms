#include <stdio.h>

int linear_search(int array[], int size, int key) {
    for(int index = 0; index < size; ++index)
        if(array[index] == key)
            return index;
    return -1;
}

int main() {
    printf("Enter size of the array: ");
    int size;
    scanf("%d", &size);

    printf("Enter elements of the array:\n");
    int arr[size];
    for(int i = 0; i < size; ++i)
        scanf("%d", arr+i);

    printf("Enter element to be searched: ");
    int key;
    scanf("%d", &key);

    int index = linear_search(arr, size, key);

    if(index >= 0)
        printf("%d found at index %d\n", key, index);
    else
        printf("%d not found in array\n", key);

    return 0;
}
