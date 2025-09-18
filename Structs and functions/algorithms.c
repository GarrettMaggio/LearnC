#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *array, int size) {

    // if statement says element at j position is smaller than element at min position
    // the if statement will execute for every value that is smaller than
    // min. Essentially it will move the smallest value to the minimum index on each iteration.

    for (int i = 0; i < size; i++) {
        int min = i; // first iteration i = 0 first element in array
        for (int j = i+1; j < size; j++) { // loops through the array until it finds a value that is smaller
            if (array[j] < array[min]) { // change < to > if you want to sort in descending order.
                int temp = array[min];
                array[min] = array[j];
                array[j] = temp;
            }
        }
        printf ("%d ", array[min]);
    }
    printf("\n");
}

void insertionSort(int *array, int size) {

    // i is assigned the second element in the array. Then the second value is assignment to a temp variable.
    // then x is a variable pointing to the first element in the array.

    for (int i = 1; i < size; i++) {
        int temp = array[i];
        int x = i - 1;

        // when the while loop executes the first value is assigned to the element at the next index. This patten continues
        // for every element until and element is found with a larger value than temp.
        while (array[x] > temp && x >= 0) { // reverse the first > to < for descending order.
            array[x + 1] = array[x];
            x = x - 1;
        }
        array[x + 1] = temp;
    }

    for (int i = 0; i < size; i++) {
        printf ("%d ", array[i]);
    }
    printf("\n");
}

void binarySearch( int *array, int size, int value_to_find) {

    printf("%s\n", "Enter a number from 1-10 to search for.");
    scanf("%d", &value_to_find);

    int low = 0;
    int high = size - 1;
    int counter = 0;


    while (low <= high && counter != 1) {
        int middle = (low + high)/2;

        if (array[middle] > value_to_find) { // search the bottom of the array
            high = middle - 1;
        }
        if (array[middle] < value_to_find) { // search the top of the array
            low = middle + 1;
        }
        if (array[middle] == value_to_find) {
            printf("%s", "Value found:\t");
	        printf("%d\n", array[middle]);
            counter++;
	    }
    }
    if (low > high) {
        printf("%s\n", "Value not found:\t");
    }

}


int algorithms() {

    int unsorted_array[] = {4, 2, 6, 9, 1, 3, 8, 7, 5, 10};
    char value_to_find;
    value_to_find = 0;

    int size = sizeof(unsorted_array) / sizeof(unsorted_array[0]); // this is the same as saying sizeof(array) / 4 because int's occupy 4 bytes of memory
                                                                    // so 4 bytes per element.

    printf("%s\n", "Unsorted array");
    for (int i = 0; i < sizeof(unsorted_array) / sizeof(unsorted_array[0]); i++) {
        printf("%d ", unsorted_array[i]);
    }
    printf("\n");

    // selection sort works by comparing two elements that are next to each other if the next element in the
    // array is larger than the first element then their positions in the array are swapped.
    // for a more detailed explanation look at the selection sort function.

    // comment out one of the sorting algorithms to see the other working
    printf("%s\n", "Selection Sort");
   selectionSort(unsorted_array, size);

    printf("%s\n", "Insertion Sort");
    insertionSort(unsorted_array, size);

    printf("%s\n", "Binary Search");
    binarySearch(unsorted_array, size, value_to_find);



    return 0;

}
