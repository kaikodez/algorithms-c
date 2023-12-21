/*
 *
 * Use Insertion Sort to sort an
 * integer array. Worst case is O(n^2).
 * However, many items in arrays are
 * partially sorted, so this could run
 * as quickly as O(n) in best case when
 * array is already sorted. This is a
 * better choice over Selection Sort,
 * which will always run in O(n^2).
 *
 */

#include <stdio.h>

void insertionSort(int*, int);

void printArray(char*, int*, int);

int main() {
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    printArray("Before: ", array, 10);

    insertionSort(array, 10);

    printArray("After:  ", array, 10);

    return 0;
}

/// Sort items in an array using Insertion Sort.
/// Worst case this runs in O(n^2), but many
/// items in arrays are partially sorted, so
/// this could run as quickly as O(n) in best
/// case when array is already sorted.
/// \param array
/// \param length
void insertionSort(int* array, int length) {
    int value, j;

    // Don't bother sorting an array
    // with less than 2 items.
    if (length < 2)
        return;

    // Sort each item in the array
    // starting with the second item.
    for(int i = 1; i < length; i++) {
        // Save the value we're trying
        // to place in sorted order.
        value = array[i];

        // Scan and shift values in
        // previously sorted array
        // until we find the appropriate
        // spot for value.
        for (j = i - 1; j > -1; j--) {
            if (value < array[j]) {
                array[j+1] = array[j];
            } else
                break;
        }

        // Add the value to the
        // array in sorted order.
        array[j+1] = value;
    }
}

/// Prints the contents of an integer array.
/// \param label
/// \param array
/// \param length
void printArray(char* label, int* array, int length) {
    printf("%s ", label);

    for(int i = 0; i < length; i++) {
        printf("%2d ", array[i]);
    }

    printf("\n\n");
}
