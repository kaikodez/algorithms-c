/*
 *
 * Use Selection Sort to sort an
 * integer array. O(n^2).
 *
 */

#include <stdio.h>

void selectionSort(int*, int);
void swap(int*, int*);
void printArray(char*, int*, int);

int main() {
    int array[] = {9, 8, 7, 6, 5,
                   4, 3, 2, 1, 0};

    printArray("Before: ", array, 10);

    selectionSort(array, 10);

    printArray("After:  ", array, 10);

    return 0;
}

/// Sorts an array in-place using Selection
/// Sort. O(n^2).
/// \param array
/// \param length
void selectionSort(int* array, int length) {
    int min_index, min_value;

    for (int i = 0; i < length - 1; i++) {
        // Assume current value is the
        // minimum value;
        min_index = i;
        min_value = array[min_index];

        for (int j = i+1; j < length; j++) {
            // Compare this value to minimum
            // value. If it's less than the
            // minimum value, make it the new
            // minimum value;
            if (array[j] < min_value) {
                min_index = j;
                min_value = array[j];
            }
        }

        // Swap the values
        if (i != min_index)
            swap(&array[i], &array[min_index]);
    }
}

/// Swaps two integers.
/// \param x
/// \param y
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
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
