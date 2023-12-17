/*
 *
 * Use Binary Search to find a value
 * in a sorted array. O(log n).
 *
 */

#include <stdio.h>

int find_index(const int*, int, int, int);

int main() {
    int array[] = {0, 1, 2, 3, 4,
                   5, 6, 7, 8, 9};

    for(int i = 0; i < 11; i++) {
        printf("Index of %d: %d.\n", i,
               find_index(array, 0, 9, i));
    }

    return 0;
}

/// Searches for value in the sorted array and returns its
/// index. If index is not in the array, it returns -1. The
/// function uses a tail recursive binary search algorithm.
/// \param sorted_array
/// \param low_index
/// \param high_index
/// \param value
/// \return the index of value in the array, otherwise -1
int find_index(const int* sorted_array, int low_index, int high_index, int value) {
    // Base Test - Not Found
    if (low_index > high_index) return -1;

    // Calculate midpoint
    int midpoint_index = (high_index + low_index) / 2;

    // Base Test - Found
    if (sorted_array[midpoint_index] == value) {
        return midpoint_index;
    }

    // Adjust search range
    if (sorted_array[midpoint_index] < value)
        low_index = midpoint_index + 1;
    else
        high_index = midpoint_index - 1;

    return find_index(sorted_array, low_index, high_index, value);
}
