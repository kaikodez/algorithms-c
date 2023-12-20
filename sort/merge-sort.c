/*
 *
 * Use Merge Sort to sort an integer array.
 * O(nlogn).
 *
 * Notes: Merge Sort is easier to comprehend
 * than code. It's a divide and conquer algorithm.
 * It constantly divides the array in half until
 * there is only 1 item in each sub array. It then
 * merges the sub arrays in sorted order. It runs
 * in O(nlogn). During the merge we need a couple
 * of temp arrays for the two sub arrays being
 * merged.
 *
 */

#include <stdio.h>

void mergeSort(int*, int, int);
void merge(int*, int, int, int);

void printArray(char*, int*, int);

int main() {
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    printArray("Before: ", array, 10);

    mergeSort(array, 0, 9);

    printArray("After:  ", array, 10);

    return 0;
}

/// Sorts an array using Merge Sort. O(nlogn).
/// We're continuously dividing the array in
/// half until we get to individual elements.
/// We then merge the elements in sorted order.
/// \param array
/// \param left_index
/// \param right_index
void mergeSort(int* array, int left_index, int right_index) {
    if (left_index < right_index) {
        // Find the midpoint index.
        // We'll split on this index.
        int mid_index = (left_index + right_index) / 2;

        // Sort left side first, then right.
        mergeSort(array, left_index, mid_index);
        mergeSort(array, mid_index + 1, right_index);

        // Merge the left and right sub arrays.
        merge(array, left_index, mid_index, right_index);

        // Print the contents of the array
        // after each merge for better
        // visualization.
        printArray("        ", array, 10);
    }
}

/// Merge the sub arrays in sorted order.
/// Sub arrays will be in sorted order.
/// We just need to merge them, choosing
/// the next smaller element from either
/// sub array. The resulting merge will be
/// in sorted order, too.
/// \param array
/// \param left
/// \param mid
/// \param right
void merge(int* array, int left_index, int mid_index, int right_index) {
    // Create left and right temporary sub arrays
    // to hold values being merged into array.
    // On large arrays, this temporary space may
    // not be inconsequential. There is also extra
    // time being spent moving values to these
    // temporary arrays.
    int length_left = mid_index - left_index + 1;
    int length_right = right_index - mid_index;

    int left_array[length_left];
    int right_array[length_right];

    // Copy the contents into the sub arrays.
    for(int i=0; i < length_left; i++) {
        left_array[i] = array[left_index + i];
    }
    for(int i=0; i < length_right; i++) {
        right_array[i] = array[mid_index+1+i];
    }

    // We need 3 indexes for the left and right
    // temporary sub arrays as well as an index
    // for array.
    int i = 0, j = 0, k = left_index;

    // Choose the lowest value from either the
    // left or right sub array and add it to
    // array. Again, the sub arrays are in
    // sorted order so the results of the merge
    // will be in sorted order.
    while (i < length_left && j < length_right) {
        if (left_array[i] <= right_array[j]) {
            array[k] = left_array[i];
            i++;
        }
        else {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    // If the left sub array isn't empty, copy
    // the remaining elements into array. This
    // happens when the right sub array has
    // fewer elements than the left.
    while (i < length_left) {
        array[k] = left_array[i];
        i++;
        k++;
    }

    // If the right sub array isn't empty, copy
    // the remaining elements into array. This
    // happens when the left sub array has
    // fewer elements than the right.
    while (j < length_right) {
        array[k] = right_array[j];
        j++;
        k++;
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
